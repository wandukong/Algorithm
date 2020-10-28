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
    // 1. map�� ũ�⸸ŭ Ű�� ������  ��������.
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

    sort(treasure.begin(), treasure.end());                                   // �ߺ������ϱ� ���ؼ��� ������ ���� ���ش�.
    treasure.erase(unique(treasure.begin(), treasure.end()), treasure.end()); // �ߺ��� ����

    for (int i = 0; i < gems.size(); i++)
        cart[gems[i]]++;

    for (int i = 0; i < cart.size(); i++)
        printf("%s %d\n", treasure[i].c_str(), cart[treasure[i]]);

    return 0;
}