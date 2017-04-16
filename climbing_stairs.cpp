class Solution {
public:
    int climbStairs(int n) {
        int *dp=new int[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

int main(){
    Solution solution;
    int res=solution.climbStairs(4);
    return 0;
}