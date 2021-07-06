#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int N, M;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    int left = 0, right = 0, ans = 0, sum = 0;
    while (left <= N)
    {
        if (sum > M || right == N)
            sum -= arr[left++];
        else
            sum += arr[right++];
        if (sum == M)
            ans++;
    }
    printf("%d", ans);
    return 0;
}