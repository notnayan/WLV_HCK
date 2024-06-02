/*
Student Name: Nayan Raj Khanal
University ID: 2227486

This CUDA C program utilizes parallel processing on a GPU to crack an encrypted password. 
It employs a CUDA kernel, decryptPass, to generate potential password combinations and decrypt them using a function called Cudacrack. 
The code efficiently searches for the correct password by leveraging GPU threads. 
The main function initializes character sets, allocates memory on both the CPU and GPU, launches the kernel, and prints the results, displaying the original encrypted password and the decrypted password if found. 
The program demonstrates a parallelized approach to password decryption using CUDA.

1.	Generate encrypted password in the kernel function (using CudaCrypt function) to be compared to original encrypted password:
The Cudacrack function in the CUDA kernel is responsible for generating an encrypted password based on a given raw password. 
The transformation involves adding and subtracting specific values to each character in the raw password. 
The resulting encrypted password is then checked against the target encrypted password.

2.	Allocating the correct amount of memory on the GPU based on input data. Memory is freed once used:
Memory is allocated on the GPU for the alphabet, numbers, encrypted password, and the output password. 
The correct amount of memory is allocated based on the size of the data (alphabet, numbers, encrypted password, and output password). 
Memory is freed once it is no longer needed.

3.	Program works with multiple blocks and threads: 
The CUDA kernel decryptPass is designed to work with multiple blocks and threads. 
The kernel is launched with a 2D grid (dim3(26, 26, 1)) and 2D block (dim3(10, 10, 1)) configuration to explore different combinations of alphabet and numbers.

4.	Decrypted password sent back to the CPU and printed:
If a thread finds a matching password, it prints the result, including the encrypted and decrypted passwords. 
The decrypted password is sent back to the CPU, and the results are printed on the CPU.

*/

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//__global__ --> GPU function which can be launched by many blocks and threads
//__device__ --> GPU function or variables
//__host__ --> CPU function or variables

__device__ char* Cudacrack(char* rawPassword) {
    char * newPassword = (char *) malloc(sizeof(char) * 11);

    newPassword[0] = rawPassword[0] + 2;
    newPassword[1] = rawPassword[0] - 2;
    newPassword[2] = rawPassword[0] + 1;
    newPassword[3] = rawPassword[1] + 3;
    newPassword[4] = rawPassword[1] - 3;
    newPassword[5] = rawPassword[1] - 1;
    newPassword[6] = rawPassword[2] + 2;
    newPassword[7] = rawPassword[2] - 2;
    newPassword[8] = rawPassword[3] + 4;
    newPassword[9] = rawPassword[3] - 4;
    newPassword[10] = '\0';

    for(int i = 0; i < 10; i++){
        if(i >= 0 && i < 6){ // checking all lowercase letter limits
            if(newPassword[i] > 122){
                newPassword[i] = (newPassword[i] - 122) + 97;
            } else if(newPassword[i] < 97){
                newPassword[i] = (97 - newPassword[i]) + 97;
            }
        } else { // checking number section
            if(newPassword[i] > 57){
                newPassword[i] = (newPassword[i] - 57) + 48;
            } else if(newPassword[i] < 48){
                newPassword[i] = (48 - newPassword[i]) + 48;
            }
        }
    }
    return newPassword;
}

// CUDA kernel to check potential passwords against the encrypted password
__device__ int arePassEqual(char* one, char* two, int length) {
    int result = 1;
    for (int i = 0; i < length; i++) {
        if (one[i] != two[i]) {
            result = 0;
            break;
        }
    }
    return result;
}

// CUDA kernel to perform password decryption using Cudacrack on all possible combinations
__global__ void decryptPass(char* alphabet, char* numbers, char* encryptedPass, char* deviceOutputPass) {
    int threadID = blockDim.x * blockIdx.x + threadIdx.x;

    // Check if a password has already been found by other threads
    if(*deviceOutputPass != '\0') {
        return;
    }

    // Create a potential password combination based on thread indices
    char potentialPass[4];
    potentialPass[0] = alphabet[blockIdx.x];
    potentialPass[1] = alphabet[blockIdx.y];
    potentialPass[2] = numbers[threadIdx.x];
    potentialPass[3] = numbers[threadIdx.y];

    // Apply Cudacrack transformations to the potential password
    char* encryptedPotential = Cudacrack(potentialPass);

    // Check if the encrypted potential password matches the target encrypted password
    if (arePassEqual(encryptedPass, encryptedPotential, 11)) {
        // Print the result if a match is found and copy the password to the output
        printf("ThreadID '%d' found password of '%s' is '%s'\n", threadID, encryptedPass, potentialPass);
        for (int i = 0; i < 4; i++ ) {
            deviceOutputPass[i] = potentialPass[i];
        }
    }

    free(encryptedPotential); // Free allocated memory
}

// Main function
int main(int argc, char** argv) {

	/*
		Test Encrypted Passwords:
		x y 3 3 = zvycvx5171
    p p 1 3 = rnqsmo3171
		s p 1 8 = uqtsmo3134
	*/
    // Encrypted password
    const char* encryptedPass = "rnqsmo3171"; //pp13
    if (argc > 1) {
        encryptedPass = argv[1];
    }
    printf("Encrypted Password: '%s'\n", encryptedPass);
    printf("---\n");

    // Character sets for alphabet and numbers
    char cpuAlphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    char cpuNumbers[10] = { '0', '1', '2', '3', '4', '5', '6' ,'7', '8', '9' };

    // Size of the encrypted password
    int sizeOfEncryptedPass = sizeof(char) * 11;

    // Allocate and copy memory for alphabet, numbers, encrypted password, and output password on GPU
    char* gpuAlphabet;
    cudaMalloc((void**) &gpuAlphabet, sizeof(char) * 26);
    cudaMemcpy(gpuAlphabet, cpuAlphabet, sizeof(char) * 26, cudaMemcpyHostToDevice);

    char* gpuNumbers;
    cudaMalloc((void**) &gpuNumbers, sizeof(char) * 10);
    cudaMemcpy(gpuNumbers, cpuNumbers, sizeof(char) * 10, cudaMemcpyHostToDevice);

    char* gpuEncryptedPass;
    cudaMalloc((void**) &gpuEncryptedPass, sizeOfEncryptedPass);
    cudaMemcpy(gpuEncryptedPass, encryptedPass, sizeOfEncryptedPass, cudaMemcpyHostToDevice);

    char* gpuOutputPass;
    cudaMalloc((void**) &gpuOutputPass, sizeOfEncryptedPass);

    // Launch CUDA kernel to decrypt the password
    decryptPass<<< dim3(26, 26, 1), dim3(10, 10, 1) >>>(gpuAlphabet, gpuNumbers, gpuEncryptedPass, gpuOutputPass);

    // Ensure the kernel has completed execution before proceeding
    cudaDeviceSynchronize();
    printf("CUDA threads synchronization completed!\n");

    // Allocate and copy memory for the output password on CPU
    char* cpuOutputPass = (char*)malloc(sizeof(char) * 4);
    cudaMemcpy(cpuOutputPass, gpuOutputPass, sizeOfEncryptedPass, cudaMemcpyDeviceToHost);

    printf("---\n");
    printf("Results:\n");

    // Print the decrypted and encrypted passwords or an error message
    if (cpuOutputPass != NULL && cpuOutputPass[0] != '\0') {
        printf("1. Given Encrypted Pass: '%s'\n", encryptedPass);
        printf("2. Found Decrypted Pass: '%s'\n", cpuOutputPass);
    } else {
        printf("Unable to determine a password.\n");
    }

    // Free allocated GPU and CPU memory
    cudaFree(gpuAlphabet);
    cudaFree(gpuNumbers);
    cudaFree(gpuEncryptedPass);
    cudaFree(gpuOutputPass);
    free(cpuOutputPass);

    return 0;
}
