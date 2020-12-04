#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int arr[1000];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > ans)
        {
            break;
        }
        ans += arr[i];
    }
    printf("%d", ans);
}