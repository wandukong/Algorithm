#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define PIVOT 17 // 2^17 >= N

int N, M, parent[PIVOT][100001], depth[100001];
vector<vector<int>> tree;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1}); // ��Ʈ��� 1
    depth[1] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        for (auto next : tree[cur])
        {
            if (!depth[next])
            {
                depth[next] = d + 1;
                parent[0][next] = cur; // �θ� ��� ����
                q.push({next, d + 1});
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] > depth[b]) // �׻� b�� �� ũ��
        swap(a, b);
    int diff = depth[b] - depth[a];
    for (int i = 0; i < PIVOT; i++) // ���� ���̷� ����
    {
        int bit = (1 << i);
        if ((diff & bit) == bit)
            b = parent[i][b];
    }
    if (a == b) // a �� �ٷ� lca �̹Ƿ� ����
        return a;
    for (int i = PIVOT - 1; i >= 0; i--) // pivot�� ū ��� �Ѵ� 0�� ���� �����Ƿ� ���ǹ� false
        if (parent[i][a] != parent[i][b])
            a = parent[i][a], b = parent[i][b];
    return parent[0][a];
}

int main()
{
    // https://www.acmicpc.net/problem/11438
    scanf("%d", &N);
    tree.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bfs();
    //parent[0][j] : 1����, parent[1][j] : 2����, parent[2][j] : 4����. parent[i][j] : i^2 ����
    for (int i = 1; i < PIVOT; i++)
        for (int j = 1; j <= N; j++)
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
    scanf("%d", &M);
    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
