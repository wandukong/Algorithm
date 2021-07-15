#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int N;
pair<int, int> arr[501];
int dp[501][501];

int goDp(int l, int r)
{
    if (dp[l][r])
        return dp[l][r];
    if (r - l == 1)
        return arr[l].first * arr[l].second * arr[r].second;
    if (l == r)
        return 0;
    dp[l][r] = 987654321;
    for (int i = l; i <= r - 1; i++)
    {
        int L = goDp(l, i);
        int R = goDp(i + 1, r);
        dp[l][r] = min(dp[l][r], L + R + arr[l].first * arr[i].second * arr[r].second);
    }
    return dp[l][r];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    printf("%d", goDp(0, N - 1));
}