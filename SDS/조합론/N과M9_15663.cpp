#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 1000000010

using namespace std;

int N, M, arr[9], ans[9];
bool check[9];
string answer;

void go(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    int temp = -1;
    for (int i = 0; i < N; i++)
    {

        if (check[i] || temp == arr[i])
            continue;
        check[i] = true;
        ans[cnt] = arr[i];
        go(cnt + 1);
        temp = ans[cnt];
        ans[cnt] = 0;
        check[i] = false;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    go(0);
    return 0;
}