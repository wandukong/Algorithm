#include <string>
#include <vector>

using namespace std;

int N;
long long dp[100001];

int main()
{
    scanf("%d", &N);
    dp[1] = 3, dp[2] = 7;
    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 1] % 9901 * 2 + dp[i - 2] % 9901) % 9901;

    printf("%lld\n", dp[N]);
    return 0;
}