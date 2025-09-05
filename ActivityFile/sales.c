#include <stdio.h>
#include <stdlib.h>

float totalSale(float s[], int n)
{
    float t = 0;
    for (int i = 0; i < n; i++)
        t += s[i];
    return t;
}

float maxSale(float s[], int n)
{
    float m = s[0];
    for (int i = 1; i < n; i++)
        if (s[i] > m)
            m = s[i];
    return m;
}

int main()
{
    FILE *f = fopen("sales.txt", "r");
    if (!f)
        return 1;
    int n = 0;
    float x;
    while (fscanf(f, "%f", &x) == 1)
        n++;
    rewind(f);

    float *s = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
        fscanf(f, "%f", &s[i]);
    fclose(f);

    printf("Total: %.2f\n", totalSale(s, n));
    printf("Max: %.2f\n", maxSale(s, n));

    free(s);
    return 0;
}
