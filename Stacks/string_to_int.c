// CONVERTING DATATYPE OF STRING OF NUMBERS TO INTEGER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fun(char s[]) // OR int fun(char *s)
{
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
        sum = sum * 10 + (s[i] - 48);
    return sum;
};

int main()
{
    char s[100] = "20";
    char s1[100] = "14";
    int a = fun(s);
    int b = fun(s1);
    printf("The integer value is %d\n", a);
    printf("The integer value is %d\n", b);
    printf("The integer value is %d\n", a + b);
    return 0;
}
