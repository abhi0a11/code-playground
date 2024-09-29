#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void update(int **p2)
{
    p2 = p2 + 1;
    // kuch change hoga? - no

    *p2 = *p2 + 1;
    // kuch change hoga? - yes
    **p2 = **p2 + 1;
    // kuch change hoga? - yes
}


int main()
{

    // int i = 5;
    // int *p = &i;
    // int **p2 = &p;

    // cout << endl
    //      << endl
    //      << "sab sahi chal rha h" << endl
    //      << endl;
    // cout << "printing p " << p << endl;
    // cout<< " printing address of p"<< &p;

    // cout << *p2 << endl;

    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl;

    // cout<<endl<<endl;
    // cout<<"before "<< i <<endl;
    // cout<<"before "<< p <<endl;
    // cout<<"before "<< p2 <<endl;
    // update(p2);
    // cout<<"after "<<i<<endl;
    // cout<<"after "<<p<<endl;
    // cout<<"after "<<p2<<endl;


    
    return 0;
}