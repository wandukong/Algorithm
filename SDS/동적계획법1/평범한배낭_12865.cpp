#include <iostream>
#include <algorithm>

using namespace std;

int N, K, ans;
pair<int, int> arr[101];
int dp[101][100001];

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr + N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            if (j - arr[i].first >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
            else
                dp[i][j] = dp[i - 1][j];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    printf("%d", dp[N][K]);
    return 0;
}