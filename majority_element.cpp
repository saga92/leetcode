#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0], count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0){
                majority=nums[i];
                count++;
            }else if(nums[i]==majority){
                count++;
            }else{
                count--;
            }
        }
        return majority;
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
 */
