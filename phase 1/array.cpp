#include <iostream>
using namespace std;

int getMax(int arr[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        max = max + arr[i];
    }
    return max;
}
// to check if a number is power of '2' or not
// trick - if number of set bits is 1 then it is power of '2'

// void isPowTwo(){
//     int size;
//     cout<<"Enter a number"<<endl;
//     cin>>size;
//     int i=0,bit,count=0;
//     while (size!=0)
//     {
//         bit = size&1;
//         if (bit==1)
//         {
//             count++;
//         }
//        size= size>>1;
//         i++;
//     }
//     if (count == 1)
//     {
//         cout<<"multipl of 2"<<endl;
//     }
//     else cout<<"not a multiple of 2"<<endl;

// }

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

void reverseArray(int arr[],int size){

    // for (int i = 0; i < size/2; i++)
    // {
    //     int temp = arr[i];
    //     arr[i]=arr[size-1-i];
    //     arr[size-1-i]=temp;
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    int start=0;
    int end= size-1;
    for (int i = 0; start<=end; i++)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    // int arr[10]={2,7,1,-4,11};
    // cout<<getMax(arr,5);

    // isPowTwo();

    int arr1[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
//    bool found= search(arr1, 10, 22);
//     if (found)
//     {
//         cout<<"Element found";
//     }
//     else cout<<"Absent";
    reverseArray(arr1,10);
    return 0;
}