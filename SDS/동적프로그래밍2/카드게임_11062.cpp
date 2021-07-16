#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, T, dp[1001][1001], arr[1001];

int goDp(int l, int r)
{
    if (r - l < 0)
        return 0;
    if (dp[l][r])
        return dp[l][r];
    if (r - l <= 1)
        return dp[l][r] = max(arr[l], arr[r]);

    dp[l][r] = arr[l] + min(goDp(l + 2, r), goDp(l + 1, r - 1));
    dp[l][r] = max(dp[l][r], arr[r] + min(goDp(l, r - 2), goDp(l + 1, r - 1)));
    return dp[l][r];
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        memset(dp, 0, sizeof(dp));
        printf("%d\n", goDp(0, N - 1));
    }
    return 0;
}