#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N;
vector<vector<int>> graph;
int check[30];

void preOrder(int n)
{
    check[n] = 1;
    printf("%c", n + 65);
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (graph[n][i] == -1)
            continue;
        if (!check[graph[n][i]])
            preOrder(graph[n][i]);
    }
}
void postOrder(int n)
{
    check[n] = 1;
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (graph[n][i] == -1)
            continue;
        if (!check[graph[n][i]])
            postOrder(graph[n][i]);
    }
    printf("%c", n + 65);
}
void innerOrder(int n)
{
    check[n] = 1;
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (i == 1)
            printf("%c", n + 65);
        if (graph[n][i] == -1)
            continue;
        if (!check[graph[n][i]])
            innerOrder(graph[n][i]);
    }
}

int main()
{
    scanf("%d", &N);
    graph.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        int node, child;
        for (int j = 0; j < 3; j++)
        {
            char a;
            cin >> a;
            if (j == 0)
            {
                node = a - 65;
                continue;
            }
            if (a == '.')
                graph[node].push_back(-1);
            else
            {
                child = a - 65;
                graph[node].push_back(child);
            }
        }
    }
    preOrder(0);
    printf("\n");
    memset(check, 0, sizeof(check));
    innerOrder(0);
    printf("\n");
    memset(check, 0, sizeof(check));
    postOrder(0);
    return 0;
}