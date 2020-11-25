#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        q.push(a);
    }

    for (int i = 0; i < M; i++)
    {
        long long sum = 0;
        sum += q.top();
        q.pop();
        sum += q.top();
        q.pop();

        q.push(sum);
        q.push(sum);
    }

    while (!q.empty())
    {
        ans += q.top();
        q.pop();
    }

    printf("%lld\n", ans);

    return 0;
}