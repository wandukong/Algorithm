// https : //programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    //기본 카메라 1대
    int answer = 1;
    //들어온 리스트 정렬
    sort(routes.begin(), routes.end());
    //비교를 위해 처음차가 나가는 부분 체크
    int temp = routes[0][1];
    //리스트 순회하기
    for (auto a : routes)
    {
        printf("%dvs %d %d\n", temp, a[0], a[1]);
        //현재 차가 나가는 부분보다 뒤에 차가 들어온다면
        if (temp < a[0])
        {
            printf("temp : %d  a[0] : %d     %d\n", temp, a[0], a[1]);
            //카메라 설치
            answer++;
            //나가는 부분 정정
            temp = a[1];
        }
        // 현재 차보다 뒤차가 먼저나가면
        if (temp >= a[1])
            temp = a[1]; // 나가는 부분을 뒷차로 수정
    }
    return answer;
}

void print(vector<vector<int>> routes, int answer)
{
    int t = solution(routes);
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main()
{
    print({{-20, 15}, {-14, -5}, {-18, -13}, {-5, -2}, {-4, -3}, {1, 13}}, 3);
    return 0;
}