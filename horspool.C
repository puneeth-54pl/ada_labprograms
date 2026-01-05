#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256   /* Size of alphabet (ASCII) */

int Table[MAX];

/* Shift Table Construction */
void ShiftTable(char P[])
{
    int i, j, m;
    m = strlen(P);

    for (i = 0; i < MAX; i++)
        Table[i] = m;

    for (j = 0; j < m - 1; j++)
        Table[(unsigned char)P[j]] = m - 1 - j;
}

/* Horspool Matching Algorithm */
int HorspoolMatching(char T[], char P[])
{
    int i, k, m, n;
    n = strlen(T);
    m = strlen(P);

    i = m - 1;
    while (i < n)
    {
        k = 0;
        while (k < m && P[m - 1 - k] == T[i - k])
            k++;

        if (k == m)
            return i - m + 1;
        else
            i = i + Table[(unsigned char)T[i]];
    }
    return -1;
}

/* Main Function */
void main()
{
    char T[1000], P[100];
    int pos;
    char ch;

    do
    {
        clrscr();
        printf("\n***** Horspool String Matching Algorithm *****\n\n");

        printf("Enter the text    : ");
        gets(T);

        printf("Enter the pattern : ");
        gets(P);

        ShiftTable(P);
        pos = HorspoolMatching(T, P);

        if (pos >= 0)
            printf("\nPattern found at position %d\n", pos + 1);
        else
            printf("\nPattern not found\n");

        printf("\nDo you want to continue (Y/N): ");
        ch = getch();

    } while (tolower(ch) == 'y');
}
