class Solution {
public:
    int arrangeCoins(int n) {
        if(n<1)
            return 0;
        long long res=0,i=0;
        while(res<=n){
            i++;
            res=(i+1)*i/2;
        }
        return i-1;
    }
};
