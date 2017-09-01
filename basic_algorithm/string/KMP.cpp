#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void preset(char *str,int *P)
{
    P[0] = -1;
    int j = 0;
    for(int i = 1;i<sizeof(str);i++)
    {
        if(str[i]=='\0') break;
        while(j>0 && (str[j]!=str[i]))
        {
            j = P[j];
        }
        if(str[j]==str[i])
        {
            j++;
        }
        P[i] = j;
    }

}

int kmpSearch(char *s, char * p, int * next)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while(i<sLen && j<pLen)
	{
		if(j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == pLen)
		return i- j;
	else 
		return -1;
}

int main()
{
    char A[] = "abababaababacb";
    char B[] = "ababacb";
    int sizeB = sizeof(B);
    int P[] = {0,0,0,0,0,0,0,0};

    //预处理B子串，得出捷径数组
    preset(B,P);
    //做KMP算法
    int result = kmpSearch(A,B,P);
    cout<<result<<endl;
    return 0;

}
