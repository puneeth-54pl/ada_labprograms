#include <stdio.h>
#include <time.h>
#include <dos.h>   /* for delay() in Turbo C */

unsigned long int a[5000];

int BinSearch(int l, int h, int k)
{
    int mid;

    delay(250);  /* was Sleep(250); */

    if (l > h)
	return -1;

    mid = (l + h) / 2;

    if (a[mid] == k)
	return mid;
    else if (k < a[mid])
	return BinSearch(l, mid - 1, k);
    else
	return BinSearch(mid + 1, h, k);
}

int main()
{
    clock_t beg, end;
    double t[5];
    unsigned int k, i, p;
    unsigned int n[5] = {100, 200, 3000, 4000, 5000};
    unsigned int key;
    clrscr();
    for (k = 0; k < 5; k++)
    {
        /* initialize the array a[0..n[k]-1] = 1..n[k] */
        for (i = 0; i < n[k]; i++)
            a[i] = i + 1;

        key = n[k];  /* search for the last element */

        beg = clock();

        /* high index must be n[k] - 1, not n[k] */
        p = BinSearch(0, n[k] - 1, key);
        p++;  /* your original code increments position for 1-based printing */

        if (p > 0)
            printf("\nSuccessful Search: n = %u, key = %u, pos = %u\n", n[k], key, p);
        else
            printf("\nUnSuccessful Search: ");

        end = clock();

        /* Turbo C uses CLK_TCK for clock ticks per second */
        t[k] = (double)(end - beg) / CLK_TCK;

        printf("Time Required  %f", t[k]);
    }

    puts("\n\n\t\tBinary Search - Empirical Analysis in Worst Case");
    printf("\n\t\tInput Size\t\t\tTime Required(in secs)");
    for (i = 0; i < 5; i++)
        printf("\n\t\t%u\t\t\t\t %2.6f", n[i], t[i]);

    puts("\nEnter any key to return to the prog");
    getchar();

    return 0;
}
