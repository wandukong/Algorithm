
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K, sum, ans;
int dp[100001];
int route[100001];

void dijkstra(int cur)
{
    dp[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;

        if (cost > dp[cur])
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nextCost = cost + v[cur][i].second;

            if (nextCost < dp[next])
            {

                dp[next] = nextCost;
                pq.push({nextCost, next});
                path[next] = cur;
            }
        }
    }
}

int main()
{

    int s, e;
    vector<int> ans;

    for (int i = e; i != s; i = route[i])
        ans.push_back(i);
    ans.push_back(s);
    return 0;
}