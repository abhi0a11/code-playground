#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printbinary(int n)
{
    for (int i = 7; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

// to check if i'th bit in a number is set or unset.
// a = 0000110101  here indexing start from lsb with 0 .So, 1 is 0'th index 0 is 1st index 1 is 2nd index so on...

void isSetBit(int n, int bitIndex)
{
    if ((n & (1 << bitIndex)) != 0)
    {
        cout << "Set bit" << endl;
    }
    else
    {
        cout << "Not Set \n";
    }
}

// to set a bit in a number
void makeBitSet(int n, int bitIndex)
{
    int ans = (n | (1 << bitIndex));
    printbinary(ans);
}

// to unset a bit in a number
void unsetBit(int n, int bitIndex)
{
    int ans = (n & ~(1 << bitIndex));
    printbinary(ans);
}

// to toggle a bit in a number  ( invert a particular bit use XOR)
void toggleBit(int n, int bitIndex)
{
    int ans = (n ^ (1 << bitIndex));
    printbinary(ans);
}

// count number of set bits

int bitCount(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if ((n & 1))
        {
            cnt++;
        }
        n = n >> 1;
    }
    return cnt;
}

/*  uppercase letters in 5th bit hamesha unset rehti h aur agar usko set krde to vo lowecase m badal jata h..
 convert UPPERCASE  to lowecase by setting 5th bit of UPPERCASE
 convert lowercase to UPPERCASE by unsetting 5th bit of lowercase
*/

void invertCase(char c)
{
    int fifthBit;
    fifthBit = (((int)c >> 5) & 1);

    if ((fifthBit & 1)) // lowercase
    {
        // int ans = (((int)c & ~(1 << 5)));
        // cout << (char)ans << endl;

        /* // alternative way 1

            c = c -'a' + 'A';
            cout<<c;

        */

        // underscore('_') se and(&) krdo UPPERCASE m badal jayega

        c = (c & '_');
        cout << c << endl;
    }

    else // UPPERCASE
    {
        // int ans = ((int)c | (1 << 5));
        // cout << (char)ans << endl;

        /* // alternative way

        c = c -'A' + 'a';
        cout<<c;

    */

    // space (' ') se and(&) krdo lowercase m badal jayega

        c = (c | ' ');
        cout << c << endl;
    }
}
// to unset first i bits from LSB

void unsetSeriesOfBitsFromLSB(int n, int bitnumber)
{
    int ans = (n & ~((1 << bitnumber + 1) - 1));
    printbinary(ans);
}
// to unset first i bits From MSB

void unsetSeriesOfBitsFromMSB(int n, int bitnumber)
{
    int ans = (n & ((1 << bitnumber + 1) - 1));
    printbinary(ans);
}


// to check number is power of 2 or not
/*
example:
binary of 9 = 1001
binary of 8 = 1000

(9 & 8) == 1000 --> non zero thus 'NOT POWER OF 2'

binary of 8 = 1000
binary of 7 = 0111

8 & 7 == 0000 ---> ZERO THUS 'POWER OF 2'


*/

void isPowOf2(int n) {
    if ((n & (n - 1)) == 0) {
        cout << "Power of 2" << endl;
    }
    else {
        cout << "Not a power of 2" << endl;
    }
}
int main()
{
    // int n = 16;

    // printbinary(n);
    // isSetBit(n, 3);

    // makeBitSet(9, 1);
    // unsetBit(9, 3);

    // toggleBit(n, 3);

    // cout << bitCount(n) << endl;
    /*
        cout<< __builtin_popcount(n)<<endl; // built in function for bit count of int numbers
        cout<< __builtin_popcountll(1LL<<35)<<endl; // for long numbers
    */

    // invertCase('T');
    // invertCase('a');

    // unsetSeriesOfBitsFromLSB(n,2);
    // unsetSeriesOfBitsFromMSB(n,2);

    // isPowOf2(n);
    long long num = 1;
    long long ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (((num << i) & 1) == 1)
            ans = num & ~(1 << i);
        else
            ans |= (1 << i);
    }
    // cout<<ans<<endl;
    makeBitSet(num, 31);
    return 0;


}