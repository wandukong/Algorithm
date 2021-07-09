#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N, K, dp[1001][1001];

int nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % 10007;
}

int main()
{
    scanf("%d %d", &N, &K);
    //规过 1
    memset(dp, -1, sizeof(dp));
    printf("%d", nCr(N, K));

    //规过 2
    for (int i = 0; i <= N; i++)
        dp[i][0] = dp[i][i] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
    printf("%d", dp[N][K] % 10007);
    return 0;
}
