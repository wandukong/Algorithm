#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, arr[1002][1002], line = 0;
vector<vector<int>> graph;
vector<int> ans;

bool dfs(int edge, int cnt)
{
    ans.push_back(edge);
    if (cnt == line / 2)
        if (edge == 1)
            return true;
        else
            return false;

    for (int i = 0; i < graph[edge].size(); i++)
    {
        int next = graph[edge][i];
        if (arr[edge][next] > 0)
        {
            arr[edge][next] -= 1;
            arr[next][edge] -= 1;
            if (dfs(next, cnt + 1))
                return true;
            ans.erase(ans.end() - 1);
            arr[edge][next] += 1;
            arr[next][edge] += 1;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int temp = 0;
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j])
            {
                graph[i].push_back(j);
                temp += arr[i][j];
            }
        }
        line += temp;
        if (temp % 2)
        {
            printf("-1");
            return 0;
        }
    }
    dfs(1, 0);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}
