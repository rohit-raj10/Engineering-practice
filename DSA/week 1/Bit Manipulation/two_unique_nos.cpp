#include <bits/stdc++.h>
using namespace std;


pair<int,int> findTwoUnique(vector<int>& nums){
    int xorAll=0;

    for(int x:nums){
        xorAll^=x;
    }

    int rightMostSetBit = xorAll & (-xorAll);

    int no1=0;
    int no2=0;

    for(int x:nums){
        if(x & rightMostSetBit){
            no1^=x;
        }
        else {
            no2^=x;
        }
    }

    return {no1,no2};
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    pair<int, int> ans = findTwoUnique(nums);

    cout << ans.first << " " << ans.second;

    return 0;

}
