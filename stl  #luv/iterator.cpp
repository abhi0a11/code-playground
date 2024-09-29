#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // ITERATOTS

        vector<int> v = {2, 3, 5, 6, 7};

        vector<int>::iterator iter = v.begin();

        cout << (*(iter + 1)) << endl;

    //     for (iter = v.begin(); iter < v.end(); ++iter)
    //     {
    //         cout << *iter << " ";
    //     }
    // cout<<endl;
    //     vector<pair<int, int>> v_pair = {{1, 2}, {3, 4}, {5, 6}};

    //     vector<pair<int, int>>::iterator p;

    // for (p = v_pair.begin() ; p != v_pair.end(); ++p)
    // {
    //     cout << (*p).first << " " << (*p).second << endl;
    //     // cout << p->first << " " << p->second <<endl ;
    // }

    // for(int value: v ){
    //     cout<< value<<" ";
    // }

    // for(pair<int,int> value: v_pair ){
    //     cout<< value.first<<" "<<value.second<<endl;
    // }

    /*
        for(auto data: v){  //same as value approach it creates copy of value and store in data variable
           data++;
        }
        for(auto data: v){
            cout << data << " ";
        }
    */
    /*
        for(auto &data: v){ // now value will increase by 1 as reference in used
           data++;
        }
        for(auto data: v){
            cout << data << " ";
        }
    */
    // for(auto data: v){
    //     cout << data << " ";
    // }


    return 0;
}