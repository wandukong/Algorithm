#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001];
int N;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        dp[i] = 2000;

    dp[3] = dp[5] = 1;

    for (int i = 6; i <= N; i++)
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;

    if (dp[N] >= 2000)
        printf("-1");
    else
        printf("%d", dp[N]);
}