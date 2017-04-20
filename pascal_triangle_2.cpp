#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0]=1;
        for(int i=0;i<rowIndex+1;i++){
            for(int j=i;j>=1;j--){
                A[j]+=A[j-1];
            }
        }
        return A;
    }
};

int main(){
    Solution solution;
    vector<int> res=solution.getRow(3);
    return 0;
}