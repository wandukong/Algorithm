#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, s, e;
vector<vector<pair<int, int>>> v;
vector<int> ans;
int dp[1001];
int route[1001];

void dijkstra(int cur)
{
    dp[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (cost > dp[cur])
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nextCost = cost + v[cur][i].second;
            if (nextCost < dp[next])
            {
                dp[next] = nextCost;
                pq.push({nextCost, next});
                route[next] = cur;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    scanf("%d %d", &s, &e);

    for (int i = 1; i <= N; i++)
        dp[i] = 987654321;
    dijkstra(s);
    for (int i = e; i != s; i = route[i])
        ans.push_back(i);
    ans.push_back(s);

    printf("%d\n", dp[e]);
    printf("%d\n", ans.size());
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%d ", ans[i]);

    return 0;
}