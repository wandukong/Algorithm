#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, M, ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<vector<pii>> v;
vector<bool> check;

int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    check.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    pq.push({0, 1}); // cost, edge
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (check[cur])
            continue;
        check[cur] = true;
        ans += cost;

        for (auto next : v[cur])
            if (!check[next.second])
                pq.push(next);
    }
    printf("%d", ans);
    return 0;
}