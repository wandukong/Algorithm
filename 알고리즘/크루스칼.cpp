
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int parent[100001], ans, N, M;

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

int get(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = get(parent[x]);
}

void set(int a, int b)
{
    a = get(a), b = get(b);
    if (a > b)
        swap(a, b);
    parent[a] = b;
}

bool is_set(int a, int b)
{
    a = get(a), b = get(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    priority_queue<edge, vector<edge>, compare> pq;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        pq.push({a, b, c});
    }

    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        if (!is_set(e.v1, e.v2))
        {
            set(e.v1, e.v2);
            ans += e.cost;
        }
    }

    return 0;
}