#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, n, d, c, a, b, s, cnt, ans;
int dp[10001];

vector<vector<pair<int, int>>> v;

void dijkstra(int cur)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, cur});
    dp[cur] = 0;

    while (!q.empty())
    {
        cur = q.top().second;
        int cost = q.top().first;
        q.pop();

        if (cost > dp[cur])
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {

            int next = v[cur][i].first;
            int nextCost = cost + v[cur][i].second;

            if (dp[next] > nextCost)
            {
                dp[next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &d, &c);
        v.clear();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 987654321;
        }

        for (int i = 0; i < d; i++)
        {
            scanf("%d %d %d", &a, &b, &s);
            v[b].push_back({a, s});
        }
        dijkstra(c);
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] != 987654321)
            {
                cnt++;
                ans = max(ans, dp[i]);
            }
        }
        printf("%d %d\n", cnt, ans);
        cnt = ans = 0;
    }
    return 0;
}