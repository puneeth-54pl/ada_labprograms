#include <stdio.h>
#include <conio.h>

int n, w[10], v[10], W, i;
int sol[10] = {0,0,0,0,0,0,0,0,0,0};
int V[10][10];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void print_Sol()
{
    int LC, TV = 0, j;  /* TV is unused but kept to avoid changing your structure */
    LC = W;

    printf("\n\ni/j\t\t");
    for (j = 0; j <= W; j++)
        printf("%d\t", j);

    printf("\n\n\t\t");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
            printf("%d\t", V[i][j]);

        if (i < n)
            printf("\nitem %d\t\t", i + 1);
    }

    i = n;
    LC = W;

    while (i > 0)
    {
        if (V[i][LC] != V[i - 1][LC])
        {
            LC = LC - w[i];
            sol[i] = 1;
        }
        i--;
    }

    printf("\n\n\n Solution for the 0/1 Knapsack using Dynamic Programming   < ");
    for (i = 1; i <= n; i++)
    {
        printf("%d", sol[i]);
        if (i < n)
            printf(",  ");
    }

    printf(" >  and optimal value = %d", V[n][W]);
}

void DP_Knapsack()
{
    int j;

    for (i = 0; i <= n; i++)
        V[i][0] = 0;

    for (j = 0; j <= W; j++)
        V[0][j] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {
            if ((j - w[i]) < 0)
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], v[i] + V[i - 1][j - w[i]]);
        }
    }

    print_Sol();
}

void main()
{
    printf("Enter value for n ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter \"item %d\" weight and value ", i);
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }

    printf("\nEnter Capacity of the knapsack  ");
    scanf("%d", &W);

    DP_Knapsack();

    getch();  /* keep output screen visible in Turbo C */
}
