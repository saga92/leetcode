#include<vector>
#include<algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_minor=INT_MAX,res=0;
        if(nums.size()<3)
            return -1;
        sort(nums.begin(),nums.end());
        int j,k,tmp;
        for(int i=0;i<nums.size()-2;i++){
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                tmp=nums[i]+nums[j]+nums[k];
                if(abs(target-tmp)<min_minor){
                    res=nums[i]+nums[j]+nums[k];
                    min_minor=abs(target-tmp);
                }
                if(tmp>target){
                    k--;
                }else if(tmp<target){
                    j++;
                }else{
                    return target;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> li={1,1,1,0};
    Solution solution;
    solution.threeSumClosest(li,-100);
    return 0;
}
