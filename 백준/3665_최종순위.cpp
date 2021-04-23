#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int T, N, M, cnt[501], ranking[501], check[501][501];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        vector<vector<int>> v;
        vector<int> ans;
        queue<int> q;
        memset(cnt, 0, sizeof(cnt));
        memset(ranking, 0, sizeof(ranking));
        memset(check, 0, sizeof(check));

        for (int i = 1; i <= N; i++)
            scanf("%d", &ranking[i]);

        for (int i = 1; i <= N; i++)
            for (int j = 1 + i; j <= N; j++)
            {
                check[ranking[i]][ranking[j]] = 1;
                cnt[ranking[j]]++;
            }
        scanf("%d", &M);
        for (int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (check[a][b])
            {
                cnt[b]--;
                cnt[a]++;
            }
            else
            {
                cnt[a]--;
                cnt[b]++;
            }
            swap(check[a][b], check[b][a]);
        }

        for (int i = 1; i <= N; i++)
            if (cnt[i] == 0)
                q.push(i);

        int c = -1;
        for (int i = 0; i < N; i++)
        {
            if (q.empty())
            {
                c = 1;
                break;
            }
            else if (q.size() > 1)
            {
                c = 2;
                break;
            }
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (int j = 1; j <= N; j++)
            {
                if (check[cur][j])
                {
                    cnt[j]--;
                    if (cnt[j] == 0)
                        q.push(j);
                }
            }
        }
        if (c == 1)
            printf("IMPOSSIBLE");
        else if (c == 2)
            printf("?");
        else
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}