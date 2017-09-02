class Solution {
public:
    string longestPalindrome(string s) {
        char sNew[2004];
        int maxS[2004];
        int len1 = s.size();
        sNew[0] ='$';
        for(int i=0;i<len1;i++)
        {
            sNew[2*i+1] =s[i];
            sNew[2*i+2] = '$';
        }
        sNew[2*len1+1] = '@';
        int maxLen = 1;
        int mid = 0;
        int maxRight = 0;
        int maxMid = 0;
        for(int i=1;i<2*len1+2;i++)
        {
            int len = 1;
            if(i>maxRight)
            {
                while(i-len>=0&&sNew[i+len]!='@')
                {
                    if(sNew[i-len]!=sNew[i+len])
                    {
                        break;
                    }
                    else
                    {
                        len++;
                        if(len>maxLen)
                        {
                            maxLen = len;
                            maxMid = i;
                        }
                    }
                }
                maxS[i] = maxLen;
            }
            else
            {
                int j = 2 * mid - i;
                int minLen = min(maxS[j] , maxRight-i);
                len = minLen;
                while(i-len>=0&&sNew[i+len]!='@')
                {
                    if(sNew[i-len]!=sNew[i+len])
                    {
                        break;
                    }
                    else
                    {
                        len++;
                        if(len>maxLen)
                        {
                            maxLen = len;
                            maxMid = i;
                        }
                    }
                }
            }
            
            maxS[i] = len;
            if(i+len-1>maxRight)
                mid = i;
            maxRight = max(mid + len-1, maxRight);
        }
        string result = "";
        for(int i= maxMid-maxLen+1;i<=maxMid+maxLen-1;i++)
        {
            if(sNew[i]!='$'&&sNew[i]!='@')
            {
                result = result+sNew[i];
            }
        }
        return result;
    }
};