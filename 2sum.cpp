#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        typedef std::unordered_map<int, int> MAP;
        MAP numMap;
        MAP idxMap;
        std::vector<int> resultVec;
        for(int i=0; i<nums.size(); ++i){
            numMap.insert({nums.at(i), target-nums.at(i)});
            idxMap.insert({nums.at(i), i});
        }
        // 2 + 2 = (target = 4)
        if(target % 2 == 0){
            MAP::iterator it;
            if((it = numMap.find(target >> 1)) != numMap.end()){
                for(int i=0; i<nums.size(); ++i){
                    if(nums.at(i) == it->first){
                        resultVec.insert(resultVec.end(), i);
                        if(resultVec.size() == 2) {
                            return resultVec;
                        }
                    }
                }
                numMap.erase(it);
            }
        }
        //
        resultVec.clear();
        for(MAP::iterator iter = numMap.begin(); iter != numMap.end(); ++iter){
            int anotherInt = iter->second;
            MAP::iterator it;
            if((it=numMap.find(anotherInt)) != numMap.end()){
                resultVec.insert(resultVec.end(), idxMap.find(iter->first)->second);
                resultVec.insert(resultVec.end(), idxMap.find(it->first)->second);
                return resultVec;
            }
        }
        return resultVec;
    }

};

int main(){
    std::vector<int> vec={3,3};
    Solution solution;
    std::vector<int> result =  solution.twoSum(vec, 6);
    return 0;
}
