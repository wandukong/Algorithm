#include <iostream>
#include <algorithm>

using namespace std;

int N, ans, sum;
int arr[1001];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        ans += sum;
    }
    printf("%d\n", ans);
}