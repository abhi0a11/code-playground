#include <iostream>
using namespace std;

int main()
{
    // fibonacci via array
    // int n,fib[n];
    // cin>>n;
    // fib[0]=0;
    // fib[1]=1;
    //     cout<<fib[0]<<" ";
    //     cout<<fib[1]<<" ";
    // for (int i = 2; i < n; i++)
    // {
    //     fib[i]= fib[i-1]+fib[i-2];
    //     cout<<fib[i]<<" ";
    // }

    // fibonacci normal approach

    // int a=0,b=1,sum=a+b,n;
    // cin>>n;
    // cout<<a<<" "<<b<<" ";
    // for (int i = 0; i < n-2; i++)
    // {
    //     cout<<sum<<" ";
    //     a=b;
    //     b=sum;
    //     sum = a+b;
    // }

    // checking for prime number
    int n;
    cin >> n;
    bool isPrime=1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime=0;
            break;
        }
       
    }
    if (isPrime==0){
        cout << "Not a prime number " << endl;
    }
    else
    {
        cout << "prime number " << endl;
    }
    

    return 0;
}