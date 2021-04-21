#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, m1, m2;
long long ans1, ans2;
vector<vector<pair<int, int>>> v;
long long dp[801];

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
            }
        }
    }
}

void initDp()
{
    for (int i = 1; i <= N; i++)
        dp[i] = 987654321;
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
        v[b].push_back({a, c});
    }
    scanf("%d %d", &m1, &m2);

    initDp();
    dijkstra(1);
    ans1 += dp[m1];

    initDp();
    dijkstra(m1);
    ans1 += dp[m2];

    initDp();
    dijkstra(m2);
    ans1 += dp[N];

    initDp();
    dijkstra(1);
    ans2 += dp[m2];

    initDp();
    dijkstra(m2);
    ans2 += dp[m1];

    initDp();
    dijkstra(m1);
    ans2 += dp[N];

    if (min(ans1, ans2) >= 987654321)
        printf("-1");
    else
        printf("%lld", min(ans1, ans2));

    return 0;
}