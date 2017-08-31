class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i;
        int min = -1;
        for(i=len-1;i>=0;i--)
        {
            if(nums[i]<min)
            {
                break;
            }
            else
            {
                min = nums[i];
            }
        }
        if(i==-1)
        {
            for(int j=0;j<(len/2);j++)
            {
                int cur = nums[j];
                nums[j] = nums[len-1-j];
                nums[len-1-j] = cur;
            }
        }
        else
        {
            int cur_exchange = nums[i];
            for(int j=len-1;j>=0;j--)
            {
                if(nums[j]>cur_exchange)
                {
                    nums[i] = nums[j];
                    nums[j] = cur_exchange;
                    break;
                }
            }
            int last = len-(len-1-i)/2;
            for(int k=len-1;k>=last;k--)
            {
                int cur = nums[k];
                nums[k] = nums[len+i-k];
                nums[len+i-k] = cur;
            }
        }
    }
};