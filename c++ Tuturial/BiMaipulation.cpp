#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getBitAtPos(int n, int pos)
{
    // get bit of certain position of a number like 5 = 0101
    /*
    n=5=>0101 , pos = 2
    1<<pos => 0100
    Now 0101
       &0100
       ------
        0100
       ------
    there for at position 2 we have 1 as a bit in 5 number
*/
    int temp = 1 << pos;
    return (n & temp) != 0 ? 1 : 0;
}
int setBitAtPos(int n, int pos)
{ // this will set a bit at given position in a number
    /*
    suppose n=5=>0101
    pos = 2         if pos=1
    1<<pos=>0100    1<<pos=>0010
    Now  0101       Now  0101
       | 0100           |0010
       -------          ------
         0101            0111
       -------          ------
       It means if there will be 1 at that position then it will simply be as it is if
       not then it will get set 1;
    */
    int temp = 1 << pos;
    return (n | temp);
}
int clearBit(int n, int pos)
{ // in this we will clear bit at that position means make it "0".
    /*
    suppose n=5=>0101
    if pos=2
    1<<pos =>0100
    we will take 1's complement of this
    ~0100 =>1011
    Now,
    0101
  & 1011
    ----
    0001 ->answer
    ----
    */
    int mask = ~(1 << pos);
    return (n & mask);
}

int updateBitAtPos(int n, int pos, int bit)
{ // its nothing but clear and set bit;
    if (bit == 0)
    {
        // get bit at that position if its zero
        if ((n & (1 << pos)) == 0)
        { // it means zero is already there no need to set
            return n;
        }
        else
        {
            // else clear bit at that pos and return
            int mask = ~(1 << pos);
            return (n & mask);
        }
    }
    // if bit=1 then get bit at that pos
    if ((n & (1 << pos)) != 0)
    { // it means already there is a 1 bit so no need to change just return
        return n;
    }
    // there is 0 we need to set it 1 there and then return
    int mask = 1 << pos;
    return (n | mask);
}

int main()
{
    cout << getBitAtPos(5, 2) << " " << setBitAtPos(5, 1) << endl;
    cout << clearBit(5, 0) << " " << updateBitAtPos(5, 3, 0) << endl;
    // 00101 -> 10101
    cout << updateBitAtPos(5, 4, 1) << endl;

    return 0;
}