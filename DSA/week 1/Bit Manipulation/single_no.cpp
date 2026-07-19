#include <bits/stdc++.h>
using namespace std;

int Single_no(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        count^=arr[i];
    }
    return count;
}



int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Single no is " << Single_no(arr,n) << endl;
}