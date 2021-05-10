
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, sum, ans;
int dp[101][101];

int main()
{
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = 987654321;

    for (int i = 0; i < K; i++)
    {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, cost);
        dp[a][b] = dp[b][a] = cost; // cost
    }

    for (int k = 0; k < N; k++)
        for (int i = 1; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    return 0;
}