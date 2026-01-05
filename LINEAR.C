#include <stdio.h>
#include <time.h>
#include <dos.h>      /* for delay() in Turbo C */

int a[5000];

int seqSearch(int n, int k)
{
    int i;
    i = 0;
    while (a[i] != k)
    {
        i = i + 1;
        delay(25);   /* was Sleep(25); same delay idea, Turbo C style */
    }
    if (i < n)
        return i;
    else
        return -1;
}

int main()
{
    clock_t beg, end;
    double t[5];
    unsigned int k, i, p, n[5] = {100, 200, 300, 400, 500}, key;
    clrscr();
    for (k = 0; k < 5; k++)
    {
	for (i = 0; i < n[k]; i++)
	    a[i] = i + 1;

	key = n[k];

	beg = clock();
	p = seqSearch(n[k], key);
	p++;

	if (p > 0)
	    printf("\nSuccessful Search: n = %d, key = %d,  pos = %d\n", n[k], key, p);
	else
	    printf("\nUnSuccessful Search: ");

	end = clock();

	/* Turbo C uses CLK_TCK for ticks per second */
	t[k] = (double)(end - beg) / CLK_TCK;

	printf("Time Required  %.2f", t[k]);
    }

    puts("\n\n\t\tSequential Search - Emperical Analysis in Worst Case");
    printf("\n\t\tInput Size\t\t\tTime Required(in secs)");
    for (i = 0; i < 5; i++)
	printf("\n\t\t%d\t\t\t\t %2.2f", n[i], t[i]);

    puts("\nEnter Any key to return to the prog");
    getchar();   /* waits for a key before closing */

    return 0;
}
