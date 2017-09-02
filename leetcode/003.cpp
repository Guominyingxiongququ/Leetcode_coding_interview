class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> sMap = map<char,int>();
        int len = s.size();
        int max = 0;
        int max_start = 0;
        int cur = 0;
        int cur_start = -1;
        int begin_1=-1;
        for(int i=0;i<len;i++)
        {
            if(sMap.find(s[i])==sMap.end())
            {
                    sMap[s[i]] = i;
                    if(cur_start==-1)
                        cur_start = cur;
                    cur = cur+1;
                    if(cur>max)
                    {
                        max = cur;
                        max_start = cur_start;
                    }
            }
            else
            {
                begin_1 = sMap.find(s[i])->second; 
                sMap[s[i]] = i;
                if(begin_1>=cur_start)
                {
                    cur = cur-(begin_1-cur_start)-1;
                    cur_start = begin_1+1;
                }
                cur = cur+1;
                if(cur>max)
                    max =cur;
            }
        }
        return max;
    }
};