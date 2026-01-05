#include <stdio.h>
#include <string.h>
#include <time.h>

char text[100], pattern[50];

int bruteForceStringMatch()
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    for (i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}

void main()
{
    int result;
    clock_t start, end;
    double cpu_time_used;
    clrscr();
    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    start = clock();
    result = bruteForceStringMatch();
    end = clock();

    cpu_time_used = (double)(end - start) / CLK_TCK;

    if (result != -1)
	printf("\nPattern found at index %d\n", result);
    else
	printf("\nPattern not found\n");

    printf("\nExecution time: %f seconds\n", cpu_time_used);
     getch();
}