#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, E;
vector<vector<int>> tree;
vector<int> v;
bool check[50];

void dfs(int e)
{
    check[e] = true;
    for (int i = 0; i < tree[e].size(); i++)
    {
        if (!check[tree[e][i]])
        {
            v.push_back(tree[e][i]);
            check[tree[e][i]] = true;
            dfs(tree[e][i]);
        }
    }
}

int main()
{
    scanf("%d", &N);
    tree.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == -1)
            continue;
        tree[a].push_back(i);
    }
    scanf("%d", &E);
    dfs(E);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            if (check[tree[i][j]])
                tree[i].erase(tree[i].begin() + j);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (check[i])
            continue;
        if (tree[i].size() > 0)
            continue;
        ans++;
    }
    printf("%d", ans);
    return 0;
}