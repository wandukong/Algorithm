#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define PIVOT 14
using namespace std;

int T, N, a, b, indegree[10001], parent[PIVOT][10001], depth[10001];
vector<vector<int>> tree;

void bfs(int cur)
{
    queue<pair<int, int>> q;
    q.push({cur, 1});
    depth[cur] = 1;
    while (!q.empty())
    {
        cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int next : tree[cur])
        {
            if (!depth[next])
            {
                parent[0][next] = cur;
                depth[next] = cnt + 1;
                q.push({next, cnt + 1});
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);
    int diff = depth[b] - depth[a];
    for (int i = 0; i < PIVOT; i++)
    {
        int bit = (1 << i);
        if ((diff & bit) == bit)
            b = parent[i][b];
    }
    if (a == b)
        return a;
    for (int i = PIVOT - 1; i >= 0; i--)
        if (parent[i][a] != parent[i][b])
            a = parent[i][a], b = parent[i][b];
    return parent[0][a];
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        tree.resize(N + 1);
        for (int i = 1; i < N; i++)
        {
            scanf("%d %d", &a, &b);
            tree[a].push_back(b);
            indegree[b]++;
        }
        for (int i = 1; i <= N; i++)
        {
            if (!indegree[i])
            {
                bfs(i);
                break;
            }
        }
        for (int i = 1; i < PIVOT; i++)
            for (int j = 1; j <= N; j++)
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
        tree.clear(), memset(parent, 0, sizeof(parent)), memset(depth, 0, sizeof(depth)), memset(indegree, 0, sizeof(indegree));
    }
    return 0;
}