// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
long long answer;
long long arr[10001];

int main()
{
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++)
        scanf("%lld", &arr[i]);

    sort(arr, arr + K);
    long long left = 0, right = __LONG_LONG_MAX__;
    while (left <= right)
    {
        int cnt = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < K; i++)
            cnt += arr[i] / mid;
        if (cnt < N)
            right = mid - 1;
        else
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    printf("%lld", answer);
    return 0;
}