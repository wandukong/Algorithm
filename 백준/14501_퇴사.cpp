#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[16];
int dp[16];
int ans = 0;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);

    // 1. 0(n^2) 방법
    // for (int i = 1; i <= N; i++)
    // {
    //     if (arr[i].first + i - 1 > N)
    //         continue;
    //     dp[i] = arr[i].second;
    //     for (int j = 1; j < i; j++)
    //         if (j + arr[j].first <= i && j + arr[j].first <= N)
    //             dp[i] = max(dp[i], dp[j] + arr[i].second);
    // }
    // for (int i = 1; i <= N; i++)
    //     ans = max(dp[i], ans);

    //2. 0(n) 방법
    for (int i = 1; i <= N; i++)
    {
        // 1) i번째 날에 일을 했을 경우
        if (i + arr[i].first <= N + 1)
        {
            dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
            printf(">>> %d %d\n", i + arr[i].first, dp[i + arr[i].first]);
            ans = max(ans, dp[i + arr[i].first]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
        ans = max(ans, dp[i + 1]);
    }
    printf("%d", ans);
    return 0;
}