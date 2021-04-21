#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, arr[1001], dp[1001], ans[1001], ansValue;
vector<vector<pair<int, int>>> v;

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

            if (dp[next] > nextCost)
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
    scanf("%d %d %d", &N, &M, &X);
    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }

    for (int i = 1; i <= N; i++)
    {
        initDp();
        if (X == i)
            continue;
        dijkstra(i);
        ans[i] = dp[X];
    }
    initDp();
    dijkstra(X);
    for (int i = 1; i <= N; i++)
    {
        if (X == i)
            continue;
        ans[i] += dp[i];
        ansValue = max(ansValue, ans[i]);
    }
    printf("%d", ansValue);
    return 0;
}