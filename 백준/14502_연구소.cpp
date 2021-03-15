#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M, ans;
int arr[9][9];
int temp[9][9];
bool check[9][9];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
vector<pair<int, int>> v;

void dfs(int r, int c)
{
    check[r][c] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nc >= M || nr >= N || temp[nr][nc] != 0)
            continue;
        if (!check[nr][nc])
        {
            temp[nr][nc] = 2;
            dfs(nr, nc);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2)
                v.push_back({i, j});
        }

    for (int w1 = 0; w1 < N * M - 2; w1++)
        for (int w2 = w1 + 1; w2 < N * M - 1; w2++)
            for (int w3 = w2 + 1; w3 < N * M; w3++)
            {
                if (arr[w1 / M][w1 % M] != 0 || arr[w2 / M][w2 % M] != 0 || arr[w3 / M][w3 % M] != 0)
                    continue;
                arr[w1 / M][w1 % M] = 1;
                arr[w2 / M][w2 % M] = 1;
                arr[w3 / M][w3 % M] = 1;

                memcpy(temp, arr, sizeof(arr));
                for (int i = 0; i < v.size(); i++)
                    dfs(v[i].first, v[i].second);

                int sum = 0;
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < M; j++)
                        if (temp[i][j] == 0)
                            sum++;
                ans = max(sum, ans);
                memset(check, 0, sizeof(check));
                arr[w1 / M][w1 % M] = 0;
                arr[w2 / M][w2 % M] = 0;
                arr[w3 / M][w3 % M] = 0;
            }
    printf("%d", ans);
    return 0;
}