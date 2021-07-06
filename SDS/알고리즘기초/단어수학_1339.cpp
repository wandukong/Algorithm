#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>

// ���ĺ��� �־�����
// ���ĺ����� ���ڸ� �ϳ��� �����غ��°� ���Դϴ�.
// �ִ� 10���� �־����µ�....����Ǽ�?????
// �̷��� ���� ����Ǽ��� ���ؼ�
// ���� ������ �����ؼ� �������ϰ�, �ִ밪�� ã�´�....

using namespace std;

int N, ans;
bool usedAlphabet[26]; //����� ���ĺ�
vector<char> alphabet; // ����� ���ĺ�
vector<string> v;      // �Է¹��� ���ڿ�
bool number[10];       // ����� ����
int usedNumber[26];    // ����
map<char, int> m;      // ����� ���Ŀ��� �ε���

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

// �ι�° ==> ���ڸ� �״���̿��ϴ� ���
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
