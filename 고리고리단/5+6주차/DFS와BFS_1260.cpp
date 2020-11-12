#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int N, M, S, ans;
int check[1001];
vector<vector<int>> v;

void dfs(int cur)
{
    printf("%d ", cur);
    check[cur] = 1;
    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (!check[next])
            dfs(next);
    }
    return;
}

void bfs(int cur)
{
    queue<int> q;
    q.push(cur);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (!check[cur])
            printf("%d ", cur);
        check[cur] = 1;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!check[next])
                q.push(next);
        }
    }
    return;
}

int main()
{
    scanf("%d %d %d", &N, &M, &S);

    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end());
    dfs(S);
    printf("\n");
    memset(check, 0, sizeof(check));
    bfs(S);

    return 0;
}