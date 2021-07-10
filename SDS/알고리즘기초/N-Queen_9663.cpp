#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, ans;
int chess[14][14]; // �ʱ�ȭ�� �̹� 0���� �Ǿ�����

void recur(int line)
{
    if (line == n)
    {
        ans++;
        return;
    }
    // line��򰡿��ٰ� queen�� ���ƺ���
    for (int i = 0; i < n; i++)
    {
        if (chess[line][i] != -1)
            continue;
        chess[line][i] = line;

        for (int x = 0; x < n; x++) // ����
            if (chess[line][x] == -1)
                chess[line][x] = line;
        for (int y = line; y < n; y++) // �Ʒ�
            if (chess[y][i] == -1)
                chess[y][i] = line;
        // �밢��
        for (int y = line, x = i; y < n && 0 <= x; y++, x--)
            if (chess[y][x] == -1)
                chess[y][x] = line;
        for (int y = line, x = i; y < n && x < n; y++, x++)
            if (chess[y][x] == -1)
                chess[y][x] = line;

        recur(line + 1);

        for (int x = 0; x < n; x++) //����
            if (chess[line][x] == line)
                chess[line][x] = -1;
        for (int y = line; y < n; y++) // �Ʒ�
            if (chess[y][i] == line)
                chess[y][i] = -1;
        // �밢��
        for (int y = line, x = i; y < n && 0 <= x; y++, x--)
            if (chess[y][x] == line)
                chess[y][x] = -1;
        for (int y = line, x = i; y < n && x < n; y++, x++)
            if (chess[y][x] == line)
                chess[y][x] = -1;
    }
}

int main()
{
    memset(chess, -1, sizeof(chess));
    scanf("%d", &n);
    recur(0);
    printf("%d", ans);
}