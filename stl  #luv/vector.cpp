#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{

    int n = v.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
     << endl;
}
void printVectorPair(vector<pair<int, int>> &v)
{

    int n = v.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl
         << endl;
}

int main(){
     /*

    pair<int, string> p;

    // p = make_pair(2,"abc");
    p = {2, "abc"};

    pair<int, string> &p1 = p;
    p1.first = 3;

    cout << p.first << " " << p.second << endl;

    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};

    pair<int, int> pairArr[3];

    pairArr[0] = {1, 2};
    pairArr[1] = {2, 3};
    pairArr[2] = {3, 4};

    swap(pairArr[0], pairArr[2]);
    for (int i = 0; i < 3; i++)
    {
        cout << pairArr[i].first << " " << pairArr[i].second << endl;
    }

    */

    //  VECTOR

    /*
    vector<int> v;

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    printVector(v);
    */

    /*
        // we can also create vector of some size which can be increased by push_back() or pop_back() functions

        cout << endl << endl;

        // vector will be initialised with all zeros
        vector<int> v1(10);
        printVector(v1);

        // vector will be initialised with all values entered eg 3 in below case
        vector<int> v2(10, 3);
        printVector(v2);

        v1.push_back(7);
        v1.push_back(6);
        printVector(v1);

        v1.pop_back(); // does not return anything
        printVector(v1);

        vector<int> v3 = v1; // copy vector

    */

    /*
        // VECTOR OF PAIR

        vector<pair<int, int>> v_pair;

        cout << "Enter the size of vector"<<endl;
        int n;
        cin >> n;
        cout << "Enter the value of pair"<<endl;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v_pair.push_back({x, y});
        }

        printVectorPair(v_pair);

    */

    /*
        // array of vector

        // this is array of vector v[0] is a vector , v[1] is another vector similarly upto v[9] there are 10 different vectors.
        vector<int> v[10];

        vector<int> v2[3];

        // taking input
        for (int i = 0; i < 3; i++)
        {
            int n;
            cout << "Enter the size of vector" << endl;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                v2[i].push_back(x);
            }
        }

        // printing all  array of vectors
        for (int i = 0; i < 3; i++)
        {
            printVector(v2[i]);
        }

        // cout<< v[0][1]; // will print element at index 1 of 0th vector i.e v[0]. {behave like 2d array}
    */

    /*
        // vector of vector

        vector<vector<int>> v;

        // taking input
        int row = 3;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;

            int col_size = 3;
            cout << "Enter the value of elements" << endl;
            for (int j = 0; j < col_size; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }

        // printing vector
        for (int i = 0; i < v.size(); i++)
        {
            printVector(v[i]);
        }
    */
    return 0;
}