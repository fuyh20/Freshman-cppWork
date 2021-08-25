#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sort(char (*s)[81], int n)
{
    int i, j, k;
    char d[81] = {0};
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(s[j], s[k]) < 0)
                k = j;
        if (k != i)
        {
            strcpy(d, s[i]);
            strcpy(s[i], s[k]);
            strcpy(s[k], d);
        }
    }
}
int main()
{
    FILE *fp1, *fp2;
    char s[81] = {0};
    char(*p)[81];
    int n = 0, i = 0;
    if ((fp1 = fopen("D:/Coding cpp/data1", "r")) == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
    if ((fp2 = fopen("D:/Coding cpp/data2", "w")) == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
    while (!feof(fp1))
    {
        if (fgets(s, 80, fp1) == NULL)
            break;
        n++;
    }
    p = (char(*)[81])malloc(sizeof(char) * n * 81);
    n = 0;
    rewind(fp1);
    while (!feof(fp1))
    {
        if (fgets(p[n], 80, fp1) == NULL)
            break;
        n++;
    }
    for (int i = 0; i < n-1; i++)
        p[i][strlen(p[i])] = 0;
    p[n-1][strlen(p[n-1]) + 1] = 0;
    p[n-1][strlen(p[n-1])] = '\n';
    sort(p, n);
    for (i = 0; i < n; i++)
        fputs(p[i], fp2);
    free(p);
    fclose(fp2);
    fclose(fp1);
    return 0;
}