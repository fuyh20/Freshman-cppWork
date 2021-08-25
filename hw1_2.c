#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned char a[256] = {0};
void Reverse(unsigned char a[], int n)
{
    int b[8];
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            b[k] = a[i] % 2;
            a[i] /= 2;
        }
        a[i] = 0;
        for (int k = 0; k < 8; k++)
            a[i] += b[k] * pow(2, 7-k);
    }
}
int main()
{
    FILE *fp1, *fp2;
    unsigned char c;
    for (int i = 0; i < 256; i++)
        a[i] = i;
    Reverse(a, 256);
    if ((fp1 = fopen("D:/Coding cpp/b1", "rb")) == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
    if ((fp2 = fopen("D:/Coding cpp/b2", "wb")) == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
    while (fread(&c, sizeof(char), 1, fp1))
    {
        fwrite(a + c, sizeof(char), 1, fp2);
    }
    fclose(fp2);
    fclose(fp1);
    return 0;
}