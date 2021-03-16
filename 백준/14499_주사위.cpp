#include <iostream>
#include <algorithm>

using namespace std;

int N, M, X, Y, K;
int arr[21][21];
int dice[6]; // idx : 1 拉搁, 3 : 官蹿搁
int temp[6];

int main()
{
    scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
    while (K--)
    {
        int a;
        scanf("%d", &a);
        copy(dice, dice + 6, temp);
        if (a == 1) // 悼率
        {
            if (Y + 1 >= M)
                continue;
            Y++;
            temp[5] = dice[1];
            temp[4] = dice[3];
            temp[1] = dice[4];
            temp[3] = dice[5];
        }
        else if (a == 2) // 辑率
        {
            if (Y - 1 < 0)
                continue;
            Y--;
            temp[4] = dice[1];
            temp[5] = dice[3];
            temp[3] = dice[4];
            temp[1] = dice[5];
        }
        else if (a == 3) // 合率
        {
            if (X - 1 < 0)
                continue;
            X--;
            temp[3] = dice[0];
            temp[0] = dice[1];
            temp[1] = dice[2];
            temp[2] = dice[3];
        }
        else if (a == 4) // 巢率
        {
            if (X + 1 >= N)
                continue;
            X++;
            temp[1] = dice[0];
            temp[2] = dice[1];
            temp[3] = dice[2];
            temp[0] = dice[3];
        }
        if (arr[X][Y] == 0)
            arr[X][Y] = temp[3];
        else
        {
            temp[3] = arr[X][Y];
            arr[X][Y] = 0;
        }
        printf("%d\n", temp[1]);
        copy(temp, temp + 6, dice);
    }
    return 0;
}