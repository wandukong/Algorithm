#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[301], dp[301][2];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    dp[1][0] = dp[1][1] = arr[1];
    // dp[i][0] : 한칸 왔을 때 최대
    // dp[i][1] : 두칸 왔을 때 최대
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1] + arr[i];
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + arr[i];
    }
    printf("%d", max(dp[N][0], dp[N][1]));
    return 0;
}