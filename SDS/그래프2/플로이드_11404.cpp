#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int dp[101][101];

int main()
{
    scanf("%d %d", &N, &M);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= N; i++)
        dp[i][i] = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dp[a][b] = min(dp[a][b], c);
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%d ", dp[i][j] == dp[0][0] ? 0 : dp[i][j]);
        printf("\n");
    }
    return 0;
}