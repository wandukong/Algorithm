#include <iostream>
#include <algorithm>

using namespace std;

int T, k, n, ans;
int dp[15][15];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &k, &n);

        for (int i = 1; i <= n; i++)
            dp[0][i] = i;

        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        printf("%d\n", dp[k][n]);
    }
    return 0;
}