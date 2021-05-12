#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, ans;
int arr[205];
bool robot[105];

void moveBelt()
{
    for (int i = N * 2 - 1; i >= 0; i--) // ��Ʈ �̵�
        arr[i + 1] = arr[i];
    arr[0] = arr[2 * N];

    for (int i = N - 2; i >= 0; i--) // ��Ʈ �̵��� ���� �κ� �̵�
        if (robot[i])
        {
            robot[i + 1] = true;
            robot[i] = false;
        }
    robot[N - 1] = false; // �κ� ������
}

void moveRobot()
{
    for (int i = N - 2; i >= 0; i--) // �κ� �̵�
        if (robot[i] && !robot[i + 1] && arr[i + 1] > 0)
        {
            robot[i + 1] = true;
            robot[i] = false;
            arr[i + 1]--;
        }
    robot[N - 1] = false;        // �κ� ������
    if (!robot[0] && arr[0] > 0) // �κ� �ø���
    {
        robot[0] = true;
        arr[0]--;
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N * 2; i++)
        scanf("%d", &arr[i]);
    while (true)
    {
        ans++;
        moveBelt();
        moveRobot();
        int cnt = 0;
        for (int i = 0; i < 2 * N; i++)
            if (arr[i] <= 0)
                cnt++;
        if (cnt >= K)
            break;
    }
    printf("%d", ans);
    return 0;
}