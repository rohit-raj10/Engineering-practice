#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count=0;
    while(n){
        count+=n&1;

        n>>=1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of 1 bits in " << n << " is " << countSetBits(n) << endl;
    return 0;
}