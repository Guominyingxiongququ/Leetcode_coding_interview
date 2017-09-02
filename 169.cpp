class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> nums_map = map<int,int>();
        int len = nums.size();
        if(len==1)
            return nums[0];
        for(int i=0;i<len;i++)
        {
            if(nums_map.find(nums[i])!=nums_map.end())
            {
                int count = nums_map.find(nums[i])->second + 1;
                nums_map[nums[i]] = count;
                if(count>len/2)
                    return nums[i];
            }
            else
            {
                nums_map[nums[i]] = 1;
            }
        }
        return 0;
    }
};