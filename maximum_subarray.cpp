#include <vector>
#include <climits>

using namespace std;
//maxSubArray(arr, i)= maxSubArray(arr,i-1)>0? maxSubArray(arr, i-1) : 0  +arr[i]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int *dp=new int[n];
        dp[0]=nums[0];
        int maxSub=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=nums[i] + (dp[i-1]>0?dp[i-1]:0);
            maxSub=max(maxSub, dp[i]);
        }
        return maxSub;
    }
};

int main(){
    vector<int> vec={-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    int res=solution.maxSubArray(vec);
    return 0;
}