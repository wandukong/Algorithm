#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, parent[100001], ans;
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;

struct info
{
    int v1, v2, cost;
};

struct compare
{
    bool operator()(info a, info b)
    {
        return a.cost > b.cost;
    }
};

priority_queue<info, vector<info>, compare> pq;

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void merge(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a > b)
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
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 0; i < N - 1; i++)
    {
        pq.push({x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)});
        pq.push({y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)});
        pq.push({z[i].second, z[i + 1].second, abs(z[i].first - z[i + 1].first)});
    }
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if (!is_merged(temp.v1, temp.v2))
        {
            ans += temp.cost;
            merge(temp.v1, temp.v2);
        }
    }
    printf("%d", ans);
    return 0;
}