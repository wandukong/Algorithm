#include <iostream>
#include <algorithm>

using namespace std;

int N, S, arr[21], ans;

void solve(int idx, int sum)
{

    sum += arr[idx];
    if (idx >= N)
        return;
    if (sum == S)
        ans++;
    solve(idx + 1, sum - arr[idx]);
    solve(idx + 1, sum);
}

int main()
{
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    solve(0, 0);
    printf("%d", ans);
    return 0;
}