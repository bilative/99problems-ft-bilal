// Actually I realized when I commit results to github that, this answers looks so silly.
// Sorry for that but probably I had a problem with time limit in the exam. Bc of this I had to rush probably.

//1-
Ap = a;

//2-
Int len;
len = sizeof(*a) / sizeof(*a[0]);
int totalNumb;
totalNumb = func(&ap, len);

//3-
printf("summation of array elements: %d\n", totalNumb);

//4- 
    int func(int *p, int len){
        int total = 0;
        //x = sizeof(*A) / sizeof(*A[0]);
        for (int j = 0; j <= len; j++){
            total += *A[j];
        }
        return total
    }
