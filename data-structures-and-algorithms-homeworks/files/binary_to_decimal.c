#include <stdio.h>

int main(void)
{
    int number;
    int factorial = 1;  // Idea behind my approach is;
    int pow10 = 10;         // Divide number to 10 and take residual
    int pow2 = 1;           // multiply residual with 2^i and add it to result 
    int residual = 1;       // later I subtract residual from number, so new number could be divide by 10 again with same logic
    int result = 0;         // With this approach I could remove last digit everytime and process could run with same idea again and again
    int error_ = 0;           
  
    printf("Enter a binary number!\n");
    scanf("%d", &number);
    
    for(int i=1; i<=5; i++){
        if (number !=0) {
            residual = number % pow10;
            number -= residual;
            number /= 10;
            result += residual * pow2;
            pow2 *= 2;
            if (residual > 1){
                error_ += 1; // If base is not 2, this counter will raise +1 to alert
            }              
        }
    }
    if (error_ > 0){
        printf("Base of the number is not 2\n");
    }
    else {
        printf("%d\n", result);
    }
}
