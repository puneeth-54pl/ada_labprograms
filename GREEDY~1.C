#include <stdio.h>
int n,w[10], v[10], W, i,  sol[10]={0,0,0,0,0,0,0,0,0,0};
void Greedy_Knapsack()
{
    int LC, TV=0;
    LC = W;
    i =1;
    while (i<=n)
    {
        if (w[i]<=LC)
         {
            TV += v[i];
            LC = LC-w[i];
            sol[i]=1;
         }
         i++;
    }
    printf("\n solution for the knapsack    < ");
    for(i=1;i<=n; i++)
    {
        printf("%d", sol[i]);
        if (i<(n-1))
            printf(",  ");
    }

    printf(" >  and optimal value = %d", TV);
}


int main()
{   clrscr();
    printf("Enter value for n ");
    scanf("%d", &n);
    printf("\nEnter weight and Value of n items, such that v/w is in descending order");
    for(i=1; i<=n; i++)
    {
	    printf("\nEnter \"item %d \" weight and value ",i);
	    scanf("%d", &w[i]);
	    scanf("%d", &v[i]);
    }

    printf("\nEnter Capacity of the knapscak  ");
    scanf("%d", &W);
    Greedy_Knapsack();
    getch();
return 0;
}
