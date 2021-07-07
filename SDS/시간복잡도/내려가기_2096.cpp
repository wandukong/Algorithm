#include <iostream>
#include <algorithm>

using namespace std;

int dp[4][3], N;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (i == 0)
        {
            dp[0][0] = a, dp[0][1] = b, dp[0][2] = c;
            dp[2][0] = a, dp[2][1] = b, dp[2][2] = c;
            dp[3][0] = dp[3][1] = dp[3][2] = 10; // ÃÊ±âÈ­
        }
        else
        {
            dp[1][0] = max(dp[0][0], dp[0][1]) + a;
            dp[1][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + b;
            dp[1][2] = max(dp[0][1], dp[0][2]) + c;

            dp[0][0] = dp[1][0], dp[0][1] = dp[1][1], dp[0][2] = dp[1][2];

            dp[3][0] = min(dp[2][0], dp[2][1]) + a;
            dp[3][1] = min(dp[2][0], min(dp[2][1], dp[2][2])) + b;
            dp[3][2] = min(dp[2][1], dp[2][2]) + c;

            dp[2][0] = dp[3][0], dp[2][1] = dp[3][1], dp[2][2] = dp[3][2];
        }
    }
    int ans1 = max(dp[0][0], max(dp[0][1], dp[0][2]));
    int ans2 = min(dp[2][0], min(dp[2][1], dp[2][2]));
    printf("%d %d", ans1, ans2);
    return 0;
}