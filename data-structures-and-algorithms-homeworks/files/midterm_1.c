#include <stdio.h>
int power(int x);
int main()
{
    int input_number;
    int sonuc;
    printf("give me a number to test");
    scanf ( "%d", &input_number ) ;
    sonuc = power(input_number);
    printf("%d", sonuc);
    return 0;
}
int power(int x)
{
    if (x > 1){
        return x*x + power(x-1) ;
    }
    return 0;
}
