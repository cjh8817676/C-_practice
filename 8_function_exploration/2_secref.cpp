// secref.cpp -- defining and using a reference
#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;   // rodents is a reference

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;       // can we change the reference?   no    //reference ���V�S�w�ܼƫ�N���|�A����"��}"�F  
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;
    cout << "rats = " << rats;
    cout << "rodents = bunnies �u�|����rodents���V���O���骺�ƭȡA��rodents���O�����}�ä��|�]������";
    // cin.get();
    return 0; 
}
