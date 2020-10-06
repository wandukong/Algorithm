#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

    vector<string> gems{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

int main()
{
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