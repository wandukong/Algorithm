#include <iostream>
#include <algorithm>

using namespace std;

int dp[401][401];

int main()
{
    int n, k, s, a, b;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        dp[a][b] = -1;
        dp[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][j] == 0)
                {
                    if (dp[i][k] == -1 && dp[k][j] == -1)
                        dp[i][j] = -1;
                    else if (dp[i][k] == 1 && dp[k][j] == 1)
                        dp[i][j] = 1;
                }
            }
    scanf("%d", &s);
    while (s--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
    return 0;
}
