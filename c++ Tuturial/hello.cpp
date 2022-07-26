#include <iostream>
#include <vector>
using namespace std;
//System header files : It comes with the compilers
//User Defined header files :It is written by the programmer.
//eg // #include this.h
//cpp refrerence
int c = 45;
int main()
{
    int num1, num2, c;
    cout << "Enter the num 1 value :\n"; /* "<< This is insertion Operator"*/
    cin >> num1;                         /* >> Extraction Operator*/

    cout << "\nEnter the num2 value :" << endl;
    cin >> num2;
    c = num1 + num2;
    cout << "\n Answer is :" << num1 / num2;

    cout << ::c; /* ::c its used to access the global variable c whuch is defined outside the main function*/
    // REFERENCE VARIABLE
    int x = 56;
    int &y = x; // & y its going to be the reference variable of x Now what so over tempering will happens it will also efeect the value of y;
    x++;
    cout << endl
         << y;

    // TYPE CASTING
    const float d = 67.78;
    cout << endl
         << int(d);
    int age;
    cout << "Enter your age" << endl;
    cin >> age;
    switch (age)
    {
    case 13:
        cout << "I am 13 ";
        break;

    default:
        cout << "I am not 13";
        break;
    }

    return 0;
}