#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int N, M, parent[1001];
double ans;
vector<pair<int, int>> spaceship;

struct edge
{
    int v1, v2;
    double cost;
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
    priority_queue<edge, vector<edge>, compare> pq;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        spaceship.push_back({a, b});
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
        {
            double c = sqrt(pow(spaceship[i].first - spaceship[j].first, 2) + pow(spaceship[i].second - spaceship[j].second, 2));
            pq.push({i + 1, j + 1, c});
        }
    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        if (!is_merged(e.v1, e.v2))
        {
            ans += e.cost;
            merge(e.v1, e.v2);
        }
    }
    printf("%.2lf", ans);
    return 0;
}