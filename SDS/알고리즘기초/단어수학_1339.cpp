#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>

// 알파벳이 주어지면
// 알파벳별로 숫자를 하나씩 매핑해보는게 일입니다.
// 최대 10개가 주어지는데....경우의수?????
// 이렇게 만든 경우의수에 대해서
// 직접 숫자을 대입해서 합을구하고, 최대값을 찾는다....

using namespace std;

int N, ans;
bool usedAlphabet[26]; //사용한 알파벳
vector<char> alphabet; // 사용한 알파벳
vector<string> v;      // 입력받은 문자열
bool number[10];       // 사용한 숫자
int usedNumber[26];    // 순열
map<char, int> m;      // 사용한 알파엣의 인덱스

void recursive(int cnt)
{
    if (cnt == alphabet.size())
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int mul = 1;
            for (int j = v[i].size() - 1; j >= 0; j--)
            {
                sum += usedNumber[m[v[i][j]]] * mul;
                mul *= 10;
            }
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (!number[i])
        {
            number[i] = true;
            usedNumber[cnt] = i;
            recursive(cnt + 1);
            number[i] = false;
            usedNumber[cnt] = 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
        for (int j = v[i].size() - 1; j >= 0; j--)
            usedAlphabet[v[i][j] - 'A'] = true;

    int idx = 0;
    for (int i = 0; i < 26; i++)
        if (usedAlphabet[i])
        {
            alphabet.push_back(i);
            m[i + 'A'] = idx++;
        }
    recursive(0);
    printf("%d", ans);
    return 0;
}

// 두번째 ==> 숫자를 그대로이용하는 방법
// ABCD : 1000 * A + 100 * B + 10 * C + D
// GCD : 100 * G + 10 * C + D
// EFABC : 10000 * E + 1000 * F + 100 * A + 10 * B + C
// ----------------------------------------------------
// 1100 * A + 110 * B + 21 * C + 2 * D + 10000 * E + 1000 * F + 100 * G

using namespace std;

int N, ans;
vector<string> v;
int value[26];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        int num = 1;
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            value[v[i][j] - 'A'] += num;
            num *= 10;
        }
    }
    sort(value, value + 26, greater<int>());
    int idx = 0, num = 9;
    while (true)
    {
        ans += value[idx++] * (num--);
        if (value[idx] == 0)
            break;
    }
    printf("%d", ans);
    return 0;
}
