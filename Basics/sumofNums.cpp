#include <iostream>
using namespace std;

int sumofNum(int n){ //functional recursion where we returns something  as a function rahther than printing in the same function
    if(n == 0){
        return 0;
    }
    
    return n + sumofNum(n-1);
}

int main()
{
    int n;
    cin >> n;

    int a = sumofNum(n);
    
    cout << a << endl;
    return 0;
}