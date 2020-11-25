#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, ans;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%dn", &a);
        q.push(a);
    }
    for (int i = 0; i < N - 1; i++)
    {
        int sum = 0;
        sum += q.top();
        q.pop();
        sum += q.top();
        q.pop();

        q.push(sum);

        ans += sum;
    }
    printf("%d\n", ans);
    return 0;
}