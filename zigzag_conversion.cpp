#include<string>
#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.size();
        if(numRows==1)
            return s;
        vector<int> nums;
        for(int i=0;i<numRows;i++){
            int j=i;
            int j1=0;
            while(1){
                if(j<len){
                    if(nums.empty()||*(nums.end()-1)!=j)
                        nums.push_back(j);
                }else break;
                j1=j+2*(numRows-1)-i*2;
                if(j1<len) {
                    if (nums.empty() || *(nums.end() - 1) != j1)
                        nums.push_back(j1);
                }else break;
                j+=2*(numRows-1);
            }
        }
        string res;
        for(auto n:nums){
            res+=s[n];
        }
        return res;
    }
};

int main(){
    Solution solution;
    string res=solution.convert("A",2);
    return 0;
}
