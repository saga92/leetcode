#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=-1,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(j!=-1){
                    nums[j]=nums[i];
                    j++;
                }
            }else{
                if(j==-1){
                    j=i;
                }
                count++;
            }
        }
        int len=nums.size()-count;
        for(int k=len;k<nums.size();k++){
            nums[k]=0;
        }
    }
};
