#include <iostream>
using namespace std;
int power()
{
    int a, b;
    cin >> a >> b;
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}
bool isEven()
{
    int num;
    cout << "Enter a number";
    cin >> num;

    if (num % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

bool isPrime(int n)
{

    for (int i = 2; i<n; i++)
    {
        if (n % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
}
void dummy(int &n){
    n++;
    cout<<"n is "<<n<<endl;
}


int update(int a){
    int ans = a*a;
    return ans;
}
int main()
{
    // calculator

    // int a,b;
    // cout<<"Enter the value of a"<<endl;
    // cin>>a;
    // cout<<"Enter the value of b"<<endl;
    // cin>>b;

    // char op;
    // cout<<"Enter a operation to perform"<<endl;
    // cin>>op;
    // switch (op)
    // {
    // case '+':
    //     cout<<(a+b)<<endl;
    //     break;
    // case '-':
    //     cout<<(a-b)<<endl;
    //     break;
    // case '/':
    //     cout<<(a/b)<<endl;
    //     break;
    // case '*':
    //     cout<<(a*b)<<endl;
    //     break;
    // case '%':
    //     cout<<(a%b)<<endl;
    //     break;

    // default: cout<<"Enter a valid operation"<<endl;
    //     break;
    // }

    // cout << power() << endl;
    // cout << isEven() << endl;
    // cout << nCr(8, 2);
    

    // int n;
    // cout << "Enter a nummber"<<endl;
    // cin >> n;
    // // cout << isPrime(n);
    // dummy(n);
    // cout<<"number is "<<n;

    // int a = 14;
    // a = update (a);
    // cout<<a<<endl; 

    
    return 0;
}