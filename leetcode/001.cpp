struct element{
    int value;
    int index;
};

bool compare(element & num1, element & num2)
{
    return (num1.value<num2.value);
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<element> nums_vector = vector<element>(length);
        for(int i=0;i<length;i++)
        {
            nums_vector[i].value = nums[i];
            nums_vector[i].index = i;
        }
        std::sort(nums_vector.begin(),nums_vector.end(),compare);
        int num1;
        int num2;
        int j;
        vector<int> targetVector =vector<int>(2);
        for(int i=0;i<length-1;i++)
        {
            num1 = nums_vector[i].value;
            num2 = target-num1;
            j = search(nums_vector,i+1,length-1, num2);
            if(j!=-1)
            {
                targetVector[0] = nums_vector[i].index;
                targetVector[1] = nums_vector[j].index;
                if(targetVector[0]>targetVector[1])
                {
                    int cur = targetVector[0];
                    targetVector[0] = targetVector[1];
                    targetVector[1] = cur;
                }
                return targetVector;
            }
        } 
    }
    int search(vector<element>& nums, int begin, int end, int target)
    {
        if(begin>end)
            return -1;
        int mid = (begin+end)/2;
        if(nums[mid].value>target)
            return search(nums,begin,mid-1,target);
        if(nums[mid].value<target)
            return search(nums,mid+1,end,target);
        return mid;
    }
};