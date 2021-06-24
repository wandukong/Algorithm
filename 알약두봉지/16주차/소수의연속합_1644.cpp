#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
bool check[4000001];
vector<int> prime;

int main()
{
    scanf("%d", &N);

    for (int i = 2; i <= N; i++)
    {
        if (check[i])
            continue;
        for (int j = i + i; j <= N; j += i)
            if (!check[j])
                check[j] = true;
    }
    for (int i = 2; i <= N; i++)
        if (!check[i])
            prime.push_back(i);
    prime.push_back(0);
    int s = 0, e = 0, sum = 0;
    while (s <= e)
    {
        if (sum > N || e == prime.size() - 1)
            sum -= prime[s++];
        else
            sum += prime[e++];
        if (sum == N)
            ans++;
    }
    printf("%d", ans);
    return 0;
}