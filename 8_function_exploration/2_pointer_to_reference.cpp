#include <iostream>
int main()
{
    using namespace std;

    int rats = 101;
    int & rodents = rats;  
    int *pt = &rodents;    // pointer ���V�@��reference
    int bunnies = 50;

    cout << "rats address: " << &rats << endl;
    cout << "rodents address :" << &rodents << endl;
    cout << "rodents �ƭ� :" << rodents << endl;
    cout << "pt value " << pt << endl;
    cout << "*pt value " << *pt << endl;
    cout << "bunnies address :" << &bunnies << endl;
    pt = &bunnies;        // ����pt�令���Vbunnies�A�����|����rodents��reference��rats

    cout << "after (pt = &bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (pt = &bunnies;) rodents ���V���Ʀr :" << rodents<<endl;

    rodents = bunnies;

    cout << "after (rodents = bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (rodents = bunnies;) rodents ���V���Ʀr :" << rodents;



}