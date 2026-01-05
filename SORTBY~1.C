#include <stdio.h>
#include <time.h>
#include <dos.h>   // for delay()

int a[500], s[500];

void Sort_by_Counting(int n)
{
    int count[500];
    int i, j;

    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[i] > a[j])
                count[i]++;
            else
                count[j]++;
            delay(15);   // Turbo C compatible
        }
    }

    printf("\n\n\tElement\tValue\tCount");
    for (i = 0; i < n; i++)
    {
        s[count[i]] = a[i];
        printf("\n\t%d\t%d\t%d", i, a[i], count[i]);
    }
}

int main()
{
    clock_t beg, end;
    double t[5];
    int i, j;
    int in[5] = {5,10,15};

    printf("\n----------Sort By Counting----------\n");

    for (i = 0; i<3;i++)      {
	printf("\n\n%d. Before Sorting (Input Size = %d)\n", i + 1, in[i]);
	for (j = 0; j < in[i]; j++)
	{
            a[j] = rand() % 100;
            if (j % 10 == 0)
                printf("\n\t");
            printf("%d\t", a[j]);
        }

        beg = clock();
        Sort_by_Counting(in[i]);
        end = clock();

        t[i] = (double)(end - beg) / CLOCKS_PER_SEC;

        printf("\n\nAfter Sorting:\n\t");
        for (j = 0; j < in[i]; j++)
        {
            if (j % 10 == 0)
                printf("\n\t");
            printf("%d\t", s[j]);
        }

        printf("\n\nTime Required: %f seconds\n", t[i]);
    }

    printf("\n--- Sort by Counting (Input Enhancement) Empirical Analysis ---\n");
    printf("\nInput Size\tTime (sec)");
    for (i = 0; i < 5; i++)
        printf("\n%d\t\t%f", in[i], t[i]);

    getch();
    return 0;
}
