#include<vector>
#include <limits.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), prev_buy(0), sell(0), prev_sell(0);
        for(int price:prices){
            prev_buy=buy;
            buy=max(prev_sell-price, buy);
            prev_sell=sell;
            sell=max(prev_buy+price, sell);
        }
        return sell;
    }
};
