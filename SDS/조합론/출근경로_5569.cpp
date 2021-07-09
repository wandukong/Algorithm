#include <iostream>
#include <algorithm>
#define MOD 100000
using namespace std;

int w, h, dp[101][101][2][2]; // [x��ǥ][y��ǥ][���Ⱑ�ɿ���][����]

int main()
{
    scanf("%d%d", &w, &h);
    for (int i = 2; i <= w; i++)
        dp[1][i][0][1] = 1;
    for (int i = 2; i <= h; i++)
        dp[i][1][0][0] = 1;
    for (int i = 2; i <= h; i++)
        for (int j = 2; j <= w; j++)
        {
            dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % MOD; //  �������� �� = ���Ⱑ�� �� + ����Ұ��� ��
            dp[i][j][0][1] = (dp[i][j - 1][0][1] + dp[i][j - 1][1][1]) % MOD; //  ���Ⱑ�� �� = ���Ⱑ�� �� + ����Ұ��� ��
            dp[i][j][1][0] = dp[i - 1][j][0][1] % MOD;                        //  �����Ұ���(�̹̲���) �� = ���Ⱑ�� ��
            dp[i][j][1][1] = dp[i][j - 1][0][0] % MOD;                        //  �����Ұ���(�̹̲���) �� = ���Ⱑ�� ��
        }
    printf("%d", (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD);
    return 0;
}