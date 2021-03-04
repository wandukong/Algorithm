#include <iostream>
#include <algorithm>

using namespace std;

int gear[5][9];     // ½ÃÀÛ Àü Åé´Ï¹ÙÄû »óÅÂ
int tempGear[5][9]; // Åé´Ï¹ÙÄû È¸Àü ÀÛ¾÷ ÀÓ½Ã °á°ú
int result[5][9];   // Åé´Ï¹ÙÄû È¸Àü ÈÄ °á°ú
int K, ans;

void moveGear(int num, bool dir)
{
    if (dir)
    {
        for (int i = 7; i >= 0; i--)
            tempGear[num][i + 1] = tempGear[num][i];
        tempGear[num][0] = tempGear[num][8];
    }
    else
    {
        int temp = tempGear[num][0];
        for (int i = 0; i <= 6; i++)
            tempGear[num][i] = tempGear[num][i + 1];
        tempGear[num][7] = temp;
    }
    for (int i = 0; i < 8; i++)
        result[num][i] = tempGear[num][i];
}

int main()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j < 8; j++)
            scanf("%1d", &gear[i][j]);
    scanf("%d", &K);
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j < 8; j++)
            result[i][j] = tempGear[i][j] = gear[i][j];
    while (K--)
    {
        int a, b;
        bool dirChk;
        scanf("%d %d", &a, &b);
        if (b == 1)
            dirChk = true;
        else
            dirChk = false;
        moveGear(a, dirChk);
        bool tempDir = dirChk;
        int temp = a;
        for (int i = a + 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
                for (int k = 0; k < 8; k++)
                    tempGear[j][k] = gear[j][k];
            if (tempGear[temp][2] == tempGear[i][6])
                break;
            tempDir = !tempDir;
            moveGear(i, tempDir);
            temp = i;
        }
        tempDir = dirChk;
        temp = a;
        for (int i = a - 1; i >= 1; i--)
        {
            for (int j = 1; j <= 4; j++)
                for (int k = 0; k < 8; k++)
                    tempGear[j][k] = gear[j][k];
            if (tempGear[temp][6] == tempGear[i][2])
                break;
            tempDir = !tempDir;
            moveGear(i, tempDir);
            temp = i;
        }
        for (int i = 1; i <= 4; i++)
            for (int j = 0; j < 8; j++)
                gear[i][j] = tempGear[i][j] = result[i][j];
    }
    if (gear[1][0])
        ans += 1;
    if (gear[2][0])
        ans += 2;
    if (gear[3][0])
        ans += 4;
    if (gear[4][0])
        ans += 8;
    printf("%d", ans);
    return 0;
}