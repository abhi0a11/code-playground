#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverse(string str, int i, int j)
{
    // base case
    if (i > j)
        return str;

    swap(str[i], str[j]);
    i++;
    j--;

   return reverse(str, i, j);
}

// pass by reference 
void reverseByValue(string& str, int i, int j)
{
    cout<<"call received for "<<str<<endl;
    // base case
    if (i > j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;

    reverseByValue(str, i, j);
}
int main()
{
    string s = "abcde";
    string ss = reverse(s, 0, (s.length() - 1));
    cout << ss << endl;

    reverseByValue(s,0, (s.length() - 1));
    cout<<s<<endl<<endl;
    return 0;
}