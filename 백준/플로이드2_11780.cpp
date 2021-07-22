#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N, M, a, b, c, arr[105][105], route[101][101];
vector<int> v;

void findRoute(int start, int end)
{
    if (route[start][end] == 0)
    {
        v.push_back(start);
        v.push_back(end);
        return;
    }
    findRoute(start, route[start][end]);
    v.pop_back();
    findRoute(route[start][end], end);
}

int main()
{
    scanf("%d %d", &N, &M);
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 1; i <= N; i++)
        arr[i][i] = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (arr[a][b] > c)
            arr[a][b] = c;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    route[i][j] = k;
                }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (arr[i][j] == arr[104][104])
                printf("0 ");
            else
                printf("%d ", arr[i][j]);
        printf("\n");
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == arr[104][104] || i == j)
                printf("0 ");
            else
            {
                v.clear();
                findRoute(i, j);
                printf("%d ", v.size());
                for (int k = 0; k < v.size(); k++)
                    printf("%d ", v[k]);
            }
            printf("\n");
        }
    }
    return 0;
}
