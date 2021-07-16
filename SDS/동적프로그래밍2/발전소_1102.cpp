#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 987654321

int N, K, dp[1 << 17], arr[17][17], cnt[1 << 17], ans = INF;
string s;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    memset(dp, 0x3f, sizeof(dp));
    cin >> s;
    scanf("%d", &K);

    int bit = 0, all = (1 << N);
    for (int i = 0; i < s.size(); i++)
        bit |= (s[i] == 'Y' ? (1 << i) : 0);

    dp[bit] = 0;
    for (int k = 0; k < all; k++)
        for (int i = 0; i < N; i++)
        {
            if (!(k & (1 << i)))
            {
                continue;
            }
            cnt[k]++;
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                dp[k | (1 << j)] = min(dp[k | (1 << j)], dp[k] + arr[i][j]);
            }
        }
    for (int i = 0; i < all; i++)
        if (cnt[i] >= K)
            ans = min(ans, dp[i]);
    printf("%d", ans == INF ? -1 : ans);
    return 0;
}