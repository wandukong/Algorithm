#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int V, E, parent[10001], ans;

struct edge
{
    int v1, v2, cost;
};

struct compare
{
    bool operator()(edge a, edge b)
    {
        return a.cost > b.cost;
    }
};

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void merge(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a < b)
        swap(a, b);
    parent[b] = a;
}

bool is_meraged(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    scanf("%d %d", &V, &E);
    priority_queue<edge, vector<edge>, compare> pq;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        pq.push({a, b, c});
    }
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!is_meraged(v.v1, v.v2))
        {
            ans += v.cost;
            merge(v.v1, v.v2);
        }
    }
    printf("%d", ans);
    return 0;
}