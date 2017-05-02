#include<vector>
using namespace std;
class Solution {
public:
    inline int left(int idx){
        return (idx<<1)+1;
    }
    inline int right(int idx){
        return (idx<<1)+2;
    }
    void max_heapify(vector<int>& nums, int idx){
        int largest=idx;
        int l=left(idx), r=right(idx);
        if(l<heap_size&&nums[l]>nums[largest]) largest=l;
        if(r<heap_size&&nums[r]>nums[largest]) largest=r;
        if(largest!=idx){
            swap(nums[idx],nums[largest]);
            max_heapify(nums,largest);
        }
    }

    void build_max_heap(vector<int>& nums){
        heap_size=nums.size();
        for(int i=(heap_size>>1)-1;i>=0;i--)
            max_heapify(nums,i);
    }

    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for(int i=0;i<k;i++){
            swap(nums[0], nums[heap_size-1]);
            heap_size--;
            max_heapify(nums,0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};

/*
 * class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int x=nums[right];
        int i=left-1;
        int j=left;
        for(int j=left;j<right;j++){
            if(nums[j]>=x){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[right], nums[i+1]);
        return i+1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1;
        while(true){
            int pos=partition(nums,left,right);
            if(pos==k-1) return nums[pos];
            else if(pos<k-1) left=pos+1;
            else right=pos-1;
        }
    }
};
 * */



int main(){
    vector<int> vec={2,1};
    Solution solution;
    solution.findKthLargest(vec,1);
    return 1;
}
