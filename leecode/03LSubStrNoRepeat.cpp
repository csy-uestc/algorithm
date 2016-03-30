/*************************************************************************
	> File Name: 03LSubStrNoRepeat.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2016 04:17:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int s1=0,t=0;//s,t分别代表当前正在求的子串的开始，结束位置
        int maxLen=0,curMaxLen=0;//存储最大子串长度,当前子串最大长度
        int maxs=0,maxt=0;//存储最长子串的位置
        map<char,int> m;//存储s,j位置内子串,int表示字符位置
        vector<int> vec;//存储s1,t

        int k=0;//存储匹配位置
        for(t=s1;t<s.size();t++)
        {
            map<char,int>::const_iterator cit=m.find(s[t]);
            if(cit == m.end())//不重合，则当前子串最长位置加1
            {
                m[s[t]]=t;
                curMaxLen++;
            }
            else
            {
                
                k = cit->second;
                for(int temp=s1;temp<=k;temp++)
                m.erase(s[temp]);//生成新的子串字符集合
                m[s[t]]=t;
                if(curMaxLen > maxLen)//存储最大子串位置及长度
                {
                    maxLen = curMaxLen;
                    maxs = s1;
                    maxt = t;
                }
                curMaxLen = m.size();
                s1=k+1;
            }
        }
        //处理最后子串
        if(curMaxLen > maxLen)//存储最大子串位置及长度
        {
            maxLen = curMaxLen;
            maxs = s1;
            maxt = t;
        }
        cout<< maxs <<"  "<< maxt;
        return maxLen;
    }

};
int main()
{
    Solution so;
    cout<<so.lengthOfLongestSubstring("umvejcuuk");
    return 0;
}
