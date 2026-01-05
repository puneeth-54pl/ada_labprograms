#include <stdio.h>
#include <conio.h>

int R[10][10], n;

void Warshall()
{
    int i, j, k;     // Turbo C requires declarations at the top

    for (k = 1; k <= n; k++)
    {
        printf("\nvertex %d introduced as intermediate \n", k);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
                printf("%d\t", R[i][j]);
            }
            printf("\n");
        }
    }
    getch();   // same logic as your code
}

void main()
{
    int i, j;
    clrscr();

    printf("Program to find Transitive Closure of a graph\n");
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter Adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &R[i][j]);

    Warshall();

    getch();   // to keep screen open at the end
}
