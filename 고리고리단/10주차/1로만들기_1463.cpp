#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000005];

int main(void)
{
    scanf("%d", &n);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    printf("%d\n", dp[n]);
}