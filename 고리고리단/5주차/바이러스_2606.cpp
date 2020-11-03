#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M, ans;
int check[101];
vector<vector<int>> v;

void dfs(int cur)
{
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
        check[cur] = 1;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!check[next])
                q.push(next);
        }
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);

    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    //bfs(1);

    for (int i = 2; i <= N; i++)
        if (check[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}