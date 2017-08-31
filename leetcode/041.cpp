class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if((nums[i]>0)&&(nums[i]<=len)&&(nums[i]!=(i+1)))
            {
                int j = i;
                int cur = nums[j];
                while(cur>0&&nums[cur-1]!=cur&&cur<=len)
                {
                    int exchange = nums[cur-1];
                    nums[cur-1] = cur;
                    cur = exchange;
                }
            }
        }
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=(i+1))
                return i+1;
        }
        return len+1;
    }
};