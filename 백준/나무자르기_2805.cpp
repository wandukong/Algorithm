#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans;
int arr[1000001];
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    int left = 0, right = 2000000000, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] - mid > 0)
                sum += arr[i] - mid;
        }
        if (sum >= M)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}