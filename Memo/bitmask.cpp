#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int items_flag = 0;

    int opt0 = 1 << 0;
    int opt1 = 1 << 1;
    int opt2 = 1 << 2;
    int opt3 = 1 << 3;

    int items_flag = 0;

    // 비트 켜기 : | , +
    items_flag |= opt0;
    printf("opt0 획득 => 결과 : %s\n", bitset<8>(items_flag).to_string().c_str());
    items_flag |= opt3;
    printf("opt3 획득 => 결과 : %s\n", bitset<8>(items_flag).to_string().c_str());

    // 비트 끄기 : & ~
    items_flag &= ~opt3;
    printf("opt3 잃음 => 결과 : %s\n", bitset<8>(items_flag).to_string().c_str());

    // 비트 켜져있는지 확인
    if (items_flag & opt0)
        cout << "opt1 갖고 있음" << endl;
    else
        cout << "opt1 갖고 있지 않음" << endl;

    if (items_flag & opt3)
        cout << "opt1 갖고 있음" << endl;
    else
        cout << "opt1 갖고 있지 않음" << endl;

    // obtain item2, item3
    items_flag |= (opt2 | opt3);
    printf("opt2, opt3 획득  => 결과 : %s\n", bitset<8>(items_flag).to_string().c_str());

    // xor 연산자 : 비트 토글(1->0, 0->1)
    items_flag ^= opt0;
    items_flag ^= opt1;
    printf("opt0, opt1 비트 토글 => 결과 : %s\n", bitset<8>(items_flag).to_string().c_str());

    return 0;
}