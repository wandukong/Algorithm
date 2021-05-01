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
    // 첫번째 글자에서 떨어진 거리 초기화
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

    int idx = 0; // 글자 중 가장 가까운 거리의 글자 인덱스
    while (!loc.empty())
    {
        int moveCnt = 987654321;
        int moveDir = 0;
        for (int i = 0; i < loc.size(); i++) // 바꿔야하는 글자 중 가장 가까운 거 찾기
        {
            if (moveCnt > dist[loc[i]].first)
            {
                moveCnt = dist[loc[i]].first;
                moveDir = dist[loc[i]].second;
                idx = loc[i];
            }
        }
        answer += moveCnt;
        loc.erase(remove(loc.begin(), loc.end(), idx), loc.end()); // 글자 바꾼거 삭제
        if (moveDir == 0)                                          // 왼쪽으로 이동함
        {
            while (moveCnt--) // 이동한 횟수 만큼 dist 함수 옮기기
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