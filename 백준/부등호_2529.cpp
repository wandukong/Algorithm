#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int k, arr[11];
bool sign[10], check[11];

long long minAns = 9999999999;
long long maxAns = 0;

void go(int cnt, int value)
{
    if (cnt == k)
    {
        long long value = 0;
        long long p = 1;
        for (int i = k; i >= 0; i--)
        {
            value += arr[i] * p;
            p *= 10;
        }
        minAns = min(minAns, value);
        maxAns = max(maxAns, value);
        return;
    }

    if (sign[cnt + 1]) // <
    {
        for (int i = value + 1; i <= 9; i++)
        {
            if (!check[i])
            {
                check[i] = true;
                arr[cnt + 1] = i;
                go(cnt + 1, i);
                check[i] = false;
                arr[cnt + 1] = 0;
            }
        }
    }
    else // >
    {
        for (int i = value - 1; i >= 0; i--)
        {
            if (!check[i])
            {
                check[i] = true;
                arr[cnt + 1] = i;
                go(cnt + 1, i);
                check[i] = false;
                arr[cnt + 1] = 0;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &k);

    for (int i = 1; i <= k; i++)
    {
        char c;
        cin >> c;
        sign[i] = (c == '<') ? true : false;
    }
    for (int i = 0; i <= 9; i++)
    {
        check[i] = true;
        arr[0] = i;
        go(0, i);
        memset(check, 0, sizeof(check));
        memset(arr, 0, sizeof(arr));
    }
    string s = "";
    s = to_string(maxAns);
    if (k == s.size())
        printf("0");
    printf("%lld\n", maxAns);
    s = "";
    s = to_string(minAns);
    if (k == s.size())
        printf("0");
    printf("%lld\n", minAns);
    return 0;
}