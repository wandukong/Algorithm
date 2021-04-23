#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, cost[501], sum[501], cnt[501];
vector<vector<int>> v;
queue<pair<int, int>> q;

int main()
{
    scanf("%d", &N);
    v.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &cost[i]);
        while (true)
        {
            int a;
            scanf("%d", &a);
            if (a == -1)
                break;
            v[a].push_back(i);
            cnt[i]++;
        }
    }
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 0)
        {
            q.push({i, cost[i]});
            sum[i] = cost[i];
        }
    while (!q.empty())
    {
        int cur = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            sum[v[cur][i]] = max(sum[v[cur][i]], c + cost[v[cur][i]]);
            if (--cnt[v[cur][i]] == 0)
                q.push({v[cur][i], sum[v[cur][i]]});
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", sum[i]);
    return 0;
}