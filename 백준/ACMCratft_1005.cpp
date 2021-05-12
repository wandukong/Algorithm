#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int T, N, K, W, X, Y;
int arr[1001];
int cnt[1001];
int temp[1001];

int main()
{
    scanf("%d", &T);
    while (T--)
    {

        vector<vector<int>> v;
        queue<pair<int, int>> q;
        int ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(temp, 0, sizeof(temp));

        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);

        v.resize(N + 1);

        for (int i = 0; i < K; i++)
        {
            scanf("%d %d", &X, &Y);
            v[X].push_back(Y);
            cnt[Y]++;
        }
        scanf("%d", &W);

        for (int i = 1; i <= N; i++)
            if (cnt[i] == 0)
                q.push({i, arr[i]});

        while (!q.empty())
        {
            int cur = q.front().first;
            int cost = q.front().second;
            q.pop();

            if (cur == W)
                ans = max(cost, ans);

            for (int i = 0; i < v[cur].size(); i++)
            {
                temp[v[cur][i]] = max(temp[v[cur][i]], cost + arr[v[cur][i]]);
                if (--cnt[v[cur][i]] == 0)
                {
                    q.push({v[cur][i], temp[v[cur][i]]});
                    printf(">> %d %d\n", v[cur][i], temp[v[cur][i]]);
                }
            }
        }
        printf("ans : %d\n", ans);
    }
    return 0;
}