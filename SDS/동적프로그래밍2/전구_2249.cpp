#include <iostream>
#include <algorithm>

using namespace std;

int N, K, dp[201][201], arr[201];

int goDp(int l, int r)
{
    if (dp[l][r])
        return dp[l][r];
    if (r - l <= 1)
        return dp[l][r] = (arr[l] == arr[r] ? 0 : 1);
    dp[l][r] = 987654321;
    for (int i = l; i <= r - 1; i++)
        dp[l][r] = min(dp[l][r], goDp(l, i) + goDp(i + 1, r) + (arr[l] == arr[i + 1] ? 0 : 1));
    return dp[l][r];
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", goDp(0, N - 1));
    return 0;
}