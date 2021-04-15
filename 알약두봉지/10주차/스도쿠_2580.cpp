#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int arr[9][9];
bool check[3][9][10];
int check2[10];
vector<pair<int, int>> v;

bool dfs(int cnt)
{
    auto cur = v[cnt];
    if (cnt == v.size())
    {
        for (int i = 1; i <= 9; i++)
            if (check2[i] != 9)
                return false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!check[0][cur.first][i] && !check[1][cur.second][i] && !check[2][(cur.first / 3) * 3 + cur.second / 3][i])
        {
            arr[cur.first][cur.second] = i;
            check[0][cur.first][i] = true;
            check[1][cur.second][i] = true;
            check[2][(cur.first / 3) * 3 + cur.second / 3][i] = true;
            check2[i]++;
            if (dfs(cnt + 1))
                return true;
            check2[i]--;
            arr[cur.first][cur.second] = 0;
            check[0][cur.first][i] = false;
            check[1][cur.second][i] = false;
            check[2][(cur.first / 3) * 3 + cur.second / 3][i] = false;
        }
    }
    return false;
}

int main()
{

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
            {
                v.push_back({i, j});
                continue;
            }
            check[0][i][arr[i][j]] = true;
            check[1][j][arr[i][j]] = true;
            check[2][(i / 3) * 3 + j / 3][arr[i][j]] = true;
            check2[arr[i][j]]++;
        }
    dfs(0);
    return 0;
}