#include<stdio.h>
int gcd ( int numb1, int numb2 );              
 
int main( )               
{
    int number_1, number_2, result;
    
    printf ( "\nEnter 2 number to find common max divisor\n");
    scanf ( "%d", &number_1 ) ;
    scanf ( "%d", &number_2 ) ;
    result = gcd(number_1, number_2);

    printf ( "\nGreatest divisor of these 2 number is: %d", result);
}
 
int gcd( int numb1, int numb2 )     
{                                   // This function calculates factorial while x>0
    int max_divisor = 0;
    int min_one;
    if (numb1 > numb2){
        min_one = numb2;
    }
    else{
        min_one = numb1;
    }
    for(int i = 1; i <= min_one; i++){
        if ((numb1 % i == 0) && (numb2 % i == 0)){
            max_divisor = i;
        }
    }
    return max_divisor;
}