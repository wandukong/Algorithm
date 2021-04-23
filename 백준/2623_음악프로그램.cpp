#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt[1001];
vector<vector<int>> v;
queue<int> q;
vector<int> ans;

int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d", &a);
        scanf("%d", &b);
        for (int j = 1; j < a; j++)
        {
            scanf("%d", &c);
            v[b].push_back(c);
            cnt[c]++;
            b = c;
        }
    }
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);
        for (int i = 0; i < v[cur].size(); i++)
            if (--cnt[v[cur][i]] == 0)
                q.push(v[cur][i]);
    }
    for (int i = 1; i <= N; i++)
        if (cnt[i] != 0)
        {
            printf("0");
            return 0;
        }

    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}