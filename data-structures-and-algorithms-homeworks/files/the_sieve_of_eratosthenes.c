#include<stdio.h>   

int eratos_sieve(int number);
int main(){
    int input;
    int result;
    
    printf("\n Enter a number to find primes that lower than it: ");
    scanf ( "%d", &input );
    input += 1; // Bc my conditions calculates for n-1
    
    result = eratos_sieve(input);
     printf("Result: %d", result);
      return 0;  
     }
 
 int eratos_sieve(int number){
    int name[number];
    for (int k=0; k< number+1; k++){
        name[k] = 0; // this step fills array with 1s.
    }
    int prime_check = 1; // this parameter used to check prime situation
    for (int i=2; i < number; i++){
        prime_check = 1;
        for(int j=2; j < i; j++){
            if (i % j == 0){ //if it is not prime, prime check changes
                prime_check = i;
            }
        }
        if (prime_check==1){
            name[i] = i;
            printf("%d: prime_check-> %d\n", i, prime_check); // this printf show all primes in a good way.
        }   // if it is prime, then array[number] updated with prime number it
    }
    for (int z=2; z < number; z++){
        printf("%d\n", name[z]); // this is to show latest array
    }
     return 1;
 }
 