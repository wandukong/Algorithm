#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N;

void recur(int cnt)
{

    for (int i = 0; i < (cnt - 1) * 4; i++)
        printf("_");
    printf("\"����Լ��� ������?\"\n");
    for (int i = 0; i < (cnt - 1) * 4; i++)
        printf("_");
    printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
    for (int i = 0; i < (cnt - 1) * 4; i++)
        printf("_");
    printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
    for (int i = 0; i < (cnt - 1) * 4; i++)
        printf("_");
    printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
    if (cnt == N)
    {

        for (int i = 0; i < cnt * 4; i++)
            printf("_");
        printf("\"����Լ��� ������?\"\n");
        for (int i = 0; i < cnt * 4; i++)
            printf("_");
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
        for (int i = 0; i < cnt * 4; i++)
            printf("_");
        printf("��� �亯�Ͽ���.\n");
        return;
    }
    recur(cnt + 1);
    for (int i = 0; i < cnt * 4; i++)
        printf("_");
    printf("��� �亯�Ͽ���.\n");
}

int main()
{
    scanf("%d", &N);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");

    recur(1);
    printf("��� �亯�Ͽ���.\n");
    return 0;
}