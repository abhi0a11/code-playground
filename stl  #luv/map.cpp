#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printMap(map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}

int main(){
    /*
    // MAPS  insertion , access , find == O(logn)
// it arranges all  the elements in increasing order


    map<int, string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4, "afg"});
    m[6]; // empty string{ 0 in case of integer}

    auto it = m.find(3);
    // if(it == m.end()){
    //     cout<<"Not found"<<endl;;
    // }
    // else{
    //     cout<<(*it).first<<" "<<(*it).second<<endl;;
    // }

    // m.erase(3); // deletes value corresponding to id '3'
    m.erase(it); // deletes value corresponding to iterator

    // erase() gives segmentation fault error if value dont exist
    // so put a safety check|
    if (it != m.end())
    {
        m.erase(it);
    }

    m.clear(); // clears map
    printMap(m);
*/




// UNORDERED MAPS
// it arranges all  the elements in order they are inserted other all things are same 

// time complexity is O(1) rather tha O(logn)

unordered_map<int,string> m;
    return 0;
}