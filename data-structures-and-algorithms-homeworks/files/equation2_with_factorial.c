#include<stdio.h>
float factorial ( float number );           
 
int main( )               
{
    float input;
    float result= 1.00;
    printf ( "\nEnter a number to test equation \n");
    scanf ( "%f", &input ) ;
    float input_copy = input;
    // function call
    for (int i = 1; i <= input; i++){
        result += input_copy/factorial(i);
        input_copy *= input_copy;
    }
    printf ( "\n e is equal to %f for %f iteration", result, input);
}
 
float factorial( float number )   
{                                
    double facto = 1;
    for(double i = 1; i <= number; i+= 1.00){
        facto *= i;
    }
    return facto;
}