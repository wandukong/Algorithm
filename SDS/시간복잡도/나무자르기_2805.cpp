#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000001], sum, N, M;

int main()
{
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);
    long long left = 0, right = 1000000000, ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2, sum = 0;
        for (int i = 0; i < N; i++)
            if (arr[i] > mid)
                sum += arr[i] - mid;
        if (sum >= M)
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}