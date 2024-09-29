#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    string ans ="";
    queue<char> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        //increase count
        count[ch]++;

        //queue me push kro
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                //repeating character
                q.pop();
            }
            else{
                //nnon- repeating character
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())   ans.push_back('#');

    }
    return ans;
    
}

int main(){
    
    return 0;
}