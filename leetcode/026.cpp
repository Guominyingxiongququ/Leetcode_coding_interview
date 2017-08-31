class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int count=0;
        int cur;
        for(int i=0;i<len;i++)
        {
            if(count == 0)
            {
                cur = nums[i];
                count++;
            }
            else
            {
                if(nums[i]!=cur)
                {
                    cur = nums[i];
                    count++;
                    nums[count-1] = nums[i]; 
                }
            }
        }
        return count;
    }
};