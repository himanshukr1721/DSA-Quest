#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    bool tell = true;
    for(int i = 2; i<n; i++){
        if(n%i==0){
            tell = false;
            break;
        }
    }
    if(tell){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}