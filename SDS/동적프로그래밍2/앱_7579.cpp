#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, dp[2][10000001];
pair<int, int> arr[101];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i].first);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i].second);
    sort(arr + 1, arr + N + 1, greater<pair<int, int>>());
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= M; i++)
        if (i <= arr[1].first)
            dp[0][i] = arr[1].second;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j <= arr[i].first)
                dp[1][j] = min(dp[0][j], arr[i].second);
            else
                dp[1][j] = min(dp[0][j], dp[0][j - arr[i].first] + arr[i].second);
        }
        copy(dp[1], dp[1] + M + 1, dp[0]);
    }
    printf("%d", dp[0][M]);
    return 0;
}