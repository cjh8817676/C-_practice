// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"
#include "strngbad.cpp"
//#include "strngbetter.cpp"

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);                     //call by reference
        cout << "headline1: " << headline1 << endl;
        cout << "�`�N------" << endl;
        callme2(headline2);                      //call by value �|�X���D(�Y�O�����D���ƻ�|�X���D�A�H��N�ɶq�ϥ�call by reference�N�S�ƤF)
        cout << "headline2: " << headline2 << "   �X�{�_�Ǫ��r�ꤺ�e(�Q�R���F)" << endl;
        cout << "�`�N^^^^^^" << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;     //�Nsports�Ω�"��l��"sailor(���󪺪�l�ƥi�H�����ϥΨ�L����)�A���Onum_strings �S��++
                                        //�]���O�Nsports����ƽƻs�L�h���C
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;         //�o�����M�|��num_strings ++
        knot = headline1;       //�AC++ �o�سB�̤覡 �|�� headline1 ���� �ƻs�L�h
                                //�ҥH�i�H�o�{ headline1 �B knot �ѦҦP�@�Ӧ�}�������!!!(�b4_assignment_operator_invoke�ѨM)
        cout << "knot: " << knot << endl; 
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";    //�|�S�����o�O�]��"�sĶ��"�����D�A���s��"�sĶ��"�b����ٳ�-1�Ӫ��󪺱��p�U�פ�{��
                                  //�o�Ӿ���٬�(GPF)General Protection Fault: �N���O���@�ӵ{���Q�n�s�����ݩ�L���O����Ŷ��C
                                  
    /*����: �Q���槹�ӵ{���A��call by value �������R���γ��令 call by reference�N�i�H*/
    /*���� delete���� �P new������  �O�ۤϪ��A �]���A��Stack�h�˪�*/
    /*�ҥH�̥��Qdelete������O  knots �B sailor �Bspot �Bheadline2 �B headline1*/
    // std::cin.get();
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{   
    /*�Hheadline2�@���޼ƩI�s �|���ͫغc�禡���I�s(StringBad sb���ͩI�s  ���Onum_strings �S��++)*/
    /*����sb �P ����headline2 �O��call by value �o�覡�ǻ��A�ҥH�L�̨ƹ�W�O�ѦҦP�Ӫ���*/
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
    /*�o�Ө�Ƶ�������|StringBad sb�|�Q���A���ɩI�s�Ѻc��ơA�ɭP( static int num_strings --)*/
    /*�o�ɤS�]�� ���� sb delete�����O�����} �̵M�Qheadline2�ѦҵۡA�ҥHheadline2�]�Q�R����!!!!!!!!!!!!!!!!!!!!!!!!*/
    
}

/*(54�檺StringBad sb) �P (29��) �������P�u����[���O�νƻs���󪺤覡((�H�ȶǻ�))]�ɭP����num_strings �S��++*/
/*(num_strings �S��++ �O�]���b""�ƻs����""���ɭ�  �sĶ���|����(�@)���ثغc��ƥs��  �ƻs�غc���(copy structor))*/
/*"�H�ȶǻ�"��ܷ|���ͭ�l�ܼƪ��ƥ��A�u�n���Ͱƥ��A�sĶ�{���|�۰ʨϥ� �ƻs�غc���(copy structor)*/
/*�ƻs�غc���(copy structor) �����D�n��s static int num_strings*/
