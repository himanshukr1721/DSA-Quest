#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        long long k = y / x;   // since y % x = 0

        if (k >= 3)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}   