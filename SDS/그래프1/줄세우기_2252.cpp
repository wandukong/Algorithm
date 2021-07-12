#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, indegree[32001];
vector<vector<int>> v;
queue<int> q;

int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        indegree[b]++;
        v[a].push_back(b);
    }
    for (int i = 1; i <= N; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int node : v[cur])
            if (--indegree[node] == 0)
                q.push(node);
    }
    return 0;
}