#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prime;
int N, ans = -1, num, arr[1000001], leftGcd[1000001], rightGcd[1000001];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= N; i++)
        leftGcd[i] = gcd(leftGcd[i - 1], arr[i]);
    for (int i = N; i >= 1; i--)
        rightGcd[i] = gcd(rightGcd[i + 1], arr[i]);
    for (int i = 1; i <= N; i++)
    {
        int curGcd = gcd(leftGcd[i - 1], rightGcd[i + 1]);
        if (arr[i] % curGcd == 0)
            continue;
        if (ans < curGcd)
        {
            ans = curGcd;
            num = arr[i];
        }
    }
    if (ans == -1)
        printf("%d", ans);
    else
        printf("%d %d", ans, num);
    return 0;
}