#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
long long ans;
vector<int> bag;
vector<pair<int, int>> jwl;
priority_queue<int> pq;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        jwl.push_back({a, b});
    }
    for (int i = 0; i < K; i++)
    {
        int a;
        scanf("%d", &a);
        bag.push_back(a);
    }
    sort(jwl.begin(), jwl.end());
    sort(bag.begin(), bag.end());

    int jwlIdx = 0;
    for (int i = 0; i < bag.size(); i++)
    {
        while (jwlIdx < N && jwl[jwlIdx].first <= bag[i])
        {
            pq.push(jwl[jwlIdx].second);
            jwlIdx++;
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    printf("%lld", ans);
    return 0;
}