#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<char> arr;
vector<char> ans;
map<char, int> m;

void recur(int loc, int cnt, int countMoeum, int countJaeum)
{
    if (cnt == N && countJaeum >= 2 && countMoeum >= 1)
    {
        for (int i = 0; i < N; i++)
            printf("%c", ans[i]);
        printf("\n");
    }
    for (int i = loc; i < M; i++)
    {
        ans.push_back(arr[i]);
        if (m[arr[i]])
            countMoeum++;
        else
            countJaeum++;
        recur(i + 1, cnt + 1, countMoeum, countJaeum);
        ans.erase(ans.end() - 1);
        if (m[arr[i]])
            countMoeum--;
        else
            countJaeum--;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        char c;
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = true;
    recur(0, 0, 0, 0);
    return 0;
}