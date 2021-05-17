#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, R, arr[102][102];
int temp[102][102];

void cal1()
{
    for (int i = 0; i < N / 2; i++)
        for (int j = 0; j < M; j++)
            swap(arr[i][j], arr[N - i - 1][j]);
}

void cal2()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M / 2; j++)
            swap(arr[i][j], arr[i][M - j - 1]);
}

void cal3()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            temp[j][N - 1 - i] = arr[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = temp[i][j];
    swap(N, M);
}

void cal4()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            temp[M - 1 - j][i] = arr[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = temp[i][j];
    swap(N, M);
}

void cal5()
{
    int n = N / 2;
    int m = M / 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j + m] = arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = m; j < M; j++)
            temp[i + n][j] = arr[i][j];

    for (int i = n; i < N; i++)
        for (int j = m; j < M; j++)
            temp[i][j - m] = arr[i][j];

    for (int i = n; i < N; i++)
        for (int j = 0; j < m; j++)
            temp[i - n][j] = arr[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = temp[i][j];
}

void cal6()
{
    int n = N / 2;
    int m = M / 2;

    for (int i = 0; i < n; i++)
        for (int j = m; j < M; j++)
            temp[i][j - m] = arr[i][j];

    for (int i = n; i < N; i++)
        for (int j = m; j < M; j++)
            temp[i - n][j] = arr[i][j];

    for (int i = n; i < N; i++)
        for (int j = 0; j < m; j++)
            temp[i][j + m] = arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i + n][j] = arr[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = temp[i][j];
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
    while (R--)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
            cal1();
        else if (a == 2)
            cal2();
        else if (a == 3)
            cal3();
        else if (a == 4)
            cal4();
        else if (a == 5)
            cal5();
        else if (a == 6)
            cal6();
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}