#include <iostream>
#include <algorithm>

using namespace std;

int n;
char arr[55][55];

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &arr[i][j]); // �տ� ��ĭ ������ ��ĭ���� �Է� ���� �� �ִ�.

    printf("==========\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
    return 0;
}

/*

YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ

*/