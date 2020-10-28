#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> str{"ohhenrie", "charlie", "baesangwook", "obama", "baesangwook", "ohhenrie", "clinton"};
map<string, int> m;

vector<string> gems{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

int main()
{

    //***********************************************
    // 1. map의 크기만큼 키와 데이터  가져오기.
    //***********************************************
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
    }
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        printf("%s %d\n", it->first.c_str(), it->second);

    printf("\n\n\n");

    //***********************************************   //***********************************************
    map<string, int> cart;

    vector<string> treasure = gems;

    sort(treasure.begin(), treasure.end());                                   // 중복제거하기 위해서는 정렬을 먼저 해준다.
    treasure.erase(unique(treasure.begin(), treasure.end()), treasure.end()); // 중복값 제거

    for (int i = 0; i < gems.size(); i++)
        cart[gems[i]]++;

    for (int i = 0; i < cart.size(); i++)
        printf("%s %d\n", treasure[i].c_str(), cart[treasure[i]]);

    return 0;
}