#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> v = {1, 2, 3, 4, 5};

vector<string> gems{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
vector<string> gems2{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
int main()
{
    //***********************************************
    // 1. 특정 위치 값 제거하기.
    //***********************************************
    v.erase(v.begin() + 1, v.begin() + 3); // 두번째 세번째 제거  // 1 4 5
    // v.erase(v.begin() + n, v.begin() + m)  v[n]~v[m-1] 삭제

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    //***********************************************
    // 2. 특정 위치 값 삽입하기.
    //***********************************************
    v.insert(v.begin() + 1, 3); // 2번째 자리에 3 삽입 // 1 3 4 5

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    //***********************************************
    // 3. 특정 값 삭제하기
    //***********************************************
    v.erase(remove(v.begin(), v.end(), 1), v.end()); // 값 1 제거.
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    gems.erase(remove(gems.begin(), gems.end(), "DIA"), gems.end()); // 중복 값도 다 제거해줌
    for (int i = 0; i < gems.size(); i++)
        printf("%s ", gems[i].c_str());
    printf("\n");

    //***********************************************
    // 4. 중복 값 삭제하기
    //***********************************************

    sort(gems2.begin(), gems2.end());
    gems2.erase(unique(gems2.begin(), gems2.end()), gems2.end()); // 중복 값도 다 제거해줌
    for (int i = 0; i < gems2.size(); i++)
        printf("%s ", gems2[i].c_str());
    printf("\n");

    //***********************************************
    // 5. 특정 값 위치 찾기 find(v.begin(), v.end(), 5) - v.begin()
    //***********************************************

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    find(v.begin(), v.end(), 5) - v.begin();
    printf("5. %d\n", find(v.begin(), v.end(), 5) - v.begin());
}