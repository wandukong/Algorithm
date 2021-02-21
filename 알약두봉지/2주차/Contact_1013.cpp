#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str;

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        cin >> str;
        int i = 0;
        bool first = false, second = false; // ù��°, �ι�° ���� ���� ����
        bool chk = false;                   // ���� 0���� �������� �˻�
        int zeroCheck = 0;                  // ù��° ���� 0�ΰ� �Դ��� Ȯ��

        for (; i < str.size(); i++)
        {
            int tempStr = str[i] - '0';
            int prevStr = -1; //�� ��
            if (i != 0)
                prevStr = str[i - 1] - '0';
            int prevStr2 = -1; // �վ� ��
            if (i > 1)
                prevStr2 = str[i - 2] - '0';
            int nextStr = -1; // ���� ��
            if (i + 1 <= str.size() - 1)
                nextStr = str[i + 1] - '0';

            if (!first && !second) // ���� Ȯ��
            {
                if (tempStr) // 1�̸� ù��° ���� ����
                {
                    first = true;
                    continue;
                }
                else // 0�̸� �ι�° ���� ����
                {
                    second = true;
                    if (prevStr2 == 1 && prevStr == 1 && nextStr == 0)
                    {
                        first = true;
                        second = false;
                        zeroCheck = 1;
                    }
                    continue;
                }
            }
            else if (second && tempStr) // �ι�° ���� ��
            {
                second = false;
                continue;
            }
            else if (first)
            {
                if (zeroCheck >= 2 && tempStr) // 0�� 2�� �̻����, ���� ���� 1�� �� ���
                {
                    if (nextStr == 1)
                        continue;          // ���� ���� 1�̸� ù��° ���� ����
                    else if (nextStr == 0) // ���� ���� 0�̸� ù��° ���� ��
                    {
                        zeroCheck = 0;
                        first = false;
                        continue;
                    }
                    else if (nextStr == -1) // ���� ���� ���� ���, ù��° ���� �� -> ù��° ���� ����.
                    {
                        printf("YES\n");
                        chk = true;
                        break;
                    }
                }
                else if (!tempStr) // 0�̸� ù��° ���� ����
                {
                    zeroCheck++;
                    continue;
                }
                else
                    break; // 0 ���� 1�� �������� ���ö�
            }
            else
                break;
        }
        if (str[str.size() - 1] == '0')
            printf("NO\n");
        else if (!chk)
            if (!first && !second && i == str.size())
                printf("YES\n");
            else
                printf("NO\n");
    }
    return 0;
}