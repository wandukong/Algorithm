#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int T, N, M, W;
struct info
{
    int cur, next, cost;
};
vector<info> edge;
int dist[501];

bool bellmanFord(int cur)
{
    dist[cur] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int cur = edge[j].cur;
            int next = edge[j].next;
            int cost = edge[j].cost;
            if (dist[cur] != 1e9 && dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
                if (i == N)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &N, &M, &W);
        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edge.push_back({a, b, c});
            edge.push_back({b, a, c});
        }
        for (int i = 0; i < W; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edge.push_back({a, b, c * -1});
        }
        for (int i = 1; i <= N; i++)
            dist[i] = 1e9;
        if (bellmanFord(1))
            printf("YES\n");
        else
            printf("NO\n");
        memset(dist, 0, sizeof(dist));
        edge.clear();
    }
    return 0;
}
