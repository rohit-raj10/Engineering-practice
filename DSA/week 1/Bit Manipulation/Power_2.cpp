#include <bits/stdc++.h>
using namespace std;

int powerOf2(int n){
    int count=0;
    while(n){
        count+=n&1;

        n>>=1;
    }

    return count==1;

}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "power of two " << n << " is " << (powerOf2(n)?"True":"False" )<< endl;
    return 0;
}