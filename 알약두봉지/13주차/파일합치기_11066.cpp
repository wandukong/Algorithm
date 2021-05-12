#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

int T, N, sum[501], arr[501], dp[501][501];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int d = 1; d < N; d++)
        {
            for (int start = 1; start + d <= N; start++)
            {
                int end = start + d;
                dp[start][end] = INF;
                for (int mid = start; mid < end; mid++)
                {
                    printf("%d %d %d %d \n", start, mid, end, d);
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
                }
            }
        }
        printf("%d\n", dp[1][N]);
    }
    return 0;
}