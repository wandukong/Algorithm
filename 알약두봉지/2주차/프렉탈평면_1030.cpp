#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int s, N, K, R1, R2, C1, C2;
char ans[51][51];
vector<int> total, black;

int main()
{
    scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
    for (int i = 0; i <= R2 - R1; i++)
        for (int j = 0; j <= C2 - C1; j++)
            ans[i][j] = '0';
    int num = 1;
    for (int i = 0; i < s; i++)
        num *= N;
    int a = N;
    int b = K;
    for (int i = 0; i < s; i++)
    {
        total.push_back(a);
        black.push_back(b);
        a *= N;
        b *= N;
    }

    for (int i = 0; i <= R2 - R1; i++)
    {
        for (int j = 0; j <= C2 - C1; j++)
        {
            int r = i + R1, c = j + C1;
            for (int k = 0; k < black.size(); k++)
            {
                int mid = total[k] / 2; // 검은색 색칠할 중앙자리
                int cnt = black[k] / 2; // 중앙 자리로부터 몇 개 칠해야할지
                if (black[k] % 2 == 0)  // N, K 가 짝수 일 때
                {
                    if ((((mid - cnt <= r % total[k]) && (r % total[k]) < mid + cnt)) && ((mid - cnt <= (c % total[k])) && ((c % total[k]) < mid + cnt)))
                        ans[i][j] = '1';
                }
                else // N, K 가 홀수 일 때
                {
                    if ((((mid - cnt <= r % total[k]) && (r % total[k]) <= mid + cnt)) && ((mid - cnt <= (c % total[k])) && ((c % total[k]) <= mid + cnt)))
                        ans[i][j] = '1';
                }
            }
        }
    }
    for (int i = 0; i <= R2 - R1; i++)
    {
        for (int j = 0; j <= C2 - C1; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }
    return 0;
}