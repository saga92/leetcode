#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<3)
            return 0;
        vector<bool> boolVec(n, true);
        for(int i=2;i<n;i++){
            if(!boolVec[i])
                continue;
            int j=2;
            while(i*j<n){
                if(boolVec[i*j]){
                    boolVec[i*j]=false;
                }
                j++;
            }
        }
        int count=0;
        for(int i=2;i<boolVec.size();i++){
            if(boolVec[i])
                count++;
        }
        return count;
    }
};
