
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, sum, ans;
int arr[100001];
int indegree[100001];

int main()
{

    for (int i = 0; i < K; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        grapth[a].push_back(b);
        arr[b]++;
    }

    for (int i = 1; i <= N; i++)
        if (arr[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (--indegree[next] == 0)
                q.pusth(next);
        }
    }
    return 0;
}