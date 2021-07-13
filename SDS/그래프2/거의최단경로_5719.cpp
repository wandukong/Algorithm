#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define pii pair<int, int>

using namespace std;

struct info
{
    int from, to, cost;
};

int T, N, M, S, E;
vector<vector<pii>> v1, v2;
vector<info> v;
bool check[501], route[501][501];
int dp[505];

void dijkstra1()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, S});
    dp[S] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dp[cur] < cost)
            continue;

        for (pii next : v1[cur])
        {
            int nextCost = cost + next.first;
            int nextNode = next.second;
            if (dp[nextNode] <= nextCost)
                continue;
            dp[nextNode] = nextCost;
            pq.push({nextCost, nextNode});
        }
    }
}

void dijkstra2()
{
    queue<int> q;
    dp[S] = 0;
    q.push(E);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (check[cur])
            continue;
        check[cur] = true;
        for (pii next : v2[cur])
        {
            if (dp[cur] == dp[next.second] + next.first) // 현재 방문 지점의 dp값 == 이전의 dp값 + 이전의 cost 값
            {
                q.push({next.second});
                route[next.second][cur] = true;
            }
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0)
            break;
        scanf("%d %d", &S, &E);
        v.clear(), v1.clear(), v2.clear(), v1.resize(N + 1), v2.resize(N + 1), memset(route, 0, sizeof(route)), memset(check, 0, sizeof(check)), memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v1[a].push_back({c, b});
            v2[b].push_back({c, a});
            v.push_back({a, b, c});
        }
        dijkstra1();
        if (dp[E] == dp[504])
        {
            printf("-1\n");
            continue;
        }
        dijkstra2();
        v1.clear(), v1.resize(N + 1), memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < M; i++)
            if (!route[v[i].from][v[i].to]) // 최단 경로 구했을 때, 방문했던 경로가 아닐 때
                v1[v[i].from].push_back({v[i].cost, v[i].to});
        dijkstra1();
        if (dp[E] == dp[504])
            printf("-1\n");
        else
            printf("%d\n", dp[E]);
    }
    return 0;
}