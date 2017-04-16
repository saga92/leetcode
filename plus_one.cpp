#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        vector<int> oneVec={1};
        vector<int> res;
        int i=digits.size()-1;
        int j=oneVec.size()-1;
        int c=0;
        while(i>=0||j>=0||c!=0){
            c += i>=0? digits[i--]:0;
            c += j>=0? oneVec[j--]:0;
            res.insert(res.begin(), c%10);
            c/=10;
        }
        return res;
    }
};

int main(){
    vector<int> digits={9,9};
    Solution solution;
    solution.plusOne(digits);
}