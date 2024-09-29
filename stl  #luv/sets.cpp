#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printSet(set<string> &s)
{
    for (auto value : s)
    {
        cout << value << endl;
    }
}
void printUnoSet(unordered_set<string> &s)
{
    for (auto key : s)
    {
        cout << key << endl;
    }

    // for(auto it = s.begin(); it != s.end(); it++){
    //     cout<<(*it)<<endl;
    // }
}
void printMultiSet(multiset<string> &s)
{
    for (auto key : s)
    {
        cout << key << endl;
    }
}

int main()
{

    //red black tree implementaion
    set<string> s; // only unique value are allowed in sets
    s.insert("abc"); // log(n)
    s.insert("zsdf");
    s.insert("bcd");

    printSet(s); // set stores value in sorted order
    /*

    auto it = s.find("abc");  //log(n)
    // if(it != s.end()) cout<<(*it);

    s.erase(it);  // deletes value in set
    // s.erase("abc");
    cout<<endl;
    printSet(s); // set stores value in sorted order

    */
    
        unordered_set<string> se; // hash table implementaion
                                  //  only unique value are allowed in unordered_set
        se.insert("abc"); // O(1)
        se.insert("zsdf");
        se.insert("bcd");

        // auto it = se.find("abc");  //O(1)
        printUnoSet(se);

    

    // multiset<string> set; // hash table implementaion
    //                       //  duplicate value are allowed in multiset
    // set.insert("abc");    // O(1)
    // set.insert("zsdf");
    // set.insert("bcd");
    // set.insert("bcd"); // can insert multiple values

    // // set.erase("bcd"); // dont use it as it will erase all occourance of bcd
    // // log(n) operation as red black tree implementation
    // auto it = set.find("bcd"); // delete like this
    // if (it != set.end())
    //     set.erase(it);de

    // printMultiSet(set);
    cout<<endl<<endl;
    unordered_set<int> stt;
    stt.insert(102);
    stt.insert(1);
    stt.insert(100);
    stt.insert(101);
    stt.insert(2);
    stt.insert(4);
    stt.insert(3);

    for(auto i:stt){
        cout<<i<<endl;
    }
    return 0;
}