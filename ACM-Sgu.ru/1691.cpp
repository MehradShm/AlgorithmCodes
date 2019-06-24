#include <stdio.h>

int main(void) {
    int k;
    scanf ("%d", &k);
    if (k == 1) {
        printf ("8\n");
        return 0;
    }
    int count = 1;
    if ((k-1)%3==0) {
        count += 2;
        if ((k-1)%6==0) {
            count++;
        }
    }
    printf ("%d\n", count);
    return 0;
}

