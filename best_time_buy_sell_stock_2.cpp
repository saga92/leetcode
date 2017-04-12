#include<vector>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int maxPro=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]<prices[i]){
                maxPro+=(prices[i]-prices[i-1]);
            }
        }
        return maxPro;
    }
};

