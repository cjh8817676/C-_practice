#include <iostream>
int main()
{
    using namespace std;

    int rats = 101;
    int *pt = &rats;
    int & rodents = *pt;  // referemce ��l�ƥѬ���*pt�A�Ϩ�reference��rats
    int bunnies = 50;

    cout << "rats address: " << &rats << endl;
    cout << "pt value " << pt << endl;
    cout << "rodents address :" << &rodents << endl;
    cout << "rodents ���V���Ʀr :" << rodents << endl;
    cout << "bunnies address :" << &bunnies << endl;
    pt = &bunnies;        // ����pt�令���Vbunnies�A�����|����rodents��reference��rats

    cout << "after (pt = &bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (pt = &bunnies;) rodents ���V���Ʀr :" << rodents<<endl;

    rodents = bunnies;

    cout << "after (rodents = bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (rodents = bunnies;) rodents ���V���Ʀr :" << rodents;



}