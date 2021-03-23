#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long ans;
vector<string> v;
long long chk[10];
bool firstChk[10];
vector<pair<long long, int>> numbers;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for (int i = 0; i < N; i++)
        firstChk[v[i][0] - 65] = true;

    for (int i = 0; i < N; i++)
    {
        long long cnt = 1;
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            chk[v[i][j] - 65] += cnt;
            cnt *= 10;
        }
    }
    for (int i = 0; i < 10; i++)
        numbers.push_back({chk[i], i});
    sort(numbers.begin(), numbers.end());

    if (numbers[0].first != 0 && firstChk[numbers[0].second])
    {
        int idx = 1;
        for (; idx < numbers.size(); idx++)
            if (!firstChk[numbers[idx].second])
                break;
        auto temp = numbers[idx];
        for (int i = idx; i >= 1; i--)
            numbers[i] = numbers[i - 1];
        numbers[0] = temp;
    }
    for (int i = 0; i < 10; i++)
        ans += numbers[i].first * i;
    printf("%lld", ans);
    return 0;
}