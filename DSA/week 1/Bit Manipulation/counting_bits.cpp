#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    arr[0]=0;
    for(int i=1;i<=n;i++){
        arr[i]=arr[i>>1]+(i&1);
    }
    for (int x : arr)
        cout << x << " ";

    return 0;
}