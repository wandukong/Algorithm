#include <iostream>
#include <algorithm>

using namespace std;

long long X, Y, Z, ans = 1000000000;

int main()
{
    scanf("%lld %lld", &X, &Y);
    Z = Y * 100 / X;
    if (Z == 100 || Z == 99)
    {
        printf("-1");
        return 0;
    }
    long long left = 1, right = 1000000000, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long newZ = (Y + mid) * 100 / (X + mid);
        if (newZ > Z)
        {
            ans = min(mid, ans);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    printf("%lld", ans);
    return 0;
}