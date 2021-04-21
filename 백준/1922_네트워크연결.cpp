#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

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

int N, M, parent[1001], ans;

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

bool is_merged(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    scanf("%d %d", &N, &M);
    priority_queue<edge, vector<edge>, compare> pq;
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        pq.push({a, b, c});
    }
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!is_merged(v.v1, v.v2))
        {
            ans += v.cost;
            merge(v.v1, v.v2);
        }
    }
    printf("%d", ans);
    return 0;
}