
#include <iostream>
#include <algorithm>

using namespace std;

int N, K, sum, ans;
int arr[100001];

int main()
{
    int left = 1, right = 1;
    while (left <= N + 1)
    {
        if (right == N + 1 || sum >= K)
            sum -= arr[left++];
        else
            sum += arr[right++];
        if (sum == K)
            ans = min(ans, right - left);
    }
    return 0;
}