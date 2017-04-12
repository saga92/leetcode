#include <vector>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int* local=new int[3]{0,0,0};
        int* global= new int[3]{0,0,0};
        int diff=0;
        for(int i=1;i<prices.size();i++){
            diff=prices[i]-prices[i-1];
            for(int j=2;j>=1;--j){
                local[j]=max(global[j-1]+max(diff,0), local[j]+diff);
                global[j]=max(global[j], local[j]);
            }
        }
        return global[2];
    }
};

int main(){
    Solution solution;
    vector<int> prices={1,4,2,9,4,3};
    int res=solution.maxProfit(prices);
    return 0;
}