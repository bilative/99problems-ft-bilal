#include <time.h>
#include <stdlib.h>
#include <stdio.h>   
#include <unistd.h>
int generate_random();
int tortoise_move(int lucky_number);
int hare_move(int lucky_number);
void assign_location(int *current, int new);

int main(){
    int torto; // This ones have used to random movements
    int hare;  // This ones have used to random movements
    
    int tortoise_location = 1; // initial locations
    int hare_location = 1;     // initial locations
    srand(time(0));
  while(1){
        int torto = tortoise_move(generate_random());
        int hare = hare_move(generate_random());
        
        assign_location(&tortoise_location, torto); // POINTERS HAVE USED IN THIS FUNCTION --> YOU CAN CHECK FUNCTION 'assign_location' DESCRIBED AT THE BOTTOM
        assign_location(&hare_location, hare);      // POINTERS HAVE USED IN THIS FUNCTION --> YOU CAN CHECK FUNCTION 'assign_location' DESCRIBED AT THE BOTTOM
        
        if ((tortoise_location == hare_location) && (tortoise_location < 70)){ // bc if location > 70 race should end with tie
            printf("OUCH!! \n\n");
        }
        else if (tortoise_location >= 70 || hare_location >= 70){ // I made this bc if it is not situation checks only 1 time (for less cost)
            if (tortoise_location >= 70 && hare_location >= 70){  // This mean they both finished in the same time
                printf("It's a tie");
                return 0;
            }
            else if (tortoise_location >= 70){ // This mean tortoise wins
                printf("TORTOISE WINS!!!");
                return 0;
            }
            printf("Hare wins. Yuch"); // This mean Hare wins
            return 0;
        }
        else{
            printf("tortoise: ");
            for(int i=0;i<tortoise_location;++i){
                printf("#");
            }
            printf(" %d \n", tortoise_location);
            
            
            printf("Hare:     ");
            for(int i=0;i<hare_location;++i){
                printf("#");
            }
            printf(" %d \n\n", hare_location);
            sleep(1);
        }
}
  return 0;
}

// I proveded randomizations with the movements with this way
int generate_random(){
    int num = (rand() % 10) + 1;
    return num;
}

int tortoise_move(int lucky_number){
    if (lucky_number <= 5){
        return 3; // fast plod
    }
    else if (lucky_number <= 7){
        return -6; // slip
    }
    else {
        return 1; // slow plod
    }
}

int hare_move(int lucky_number){
    if (lucky_number <= 2){
        return 0; // sleep
    }
    else if (lucky_number <= 4){
        return 9; // big hop
    }
    else if (lucky_number <= 5){
        return -12; // big slip
    }
    else if (lucky_number <= 8){
        return 1; // small hop
    }
    else {
        return -2; // small slip
    }
}

// I used pointers in this part, my functions has no output, but it effects location value with the address.
// This functions used in row 21 and 22
void assign_location(int *current, int new){
    if (*current + new < 1){
        *current = 1;
    }
    else{
        * current = *current + new;
    }
}