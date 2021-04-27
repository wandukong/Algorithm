#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, arr[21][21], temp[21][21], ans;

void moving(int dir, int cnt)
{
    queue<int> q;
    if (cnt == 0)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, arr[i][j]);
        return;
    }
    if (dir == 0) // 오른쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (arr[i][j])
                    q.push(arr[i][j]);
                arr[i][j] = 0;
            }
            int idx = N - 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (arr[i][idx] == 0)
                {
                    arr[i][idx] = data;
                }
                else if (arr[i][idx] == data)
                {
                    arr[i][idx] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    arr[i][idx] = data;
                }
            }
        }
    }
    else if (dir == 1) // 왼쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j])
                    q.push(arr[i][j]);
                arr[i][j] = 0;
            }
            int idx = 0;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (arr[i][idx] == 0)
                {
                    arr[i][idx] = data;
                }
                else if (arr[i][idx] == data)
                {
                    arr[i][idx] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    arr[i][idx] = data;
                }
            }
        }
    }
    else if (dir == 2) // 아래쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (arr[j][i])
                    q.push(arr[j][i]);
                arr[j][i] = 0;
            }
            int idx = N - 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (arr[idx][i] == 0)
                {
                    arr[idx][i] = data;
                }
                else if (arr[idx][i] == data)
                {
                    arr[idx][i] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    arr[idx][i] = data;
                }
            }
        }
    }
    else if (dir == 3) // 위쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[j][i])
                    q.push(arr[j][i]);
                arr[j][i] = 0;
            }
            int idx = 0;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (arr[idx][i] == 0)
                {
                    arr[idx][i] = data;
                }
                else if (arr[idx][i] == data)
                {
                    arr[idx][i] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    arr[idx][i] = data;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int temp[21][21];
        memcpy(temp, arr, sizeof(arr));
        moving(i, cnt - 1);
        memcpy(arr, temp, sizeof(temp));
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    for (int i = 0; i < 4; i++)
    {
        int temp[21][21];
        memcpy(temp, arr, sizeof(arr));
        moving(i, 5);
        memcpy(arr, temp, sizeof(temp));
    }
    printf("%d", ans);
    return 0;
}