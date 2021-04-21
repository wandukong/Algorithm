#include <iostream>
#include <algorithm>

using namespace std;
string arr;

bool firstWin()
{
    for (int i = 0; i < 3; i++)
        if (arr[i * 3] == 'X' && arr[i * 3] == arr[i * 3 + 1] && arr[i * 3 + 1] == arr[i * 3 + 2]) // ��
            return true;
    for (int i = 0; i < 3; i++)
        if (arr[i] == 'X' && arr[i] == arr[i + 3] && arr[i + 3] == arr[i + 6]) // ��
            return true;
    if (arr[0] == 'X' && arr[0] == arr[4] && arr[4] == arr[8]) // �밢��1
        return true;
    if (arr[2] == 'X' && arr[2] == arr[4] && arr[4] == arr[6]) // �밢��2
        return true;
    return false;
}

bool secondWin()
{
    for (int i = 0; i < 3; i++)
        if (arr[i * 3] == 'O' && arr[i * 3] == arr[i * 3 + 1] && arr[i * 3 + 1] == arr[i * 3 + 2]) // ��
            return true;
    for (int i = 0; i < 3; i++)
        if (arr[i] == 'O' && arr[i] == arr[i + 3] && arr[i + 3] == arr[i + 6]) // ��
            return true;
    if (arr[0] == 'O' && arr[0] == arr[4] && arr[4] == arr[8]) // �밢��1
        return true;
    if (arr[2] == 'O' && arr[2] == arr[4] && arr[4] == arr[6]) // �밢��2
        return true;
    return false;
}

void solve()
{
    int first = 0, second = 0; // ����
    bool XWin = firstWin(), OWin = secondWin();

    for (int i = 0; i < 9; i++)
        if (arr[i] == 'X')
            first++;
        else if (arr[i] == 'O')
            second++;

    if (XWin && !OWin && first - second == 1) // X�� �̱� ���
        printf("valid\n");
    else if (!XWin && OWin && first == second) // O�� �̱� ���
        printf("valid\n");
    else if (first == 5 && second == 4 && !XWin && !OWin) // ��� ���
        printf("valid\n");
    else
        printf("invalid\n");
    return;
}

int main()
{
    while (true)
    {
        cin >> arr;
        if (arr == "end")
            break;
        solve();
    }
    return 0;
}