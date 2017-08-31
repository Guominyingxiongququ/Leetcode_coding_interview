class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nearest = 0;
        int len = nums.size();
        bool first = true;
        int dis = 0;
        for(int i=0;i<len-2;i++)
        {
            int rest_target = target-nums[i];
            int begin = i+1;
            int end = len-1;
            if(first)
            {
                first = false;
                nearest = nums[begin] + nums[end] + nums[i];
                dis = abs(target-nearest);
            }
            while(begin<end)
            {
                int cur_result = nums[begin] + nums[end];
                
                if(abs(cur_result-rest_target)<dis)
                {
                    dis = abs(cur_result-rest_target);
                    nearest = cur_result + nums[i];
                }
                
                if(nums[begin]+nums[end] > rest_target)
                {
                    end--;
                }
                else
                {
                    begin++;
                }
            }
        }
        return nearest;
    }
};