#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long dp[100], N;

long long fibo(long long num)
{
    if (dp[num] != -1)
        return dp[num];
    return dp[num] = fibo(num - 1) + fibo(num - 2);
}

int main()
{
    scanf("%lld", &N);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0, dp[1] = dp[2] = 1;
    fibo(N);
    printf("%lld", dp[N]);
    return 0;
}