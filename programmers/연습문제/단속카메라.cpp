// https : //programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    //�⺻ ī�޶� 1��
    int answer = 1;
    //���� ����Ʈ ����
    sort(routes.begin(), routes.end());
    //�񱳸� ���� ó������ ������ �κ� üũ
    int temp = routes[0][1];
    //����Ʈ ��ȸ�ϱ�
    for (auto a : routes)
    {
        printf("%dvs %d %d\n", temp, a[0], a[1]);
        //���� ���� ������ �κк��� �ڿ� ���� ���´ٸ�
        if (temp < a[0])
        {
            printf("temp : %d  a[0] : %d     %d\n", temp, a[0], a[1]);
            //ī�޶� ��ġ
            answer++;
            //������ �κ� ����
            temp = a[1];
        }
        // ���� ������ ������ ����������
        if (temp >= a[1])
            temp = a[1]; // ������ �κ��� ������ ����
    }
    return answer;
}

void print(vector<vector<int>> routes, int answer)
{
    int t = solution(routes);
    if (t == answer)
        cout << "����" << endl;
    else
        cout << "Ʋ��" << endl;
}

int main()
{
    print({{-20, 15}, {-14, -5}, {-18, -13}, {-5, -2}, {-4, -3}, {1, 13}}, 3);
    return 0;
}