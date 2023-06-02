#include <stdio.h>
#include "lodepng.h"
#include <stdlib.h>
#include <pthread.h>

// The first stores pixels as height 
// Second stores image as width 
// Third stores red, green and blue values of the individual pixel 

int ***array;

// char image pointer as array
unsigned char *Image;

// Structure to slice thread 
struct pixels{
    int start_h;
    int end_h;
    int height;
    int width;
    int thread_ID;
    int kernel_size;
};

// Thread function to blur image
void *blur(void *ptr){

    int i, j, k, l, m; 
    struct pixels *arg = (struct pixels*)ptr;
	int start_h = arg->start_h, end_h = arg->end_h, kernelsize = arg->kernel_size;
    int thread_id = arg->thread_ID, height = arg->height, width = arg->width;
    
    // Loop through height and slice 
    for(i=start_h; i<=end_h; i++ ){
    	// Loop through width and slice 
        for(j=0; j<width; j++){
        	// Set average value of the rgb pixels to 0
            int avg_R=0, avg_G=0, avg_B=0, numOfPixels = 0;

            // Loop through kernel which is 2D matrix image
            for (l= -kernelsize; l<=kernelsize; l+=kernelsize){
                for (m = -kernelsize; m<=kernelsize; m+=kernelsize){
                    int xPixel = i+l;
                    int yPixel = j+m;

                    // Check image pixel at given index
                    if(xPixel >=0 && yPixel >= 0 && xPixel<height && yPixel<width){
                        avg_R += array[xPixel][yPixel][0];
                        avg_G += array[xPixel][yPixel][1];
                        avg_B += array[xPixel][yPixel][2];
                        numOfPixels++;
                    }          
                }
            }
            // Replace RGB value with new value 
            Image[4*width*i+4*j+0] = avg_R/numOfPixels;
            Image[4*width*i+4*j+1] = avg_G/numOfPixels;
            Image[4*width*i+4*j+2] = avg_B/numOfPixels;
        }
    }
    pthread_exit(0);

}

void main(){

	unsigned int error, width, height;
    int i, j, k;
    int noThreads, ksize;
    char filename[20];


    // User input of PNG image they want to blur
    printf("Enter the name of PNG image (including .png)): ");
    scanf("%s", &filename);

    // Decode PNG image to change the properties 
    error = lodepng_decode32_file(&Image, &width, &height, filename);

    // User input for number of threads to blur the image
    printf("\nNumber of threads: ");
    scanf("%d", &noThreads);


	// If thread is greater than the height of image program will automatically choose necesary number of threads
    if(noThreads > height){
    	noThreads = noThreads%height + 1;
    	printf("\nThe number of threads is grerater than height\nThen program will automatically choose required number of threads: %d threads", noThreads);
	}

    printf("\nPlease enter the size (level of blur) of the Kernel (blur matrix) that you want to use:\nEnter \"1\" for 3x3, \"2\" for 5x5, \"3\" for 7x7 matrix and so on: ");
    scanf("%d", &ksize);
    
    // 2D array to read height, width of image
    array = (int***)malloc(height * sizeof(int**));
    for (i = 0; i < height; i++) {
        array[i] = (int**)malloc(width * sizeof(int*));
        for (j = 0; j < width; j++) {
                array[i][j] = (int*)malloc(3 * sizeof(int));
        }
    }

	// Store pixels value in array
    if(error){
        printf("Error in decoding image %d: %s\n", error, lodepng_error_text(error));
    }else{
        for(i=0; i<height; i++){
            for(j=0; j<width; j++){
                for(k=0; k<3; k++){
                    array[i][j][k] = Image[4*width*i+ 4*j + k];
                }
            }
        }
    }

	// Slice array based on the height of the image.
    int slice_Height[noThreads];
	for(i=0; i<noThreads; i++){
		slice_Height[i] = height/noThreads;			
	}
	int reminder_Height = height%noThreads;
	for(i=0; i<reminder_Height; i++){
		slice_Height[i]++;
	}
	int start_Height[noThreads], end_Height[noThreads];
	for(i=0; i<noThreads; i++){
        if (i==0) {
            start_Height[i] = 0;
        } else {
            start_Height[i] = end_Height[i-1] + 1;
        }
        end_Height[i] = start_Height[i] + slice_Height[i] - 1;
    }

    
    // Add sliced height width start, end point and kernel
    struct pixels divider[noThreads];
    pthread_t threads[noThreads];
    int thid = 1;
    for(i=0; i<noThreads; i++){
        divider[i].start_h = start_Height[i];
        divider[i].end_h = end_Height[i];
        divider[i].height = height;
        divider[i].width = width; 
        divider[i].thread_ID = thid;
        divider[i].kernel_size = ksize;
        thid++;
        pthread_create(&threads[i], NULL, blur, &divider[i]);   
    }

    // Join threads 
    for(i=0; i<noThreads; i++){
        pthread_join(threads[i], NULL);   
    }
	
	// Encode the image
    unsigned char *png;
    char imagename[20];
    size_t pngsize;

    printf("\nImage has been blurred\nEnter the name of PNG image (including .png)): ");
    scanf("%s", &imagename);

    lodepng_encode32(&png, &pngsize, Image, width, height);
    lodepng_save_file(png, pngsize, imagename);
    
}
