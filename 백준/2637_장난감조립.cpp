#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, Y, K, cnt[101], dp[101][101];
vector<vector<pair<int, int>>> v;
queue<int> q;
vector<int> ans;

int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &X, &Y, &K);
        v[Y].push_back({X, K});
        cnt[X]++;
    }
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 0)
        {
            q.push(i);
            dp[i][i] = 1;
        }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int cost = v[cur][i].second;
            if (--cnt[next] == 0)
                q.push(next);
            for (int j = 1; j <= N; j++)
                dp[next][j] += cost * dp[cur][j];
        }
    }
    for (int i = 1; i <= N; i++)
        if (dp[N][i] != 0)
            printf("%d %d\n", i, dp[N][i]);
    return 0;
}