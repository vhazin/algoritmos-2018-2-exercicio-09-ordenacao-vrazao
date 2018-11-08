#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    unsigned long long generations;
    scanf("%llu", &generations);
    srand(time(NULL));

    printf("%llu\n", generations);
    while (generations--)
    {
        printf("%d\n", rand() % RAND_MAX);
    }
    return 0;
}