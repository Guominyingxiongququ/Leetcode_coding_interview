class Solution {
public:
    int trap(vector<int>& height) { 
        int len = height.size();
        if(len==0)
            return 0;
        int max = 0;
        int begin = 0;
        int end = len-1;
        int water = 0;
        while(begin<end)
        {
            if(height[begin]>height[end])
            {
                if(height[end]>max)
                    max = height[end];
                water+=max;
                water-=height[end];
                end--;
            }
            else
            {
                if(height[begin]>max)
                    max = height[begin];
                water+=max;
                water-=height[begin];
                begin++;
            }
        }
        return water;
    }
};