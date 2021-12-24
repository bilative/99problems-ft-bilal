#include <stdio.h>

int main()
{
    char LETTER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
    char letter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    int counts[26] = {0};

    for (int i = 0; i <= 25; i++)
    {
        FILE *fp = fopen("english_text.txt", "r");
        do
        {
            char c = fgetc(fp);
            if ((c == LETTER[i]) | (c == letter[i]))
            {
                counts[i] += 1;
            }
            if (feof(fp))
            {

                fclose(fp);
                break;
            }
        } while (1);
    }
    // for (int i = 0; i <= 25; i++)
    // {
    //     printf("%d, %c\n", counts[i], LETTER[i]);
    // }

    FILE *writeit = fopen("count.dat", "w");

    fprintf(writeit, "Character     Count\n");
    for (int j = 0; j < 26; j++)
    {
        fprintf(writeit, "%c             %d\n", letter[j], counts[j]);
        fflush(NULL);
    }

    return (0);
}