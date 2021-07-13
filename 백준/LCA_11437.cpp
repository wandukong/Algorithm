#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, parent[50001], depth[50001];
bool check[50001];
vector<vector<int>> v;

void dfs(int x, int d)
{
    check[x] = true;
    depth[x] = d;

    for (auto next : v[x])
        if (!check[next])
        {
            parent[next] = x;
            dfs(next, d + 1);
        }
}

int lca(int a, int b)
{
    while (depth[a] != depth[b]) // ���̰� ������ ������
    {
        if (depth[a] < depth[b])
            b = parent[b];
        else
            a = parent[a];
    }
    while (a != b) // ���̰� ��������, ���� ���� ������ ã�´�.
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    scanf("%d", &N);
    v.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &M);
    dfs(1, 0); // ��Ʈ ��� 1
    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
