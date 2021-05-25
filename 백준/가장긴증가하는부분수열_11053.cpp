#include <string>
#include <vector>

using namespace std;

int N, arr[1002], dp[1002], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}