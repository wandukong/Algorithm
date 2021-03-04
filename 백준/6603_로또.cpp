#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int arr[15];
bool check[15];
int ans[6];

void go(int location, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }

    for (int i = location; i < N; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            ans[cnt] = arr[i];
            go(i, cnt + 1);
            check[i] = false;
            ans[cnt] = 0;
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        go(0, 0);
        printf("\n");
    }
    return 0;
}