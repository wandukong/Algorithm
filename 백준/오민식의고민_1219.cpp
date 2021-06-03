#include <iostream>
#include <algorithm>
#define INF 1LL << 40
using namespace std;

int N, S, E, M;
struct info
{
    int v1, v2, cost;
};
info edge[101];
int earning[101];
long long dist[101];

void bellmanFord(int cur)
{
    dist[cur] = earning[cur];
    for (int i = 0; i < N + 100; i++)
        for (int j = 0; j < M; j++)
        {
            int cur = edge[j].v1;
            int next = edge[j].v2;
            int cost = edge[j].cost;
            if (dist[cur] == -INF)
                continue;
            if (dist[cur] == INF)
                dist[next] = INF;
            if (dist[next] < dist[cur] + earning[edge[j].v2] + edge[j].cost)
            {
                dist[next] = dist[cur] + earning[edge[j].v2] + edge[j].cost;
                if (i >= N - 1)
                    dist[next] = INF;
            }
        }
}

int main()
{
    scanf("%d %d %d %d", &N, &S, &E, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &edge[i].v1, &edge[i].v2, &edge[i].cost);
        edge[i].cost *= -1;
    }
    for (int i = 0; i < N; i++)
    {
        dist[i] = -INF;
        scanf("%d", &earning[i]);
    }
    bellmanFord(S);
    if (dist[E] == -INF)
        printf("gg");
    else if (dist[E] == INF)
        printf("Gee");
    else
        printf("%lld", dist[E]);
    return 0;
}