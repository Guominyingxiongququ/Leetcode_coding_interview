class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchRecursive(s,p,0,0);
    }
    
    bool isMatchRecursive(string& s, string& p, int beginS, int beginP)
    {
        int lenS = s.size();
        int lenP = p.size();
        if(beginS==lenS&&beginP==lenP)
        {
            return true;
        }
        else
        {
            if(beginP==lenP&&(beginS!=lenS))
                return false;
            else
            {
                if((beginP!=lenP)&&(beginS==lenS))
                {
                    return checkEnd(p,beginP);
                }
                else
                {
                        if(beginP==(lenP-1)||p[beginP+1]!='*')
                        {
                            if(!isMatchCharacter(p[beginP],s[beginS]))
                                return false;
                            else
                            {
                                return isMatchRecursive(s,p,beginS+1,beginP+1);
                            }
                        }
                        else
                        {
                            if(isMatchRecursive(s,p,beginS,beginP+2))
                            {
                                return true;
                            }
                            else
                            {
                                if(isMatchCharacter(p[beginP],s[beginS]))
                                {
                                    return (isMatchRecursive(s,p,beginS+1,beginP+2)||isMatchRecursive(s,p,beginS+1,beginP));
                                }
                                else
                                {
                                    return false;
                                }
                            }
                        }
                }
            }
        }
    }
    
    bool checkEnd(string & s, int beginP)
    {
        int len = s.size();
        for(int i=beginP;i<len;i++)
        {
            if(s[i+1]!='*'||(i+1)>=len)
            {
                return false;
            }
            i++;
        }
        return true;
    }
    bool isMatchCharacter(char b,char a)
    {
        if(a==b)
            return true;
        else
        {
            if(b=='.')
                return true;
            return false;
        }
    }
};