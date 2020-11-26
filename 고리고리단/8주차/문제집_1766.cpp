#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> q;
vector<vector<int>> v;
int indegree[32001];

int main()
{
    scanf("%d %d", &N, &M);

    v.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++)
        if (!indegree[i])
            q.push(i);

    while (!q.empty())
    {
        int cur = q.top();
        printf("%d ", cur);
        q.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            indegree[next]--;
            if (!indegree[next])
                q.push(next);
        }
    }

    return 0;
}