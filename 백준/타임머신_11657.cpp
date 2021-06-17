#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
struct info
{
    int cur, next, cost;
};
vector<info> edge;
long long dist[501];

bool bellmanford(int cur)
{
    dist[cur] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
        {
            int cur = edge[j].cur;
            int next = edge[j].next;
            int cost = edge[j].cost;
            if (dist[cur] != 1e9 && dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
                if (i == N)
                    return false;
            }
        }
    return true;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back({a, b, c});
    }
    for (int i = 1; i <= N; i++)
        dist[i] = 1e9;

    if (!bellmanford(1))
        printf("-1\n");
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == 1e9)
                printf("-1\n");
            else
                printf("%lld\n", dist[i]);
        }
    }
    return 0;
}
