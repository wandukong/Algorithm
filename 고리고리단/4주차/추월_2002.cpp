#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<string, int> m;
int N, cnt = 1, ans;
vector<int> result;
vector<int> check;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        m[temp] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        result.push_back(m[temp]);
        check.push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", check[0], result[i]);
        if (check[0] != result[i]) // 추월
        {
            ans++;
            check.erase(remove(check.begin(), check.end(), result[i]), check.end());
        }
        else // 추월 x
        {
            check.erase(check.begin(), check.begin() + 1);
        }
    }
    printf("%d\n", ans);

    return 0;
}