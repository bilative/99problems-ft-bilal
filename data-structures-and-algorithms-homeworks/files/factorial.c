#include <stdio.h>

int main(void)
{
    int number;
    int factorial = 1;
    
    printf("Enter the number to calculate factorial!\n");
    scanf("%d", &number);
    
    if (number < 0){
        printf("You cant calculate the factorials of negative numbers!");
    }
    else if (number == 0){
        printf("factorial of 0 is ----> 1\n");
    }
    else{
        for (int i=1;i<=number;i++)
            {
                factorial *= i;
            }    
        printf("factorial of %d is ----> %d\n", number,factorial);
    }
}