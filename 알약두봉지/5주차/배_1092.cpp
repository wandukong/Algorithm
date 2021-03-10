#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans = 0;
int crane[51];
vector<int> box;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &crane[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int a;
        scanf("%d", &a);
        box.push_back(a);
    }

    sort(crane, crane + N, greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if (crane[0] < box[0])
    {
        printf("-1");
        return 0;
    }

    while (!box.empty())
    {
        int loc = 0;
        for (int i = 0; i < box.size(); i++)
        {
            if (crane[loc] >= box[i])
            {
                box.erase(box.begin() + i);
                i -= 1;
                loc++;
            }
            if (loc == N)
                break;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}