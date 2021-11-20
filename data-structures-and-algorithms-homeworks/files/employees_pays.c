#include<stdio.h>
float pays ();              
 
int main( )               
{
    float input;
    input = pays();
    
    if (input == 0){
        return 0;
    }
    printf ( "\n Paymont of the selected employee is: %f", input);
}
 
float pays()     
{               
    float input;
    float amount;
    int times;
    float piece;
    float result;
    printf ( "\nEnter the type of employee \n");
    scanf ( "%f", &input );
    if (input > 4 || input < 1){
        printf ( "\nThere is no employee type like this. \n");
        printf ( "Employe type could be 1, 2, 3 or 4. \n");
        return 0;
    }
    
    if (input == 1){
        printf ( "\nEnter the weekly amount of the salary \n");
        scanf ( "%f", &amount);
        return amount;
    }
    else if (input == 2){
        printf("\nYou selected Hourly Workers type\n");
        printf("\nEnter hourly amount\n");
        scanf("%f", &amount);
        printf("\nEnter total hours that worked\n");
        scanf("%d", &times);
        result = amount * (times / 40) + amount * 1.5 * (times % 40);
        return result;
    }
    else if (input == 3){
        printf("\nYou selected Commission Workers type\n");
        printf("\nEnter total gross for this employee\n");
        scanf("%f", &amount);
        result = 250 + amount * 0.057;
        return result;
    }
    else if (input == 4){
        printf("\nYou selected PieceWorkers type\n");
        printf("\nEnter the number of pieces\n");
        scanf("%f", &piece);
        printf("\nEnter price of a piece\n");
        scanf("%f", &amount);
        result = piece * amount;
        return result;
    }

    return input;
}