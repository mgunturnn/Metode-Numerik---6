// integral riemann

#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Define function here */
#define f(x) 2*x + 3

int main() {
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval,x;
 
 //JUDUL
 printf("==PROGRAM INTEGRAL RIEMANN== \n \n");
 

 //Meminta masukan user
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);

//Proses Menghitung
 //Menemukan StepSize
 stepSize = (upper - lower)/subInterval;
 x =  lower + stepSize / 2;
 /* Finding Integration Value */
 integration = f(x);
 for(i=1; i<= subInterval-1; i++)
 {
 	x += stepSize;
 	integration += ((i-1)*f(x));
 }
 integration = integration * stepSize;
 printf("\nRequired value of integration is: %.3f", integration);
 getch();
 return 0;
}
