#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k){
        if(k==0){
            vector<vector<int>> vecList;
            vector<int> vec;
            vecList.push_back(vec);
            return vecList;
        }

        if(n==k){
            vector<vector<int>> vecList;
            vector<int> vec;
            for(int i=1;i<=n;i++){
                vec.push_back(i);
            }
            vecList.push_back(vec);
            return vecList;
        }
        vector<vector<int>> hasN=combine(n-1, k);
        vector<vector<int>> hasNoN=combine(n-1, k-1);
        for(vector<int>& vec:hasNoN){
            vec.push_back(n);
        }
        /*
        for(vector<vector<int>>::iterator it=hasNoN.begin();it!=hasNoN.end();++it){
            (*it).push_back(n);
        }
         */
        hasN.insert(hasN.end(), hasNoN.begin(), hasNoN.end());
        return hasN;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> vecList=solution.combine(2,1);
    return 1;
}