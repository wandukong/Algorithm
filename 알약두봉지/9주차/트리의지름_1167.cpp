#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, ans, temp, maxEdge;
vector<vector<pair<int, int>>> tree;
bool check[100001];

void dfs(int edge, int dis)
{
    check[edge] = true;
    for (int i = 0; i < tree[edge].size(); i++)
    {
        auto next = tree[edge][i];
        if (!check[next.first])
        {
            temp += next.second;
            if (ans < temp)
            {
                ans = temp;
                maxEdge = next.first;
            }
            dfs(next.first, temp);
            temp -= next.second;
            check[next.first] = false;
        }
    }
}

int main()
{
    scanf("%d", &N);

    tree.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int edge;
        scanf("%d", &edge);
        while (true)
        {
            int a, b;
            scanf("%d", &a);
            if (a == -1)
                break;
            scanf("%d", &b);
            tree[edge].push_back({a, b});
        }
    }
    dfs(1, 0);
    memset(check, 0, sizeof(check));
    temp = 0;
    dfs(maxEdge, 0);
    printf("%d\n", ans);
    return 0;
}