#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[1000001];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        dp[i] = 9999999;
    dp[1] = 0;
    dp[2] = dp[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        int temp = dp[i - 1] + 1;
        if (i % 3 == 0)
            temp = min(temp, dp[i / 3] + 1);
        if (i % 2 == 0)
            temp = min(temp, dp[i / 2] + 1);
        dp[i] = temp;
    }
    printf("%d", dp[N]);
}