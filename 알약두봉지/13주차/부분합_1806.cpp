#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[100001], ans = 987654321;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    int start = 1, end = 1, sum = 0;
    while (start <= N + 1)
    {
        if (end == N + 1 || sum >= M)
            sum -= arr[start++];
        else
            sum += arr[end++];
        if (sum >= M)
            ans = min(ans, end - start);
    }
    if (ans == 987654321)
        ans = 0;
    printf("%d", ans);
    return 0;
}