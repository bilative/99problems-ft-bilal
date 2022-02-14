#include <stdio.h>
int main()
{
    int saat;
    int ogrenci_sayisi = 0;
    int A[2][11] = {
            {2, 1, 5, 2, 3, 1, 3, 2, 2, 6, 9},
            {8, 3, 7, 4, 6, 4, 8, 5, 8, 9, 10}
        };
    printf("give the number of the ogrenci \n");
    scanf ( "%d", &saat ) ;
    for (int i=0; i<= 10; i++){
        if ((saat >= A[0][i]) && (saat <= A[1][i])){
            ogrenci_sayisi += 1;
        }
    }
    printf("When it was %d there are %d \n\n", saat, ogrenci_sayisi);

    return 0;
}
