#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, arr[1000002], ans;
vector<int> v;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    v.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > v[v.size() - 1])
            v.push_back(arr[i]);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }
    printf("%d", v.size());
    return 0;
}