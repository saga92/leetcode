#include<vector>

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }

        int* global=new int[k+2]();
        int* local=new int[k+2]();
        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-prices[i-1];
            for(int j=k+1;j>=1;j--){
                local[j]=max(global[j-1]+max(diff,0),local[j]+diff);
                global[j]=max(global[j], local[j]);
            }
        }
        int res=global[k];
        delete[]global;
        delete[]local;
        return res;
    }
};

int main(){
    vector<int> vec={1,4,2,9,4,3};
    Solution solution;
    int res=solution.maxProfit(1000000000,vec);
    return 0;
}