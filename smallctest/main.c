#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{    
    printf("%d\n", 8 * sizeof(long long int));

    int x = 7;

    int y = x > 3 ? 1 : 2;
    // y = 1

    return 0;
}
