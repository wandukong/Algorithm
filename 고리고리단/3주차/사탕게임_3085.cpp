#include <iostream>
#include <algorithm>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int n, ans;
char arr[55][55];

int checkRow()
{
    int maxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        char c = arr[i][0];
        for (int j = 1; j < n; j++)
        {
            if (c == arr[i][j])
            {
                cnt++;
                maxCnt = cnt > maxCnt ? cnt : maxCnt;
            }
            else
            {
                cnt = 1;
                c = arr[i][j];
            }
        }
    }
    return maxCnt;
}

int checkCol()
{
    int maxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        char c = arr[0][i];
        for (int j = 1; j < n; j++)
        {
            if (c == arr[j][i])
            {
                cnt++;
                maxCnt = cnt > maxCnt ? cnt : maxCnt;
            }
            else
            {
                cnt = 1;
                c = arr[j][i];
            }
        }
    }
    return maxCnt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &arr[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                swap(arr[i][j], arr[nr][nc]);
                int temp = checkRow();
                ans = temp > ans ? temp : ans;
                temp = checkCol();
                ans = temp > ans ? temp : ans;
                swap(arr[i][j], arr[nr][nc]);
            }
    printf("%d\n", ans);
    return 0;
}