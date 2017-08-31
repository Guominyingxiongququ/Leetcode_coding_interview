class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int pivot = search_pivot(nums,0 ,nums.size()-1);
        int result1 = binary_search(nums,0,pivot,target);
        int result2 = binary_search(nums,pivot+1,nums.size()-1,target);
        if(result1 !=-1)
            return result1;
        else
            return result2;
    }
    int search_pivot(vector<int>& nums,int begin, int end)
    {
        if(begin>=end-1)
        {
            if(nums[end]>nums[nums.size()-1])
                return end;
            else
                return begin;
        }
        int last_num = nums[nums.size()-1];
        int mid = (end+begin)/2;
        if(nums[mid]<last_num)
        {
            return search_pivot(nums,begin,mid-1);
        }
        if(nums[mid]>last_num)
        {
            return search_pivot(nums,mid,end);
        }
    }
    int binary_search(vector<int>& nums,int begin, int end,int target)
    {
        if(begin>end)
            return -1;
        int mid = (begin+end)/2;
        if(nums[mid]>target)
            return binary_search(nums,begin,mid-1,target);
        if(nums[mid]<target)
            return binary_search(nums,mid+1,end,target);
        return mid;
    }
    
};