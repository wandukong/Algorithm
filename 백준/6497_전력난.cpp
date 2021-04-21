#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int parent[200001];
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

bool is_merged(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    while (true)
    {
        int N, M, ans = 0;
        priority_queue<edge, vector<edge>, compare> pq;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0)
            break;

        for (int i = 0; i < N; i++)
            parent[i] = i;
        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            pq.push({a, b, c});
            ans += c;
        }
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            if (!is_merged(v.v1, v.v2))
            {
                ans -= v.cost;
                merge(v.v1, v.v2);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}