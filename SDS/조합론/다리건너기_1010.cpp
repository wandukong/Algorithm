#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N, K, T, dp[1001][1001];

int main()
{
    scanf("%d", &T);
    for (int i = 0; i <= 30; i++)
        dp[i][0] = dp[i][i] = 1;
    for (int i = 1; i <= 30; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    while (T--)
    {
        scanf("%d %d", &K, &N);
        printf("%d\n", dp[N][K]);
    }
    return 0;
}
