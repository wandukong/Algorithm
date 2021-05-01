#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[2001];
bool check[2001][2001];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);

    for (int i = 1; i <= N; i++)
        check[i][i] = 1;
    for (int i = 1; i <= N - 1; i++)
        if (arr[i] == arr[i + 1])
            check[i][i + 1] = 1;

    for (int i = 2; i <= N - 1; i++)
        for (int j = 1; j <= N - i; j++)
            if (arr[j] == arr[j + i] && check[j + 1][j + i - 1])
                check[j][j + i] = true;
    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", check[a][b]);
    }
    return 0;
}