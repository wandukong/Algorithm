#include <iostream>
#include <algorithm>

using namespace std;

int r1, c1, r2, c2;
int ans[55][10];
int cnt = 1;       // 넣을 숫자
int straight = 1;  // 직진 횟수
int direction = 0; // 방향
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int digit(int num) // 자릿수 구하는 함수
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int main()
{
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    int cr = 0 - r1, cc = 0 - c1; // 현재 있는 위치, 우선 1을 적는 곳을 초기화 시킴

    for (int i = 1; i <= 10002; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < straight; k++)
            {
                if (0 <= cr && cr <= r2 - r1 && 0 <= cc && cc <= c2 - c1)
                    ans[cr][cc] = cnt;
                cr += dr[direction % 4], cc += dc[direction % 4];
                cnt++;
            }
            direction++;
        }
        straight++;
    }

    int maxNum = 0;
    for (int i = 0; i <= r2 - r1; i++)
        for (int j = 0; j <= c2 - c1; j++)
        {
            maxNum = max(maxNum, ans[i][j]);
            //printf("%d %d = %d", i, j, ans[i][j])
        }
    int maxDigitNum = digit(maxNum); // 가장 큰 숫자의 자릿수

    for (int i = 0; i <= r2 - r1; i++)
    {
        for (int j = 0; j <= c2 - c1; j++)
            printf("%*d ", maxDigitNum, ans[i][j]);
        printf("\n");
    }
}