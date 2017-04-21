class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        while(n){
            sum+=n/5;
            n/=5;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    int res=solution.trailingZeroes(13);
    return 0;
}