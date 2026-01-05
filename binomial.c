#include <stdio.h>
#include <conio.h>

int c[50][50], n, k;

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void print_BC()
{
    int i, j;

    printf("\n\nTo find C[n,k] using Dynamic Programming\n");
    printf("i/j\t");

    for (i = 0; i <= k; i++)
        printf("%d\t", i);

    printf("\n");

    for (i = 0; i <= n; i++)
    {
        printf("\n%d\t", i);
        for (j = 0; j <= min(i, k); j++)
            printf("%d\t", c[i][j]);
    }

    printf("\n\nBinomial Coefficient using Dynamic Programming C[%d, %d] = %d\n\n",
           n, k, c[n][k]);
}

void BC()
{
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if ((j == 0) || (j == i))
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

void main()
{
    clrscr();

    printf("Enter non-ve integer n and k: ");
    scanf("%d%d", &n, &k);

    BC();
    print_BC();

    getch();  // so output window stays
}
