#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> v1={1};
        vector<int> v2={1,1};
        vector<vector<int>> res;
        if(numRows<1) return res;
        res.insert(res.end(),v1);
        if(numRows==1) return res;
        res.insert(res.end(),v2);
        if(numRows==2) return res;
        for(int i=3;i<=numRows;i++){
            vector<int> v3={1,1};
            vector<int> last=*(res.end()-1);
            for(int i=1;i<last.size();i++){
                v3.insert(v3.begin()+1, last[i-1]+last[i]);
            }
            res.insert(res.end(), v3);
        }
        return res;
    }
};