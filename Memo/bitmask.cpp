#include <iostream>
#include <bitset>

using namespace std;

int main()
{

    // mask
    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;

    unsigned char items_flag = 0;
    cout << "No item " << bitset<8>(items_flag) << endl;

    // item0 on : bitwise or 연산자 -> mask에 1로 설정된 비트 켜기
    items_flag |= opt0;
    cout << "Item0 obtained " << bitset<8>(items_flag) << endl;

    // item3 on
    items_flag |= opt3;
    cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

    // item3 off  : bitwise and 연산자 + not 연산자
    items_flag &= ~opt3;
    cout << "Item3 lost " << bitset<8>(items_flag) << endl;

    // has item1 ? mask를 갖고 있는지 아닌지 확인
    if (items_flag & opt1)
        cout << "Has Item1" << endl;
    else
        cout << "Not have Item1" << endl;

    // has item0 ?
    if (items_flag & opt0)
        cout << "Has Item0" << endl;

    // obtain item2, item3
    items_flag |= (opt2 | opt3);
    cout << "Item2, Item3 obtained " << bitset<8>(items_flag) << endl;

    // xor 연산자 : 비트 토글(1->0, 0->1)
    if ((items_flag & opt2) && !(items_flag & opt1))
    {
        items_flag ^= opt2;
        items_flag ^= opt1;
    }
    cout << bitset<8>(items_flag) << endl;

    return 0;
}