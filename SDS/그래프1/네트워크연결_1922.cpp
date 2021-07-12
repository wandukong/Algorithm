#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, indegree[32001], parent[32001], ans;

struct edge
{
    int from, to, price;
};

struct comp
{
    bool operator()(edge a, edge b)
    {
        return a.price > b.price;
    }
};

priority_queue<edge, vector<edge>, comp> pq;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void set(int a, int b)
{
    a = find(a), b = find(b);
    if (a > b)
        swap(a, b);
    parent[b] = a;
}
bool check(int a, int b)
{
    a = find(a), b = find(b);
    return a == b;
}

int main()
{
    scanf("%d %d", &N, &M);
    while (M--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        pq.push({a, b, c});
    }
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        if (!check(e.from, e.to))
        {
            ans += e.price;
            set(e.from, e.to);
        }
    }
    printf("%d", ans);
    return 0;
}