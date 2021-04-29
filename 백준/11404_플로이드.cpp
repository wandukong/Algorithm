#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a, b, c, arr[101][101];
int INF = 987654321;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = min(arr[a][b], c);
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (arr[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
