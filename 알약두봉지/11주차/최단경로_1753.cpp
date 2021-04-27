#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V, E, K, INF = 987654321;
vector<vector<pair<int, int>>> vertex;
int dp[20001];

void dijkstra(int cur)
{
    dp[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});
    while (!pq.empty())
    {
        cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (cost > dp[cur])
            continue;
        for (int i = 0; i < vertex[cur].size(); i++)
        {
            int nextCost = cost + vertex[cur][i].second;
            int nextVertex = vertex[cur][i].first;

            if (nextCost < dp[nextVertex])
            {
                dp[nextVertex] = nextCost;
                pq.push({nextCost, nextVertex});
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &V, &E, &K);

    vertex.resize(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        vertex[u].push_back({v, w});
    }
    for (int i = 1; i <= V; i++)
        dp[i] = INF;
    dijkstra(K);
    for (int i = 1; i <= V; i++)
        if (dp[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dp[i]);

    return 0;
}