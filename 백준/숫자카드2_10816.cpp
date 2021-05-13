#include <algorithm>
#include <iostream>

using namespace std;

int N, M, arr[500005], arr2[500005];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arr2[i]);
    sort(arr, arr + N);
    for (int i = 0; i < M; i++)
    {
        int l = lower_bound(arr, arr + N, arr2[i]) - arr;
        int r = upper_bound(arr, arr + N, arr2[i]) - arr;
        printf("%d ", r - l);
    }
    return 0;
}