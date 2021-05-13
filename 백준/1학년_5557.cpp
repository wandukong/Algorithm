#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[102];
long long dp[102][21];

int main()
{

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    dp[1][arr[1]] = 1;

    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j])
            {
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] += dp[i - 1][j];
                if (j + arr[i] <= 20)
                    dp[i][j + arr[i]] += dp[i - 1][j];
            }
        }
    }
    printf("%lld", dp[N - 1][arr[N]]);
    return 0;
}