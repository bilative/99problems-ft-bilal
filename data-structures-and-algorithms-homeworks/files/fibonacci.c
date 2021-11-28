#include<stdio.h>   

int fibo(int number);
int main(){
    int input;
    int result;
    
    printf("\n Write the order of the Fibonacci Number you wanna find: ");
    scanf ( "%d", &input );
    
    result = fibo(input);
 printf("Result: %d", result);
  return 0;  
 }
 
 int fibo(int number){
     int number_1 = 0;
     int number_2 = 1;
     int result;
     for(int i=2; i < number; i++){
         result = number_1 + number_2;
         number_1 = number_2;
         number_2 = result;
     }
     return result;
 }