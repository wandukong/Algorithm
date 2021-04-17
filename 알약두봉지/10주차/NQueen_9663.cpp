#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, ans;
int check[15];

bool checking(int cnt)
{
    for (int i = 0; i < cnt; i++)
        if (check[i] == check[cnt] || abs(check[i] - check[cnt]) == cnt - i)
            return false;
    return true;
}

void solve(int cnt)
{
    if (cnt == N)
    {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        check[cnt] = i;
        if (checking(cnt))
            solve(cnt + 1);
    }
}

int main()
{
    scanf("%d", &N);
    solve(0);
    printf("%d", ans);
    return 0;
}