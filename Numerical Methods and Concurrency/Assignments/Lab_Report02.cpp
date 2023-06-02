#include <stdio.h>
#include <math.h>

//1.

//int cube(int n)
//{
//	int cube;
//	cube=n*n*n;
//	printf("The cube of %d is: %d",n,cube);
//}
//
//int main()
//{
//	int num;
//	printf("Enter a number: ");
//	scanf("%d",&num);
//	cube(num);
//	return 0;
//}
 
 //2.
 
//int swapNums(int a,int b)  
//{
//    int temp;  
//    temp = a;  
//    a = b;  
//    b = temp;
//	printf("After swapping a = %d and b = %d", a, b); 
//    return 0;
//}  
//
//int main()  
//{
//	int a;
//	printf("a = ");
//	scanf("%d",&a);
//	int b;
//	printf("b = ");
//	scanf("%d",&b);
//	printf("Before swapping a = %d and b = %d\n", a,b);
//    swapNums(a,b);
//    return 0;  
//}  

//3.

//void midPoint(int x1, int y1, int x2, int y2){
//	int xmid,ymid;
//	xmid = (x1+x2)/2;
//	ymid=(y1+y2)/2;
//	printf("The mid-point coordinate of x-axis is: %d\n",xmid);
//	printf("The mid-point coordinate of y-axis is: %d",ymid);
//}
//
//int main(){
//	midPoint(6, 0, 0, 9);
//	return 0;	
//}

//4.

//int checkArmstrong(int n) 
//{
//    int ld, sum, num;
//    sum = 0;
//    num = n;
//    while(num!=0)  
//    {  
//        ld = num % 10;  
//        sum += ld * ld * ld;  
//        num = num/10;  
//    }
//    
//    if(n==sum)
//    {
//        printf(" The number %d, is an Armstrong number.\n", n);
//    }
//    else
//    {
//        printf(" The number %d, is not an Armstrong number.\n", n);
//    }
//    return 0;
//}
//
//int checkPerfect(int n) 
//{
//    int i, sum, num;
//    sum = 0;
//    num = n;
//    for(i=1; i<num; i++)  
//    {  
//        
//        if(num%i == 0)  
//        {  
//            sum += i;  
//        }  
//    }
//    
//    if(n == sum)
//    {
//        printf(" The number %d, is a Perfect number.", n);
//    }
//    else
//    {
//        printf(" The number %d, is not a Perfect number.", n);
//    }
//	  return 0;
//} 

//int main()
//{
//    checkArmstrong(370);
//    checkPerfect(6);
//    return 0;
//}

//5.

//int velocityCalc(float v, float u,float a, float t){
//	if(isnan(v))
//	{
//		v = u + (a * t);
//		printf("The final velocity (v) is = %.2f", v);
//	}
//	else if(isnan(u))
//	{
//		u = v - (a * t);
//		printf("The initial velocity (u) is = %.2f", u);
//	}
//	else if(isnan(a))
//	{
//		a = (v - u)/t;
//		printf("The acceleration (a) is = %.2f", a);
//	}
//	else if(isnan(t))
//	{
//		t = (v - u)/a;
//		printf("The time (t) is = %.2f", t);
//	}
//	else
//	{
//		printf("Please re-check your inputs for v,u,a,t!");
//	}
//	return 0;
//	
//}
//
//int main(){
//	velocityCalc(NAN,1,1,1);
//  	return 0;
//}

//6.

//void Equations(double a, double b, double c, double d, double e, double f){
//	double x = (c*e - f*b) / (a*e - d*b);
//    double y = (c*d - f*a) / (b*d - e*a);
//	printf("The two lines cross each other at the point:\nx = %.2f and y = %.2f",x,y);
//	
//}
//int main(){
//	Equations(1,2,3,4,5,6);
//	return 0;
//}
