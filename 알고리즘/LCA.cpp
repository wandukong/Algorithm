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
    q.push({1, 1}); // 루트노드 1
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
                parent[0][next] = cur; // 부모 노드 저장
                q.push({next, d + 1});
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] > depth[b]) // 항상 b가 더 크게
        swap(a, b);
    int diff = depth[b] - depth[a];
    for (int i = 0; i < PIVOT; i++) // 같은 깊이로 수정
    {
        int bit = (1 << i);
        if ((diff & bit) == bit)
            b = parent[i][b];
    }
    if (a == b) // a 가 바로 lca 이므로 리턴
        return a;
    for (int i = PIVOT - 1; i >= 0; i--) // pivot이 큰 경우 둘다 0이 값을 가지므로 조건문 false
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
    //parent[0][j] : 1조상, parent[1][j] : 2조상, parent[2][j] : 4조상. parent[i][j] : i^2 조상
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
