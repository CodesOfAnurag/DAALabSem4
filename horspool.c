#include<stdio.h>
#include<string.h>
#include<stdio.h>

int table[256];

void shtab(char p[])
{
    int i, m = strlen(p);
    for(i=0; i<256; i++)
        table[i]=m;
    for(i=0; i<m; i++)
        table[(int)p[i]]=m-1-i;
}

int hors(char p[], char t[])
{
    shtab(p);
    int m = strlen(p), k=0, i;
    i=m-1;
    while(i<strlen(t))
    {
        if (k<m && p[m-k-1]==t[i-k])
            k++;
        if (k==m)
            return i-m+1;
        i+=table[t[i]];
    }
    return -1;
}

void main()
{
    char p[100], t[100];
    puts("Enter String : ");
    gets(t);
    puts("Enter Pattern : ");
    gets(p);
    int pos = hors(p, t);
    printf("Found at : %d\n", pos);
}