#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, arr[500001], ans[500001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    pq.push({arr[N], N});
    for (int i = N - 1; i >= 1; i--)
    {
        while (!pq.empty())
        {
            if (arr[i] > pq.top().first)
            {
                ans[pq.top().second] = i;
                pq.pop();
            }
            else
                break;
        }
        pq.push({arr[i], i});
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", ans[i]);
    return 0;
}