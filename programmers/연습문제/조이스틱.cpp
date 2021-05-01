// https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int nameSize = name.size();
    vector<int> loc;

    for (int i = 0; i < nameSize; i++)
    {
        int sVal = name[i] - 'A';
        if (sVal != 0)
            loc.push_back(i);
        if (sVal >= 14)
            answer += 26 - sVal;
        else
            answer += sVal;
    }

    pair<int, int> dist[nameSize];
    // ù��° ���ڿ��� ������ �Ÿ� �ʱ�ȭ
    if (nameSize % 2)
    {
        for (int i = 0; i < nameSize; i++)
            if (nameSize / 2 >= i)
                dist[i] = {i, 0};
            else
                dist[i] = {nameSize - i, 1};
    }
    else
    {
        for (int i = 0; i < nameSize; i++)
            if (nameSize / 2 > i)
                dist[i] = {i, 0};
            else
                dist[i] = {nameSize - i, 1};
    }

    int idx = 0; // ���� �� ���� ����� �Ÿ��� ���� �ε���
    while (!loc.empty())
    {
        int moveCnt = 987654321;
        int moveDir = 0;
        for (int i = 0; i < loc.size(); i++) // �ٲ���ϴ� ���� �� ���� ����� �� ã��
        {
            if (moveCnt > dist[loc[i]].first)
            {
                moveCnt = dist[loc[i]].first;
                moveDir = dist[loc[i]].second;
                idx = loc[i];
            }
        }
        answer += moveCnt;
        loc.erase(remove(loc.begin(), loc.end(), idx), loc.end()); // ���� �ٲ۰� ����
        if (moveDir == 0)                                          // �������� �̵���
        {
            while (moveCnt--) // �̵��� Ƚ�� ��ŭ dist �Լ� �ű��
            {
                auto temp = dist[nameSize - 1];
                for (int i = nameSize - 2; i >= 0; i--)
                    dist[i + 1] = dist[i];
                dist[0] = temp;
            }
        }
        else
        {
            while (moveCnt--)
            {
                auto temp = dist[0];
                for (int i = 0; i < nameSize - 1; i++)
                    dist[i] = dist[i + 1];
                dist[nameSize - 1] = temp;
            }
        }
    }
    return answer;
}