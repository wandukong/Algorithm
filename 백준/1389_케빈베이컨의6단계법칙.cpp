#include <iostream>
#include <algorithm>

using namespace std;

int N, M, dp[101][101], ansSum = 987654321, ans;
int INF = 987654321;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        dp[a][b] = dp[b][a] = 1;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += dp[i][j];
        if (ansSum > sum)
            ansSum = sum, ans = i;
    }
    printf("%d", ans);
    return 0;
}
