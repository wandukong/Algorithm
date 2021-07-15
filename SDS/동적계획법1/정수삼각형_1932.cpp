#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[501][501], dp[501][501];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &arr[i][j]);
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]);
    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[N][i]);
    printf("%d", ans);
    return 0;
}