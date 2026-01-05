#include <stdio.h>
#include <conio.h>

int D[10][10], n;

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void Floyd()
{
    int i, j, k;   // moved declarations out of for-loops (Turbo C requirement)

    for (k = 1; k <= n; k++)
    {
        printf("\n\nvertex %d introduced as intermediate \n", k);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                D[i][j] = min(D[i][j], (D[i][k] + D[k][j]));
                printf("%d\t", D[i][j]);
            }
            printf("\n");
        }
        getch();   // same as your original logic
    }
}

void main()
{
    int i, j;     // declare loop variables here for Turbo C

    clrscr();     // optional, but common in Turbo C

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency matrix of the graph: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &D[i][j]);

    Floyd();

    getch();      // to keep output window open at the end
}
