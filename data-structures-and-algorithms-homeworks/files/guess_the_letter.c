#include <stdio.h>
int main()
{
    int random_generator, number;
    int retries = 0;
    char guess;
    char name[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '\0'};
    
    printf("Enter a number to generate random letter for game: ");
    scanf("%d", &number);
    
    random_generator = 1000 % number;
    printf("%c \n", name[random_generator]);
    printf("%d \n", random_generator);
    while(1){
        printf("\nGUESS THE LETTER: ");
        scanf(" %c", &guess);
        printf("\n");
        retries += 1;
        if (guess == name[random_generator]){
            printf("Great! Your guess is right!");
            if (retries <= 5){
            printf("I guess you know the secret!");
        }
            return 0;
        }
        else if (guess > name[random_generator]){
            printf("\nWay ahead! Please try again.");
        }
        else if (guess < name[random_generator]){
            printf("\nWay behind! Please try again.");
        }
                
        if (retries <= 5){
            printf("Either you know the secret or you are lucky!");
        }
        else{
            printf("You should be able to do better!");
        }

    }
    
    return 0;
}