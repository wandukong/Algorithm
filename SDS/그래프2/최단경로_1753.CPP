#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define pii pair<int, int>

using namespace std;

int N, M, start;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<vector<pii>> v;
int dp[20005];

void dijkstra()
{
    pq.push({0, start});
    dp[start] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dp[cur] < cost)
            continue;

        for (pii next : v[cur])
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

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d", &start);
    v.resize(N + 1);
    memset(dp, 0x3f, sizeof(dp)); // 약 10억6천(1061109567)으로 초기화됨.
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c, b});
    }
    dijkstra();
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == dp[20004])
            printf("INF\n");
        else
            printf("%d\n", dp[i]);
    }
    return 0;
}