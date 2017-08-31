#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int begin = 0;
        int end = length-1;
        int maxArea=0;
        while(begin<end)
        {
            int shorter_line;
            bool forward;
            cout<<height[begin]<<" "<<height[end]<<endl;
            if(height[begin]>=height[end])
            {
                shorter_line = height[end];
                forward  = false;
            }
            else
            {
                shorter_line = height[begin];
                forward = true;
            }
            int curArea = shorter_line*(end-begin);
            if(maxArea<curArea)
                maxArea = curArea;
            if(forward)
                begin++;
            else
                end--;
            
        }
        return maxArea;
    }
};

int main()
{
    Solution test = Solution();
    int n[2] = {0,2};
    vector<int> height = vector<int>(n,n+2);
    cout<<test.maxArea(height)<<endl;
    return 0;
}