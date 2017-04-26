#include<vector>
using namespace std;
class Solution{
public:
    //无重复
    int binary_search_1(vector<int> nums, int x){
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>x){
                j=mid-1;
            }else if(nums[mid]<x){
                i=mid+1;
            }else{
                return mid;
            }
        }
        return i;
    }

    //有重复
    int binary_search_2(vector<int> nums, int x){
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=x){
                j=mid-1;
            }else if(nums[mid]<x){
                i=mid+1;
            }
        }
        return i;
    }
};

int main(){
    vector<int> vec={1,3,4,4,4,7,10};
    Solution solution;
    int res=solution.binary_search_2(vec,4);
    return 0;
}
