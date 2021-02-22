#include <iostream>
#include <algorithm>

using namespace std;

int N;
string ans = "";
int dp[11][10];
int s[11];

void makeAns(int where, int cnt)
{
    if (where < 1)
        return;

    for (int i = where - 1; i < 10; i++)
    {
        if (dp[where][i] >= cnt)
        {
            ans += i + '0';
            makeAns(where - 1, cnt);
            return;
        }
        cnt -= dp[where][i];
    }
}

int main()
{
    scanf("%d", &N);
    N++;

    for (int i = 0; i < 10; i++) // ���ڸ� ���� �ʱ�ȭ
        dp[1][i] = 1;
    s[1] = 10;

    for (int i = 2; i < 11; i++) // ���ڸ�~���ڸ� ���� �ʱ�ȭ
    {
        dp[i][i - 1] = 1;
        s[i] = 1;
        for (int j = i; j < 10; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            s[i] += dp[i][j];
        }
    }

    for (int i = 1; i < 11; i++) // ���ڸ� �������� ã��
    {
        if (N <= s[i])
        {
            makeAns(i, N);
            break;
        }
        N -= s[i];
    }
    if (ans == "")
        printf("-1");
    else
        printf("%s", ans.c_str());
}