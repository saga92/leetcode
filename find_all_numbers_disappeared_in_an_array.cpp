#include<vector>
#include<cmath>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

int main(){
    vector<int> nums(10);
    try{
        nums.at(12)=1;
    }
    catch(...){
        cout<<"out of range"<<endl;
    }

    cout<<nums[12]<<endl;
    return 0;
}
