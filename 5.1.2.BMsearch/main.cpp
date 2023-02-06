#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bmSearch(const char *str, const char *substr)
{
    int m, n;
    n = strlen(str);
    m = strlen(substr);

    if(m > n)
        return -1;

    int tab[256];
    for (int i = 0; i < 256; i++)
        tab[i] = m;

    for (int i = 0; i < m - 1; i++)
        tab[(unsigned char) substr[i]] = m - 1 - i;
    
    int i = m - 1;
    while (i < n)
    {
        int k = i, j = m - 1;
        while(str[k] == substr[j] && j >= 0)
        {    
            k--;
            j--;
        }
        if (j < 0)
            return k + 1;
        i += tab[(unsigned char)str[i]];
    }

    return -1;
}

void show(const char * str, const char * substr, const int pos) {
    printf("%s\n", str);
    for(int i = 0; i < pos; i++)
        printf(" ");
    printf("%s\n", substr);
}

int main()
{
    char str[500]; 
    printf("Input string: ");
    scanf("%[^\n]%*c", &str);

    char substr[50];
    printf("Input substring: ");
    scanf("%[^\n]%*c", &substr);

    show(str, substr, bmSearch(str, substr));
    return 0;
}