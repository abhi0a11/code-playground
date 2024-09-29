#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = a;
        a = b;
        b %= temp;
    }
    return a;
}
// int gcd(int a, int b)
// {
//     if (a == 0)
//     {
//         return b;
//     }
//     if (b == 0)
//     {
//         return a;
//     }

//     while (a != b)
//     {
//         if (b > a)
//         {
//             swap(a, b);
//         }

//         a = a - b; // or a%b
//     }

//     return a;
// }

int lcm(int a, int b)
{
    return (a * b / gcd(a, b));
}
int main()
{
    int a, b;
    cout << "Enter the values of a and b" << endl;
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << "Gcd of a ans b is: " << ans << endl;
    ans = lcm(a, b);
    cout << "Lcm of a ans b is: " << ans;

    return 0;
}

// lcm(a,b) * gcd(a,b)  = a*b