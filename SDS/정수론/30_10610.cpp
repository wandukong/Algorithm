#include <algorithm>
#include <iostream>

using namespace std;

string N;

int cnt[10], sum;

int main()
{
    cin >> N;
    for (int i = 0; i < N.size(); i++)
    {
        cnt[N[i] - '0']++;
        sum += N[i] - '0';
    }
    if (sum % 3 != 0 || cnt[0] == 0)
        printf("-1");
    else
    {
        sort(N.begin(), N.end(), greater<int>());
        printf("%s", N.c_str());
    }
    return 0;
}