#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[21][21], dp[21][21], ansSum = 987654321, ans, cnt;
int INF = 987654321;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &dp[i][j]);
            arr[i][j] = dp[i][j];
        }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++)
                if (j == k || i == k)
                    continue;
                else if (dp[i][j] > dp[i][k] + dp[k][j])
                {
                    printf("-1");
                    return 0;
                }
                else if (dp[i][j] == dp[i][k] + dp[k][j])
                    arr[i][j] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            ans += arr[i][j];
    printf("%d", ans);
    return 0;
}
