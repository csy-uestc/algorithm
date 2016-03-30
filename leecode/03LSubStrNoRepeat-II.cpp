/*************************************************************************
	> File Name: 03LSubStrNoRepeat-II.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2016 07:25:39 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
class Solution {
        public:
    int lengthOfLongestSubstring(string s) {
            unordered_map<char,int> m;
            int lastRepeat = -1;
            int maxlen =0;
            for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end() && lastRepeat < m[s[i]])//重复
            {
                lastRepeat = m[s[i]];
                m[s[i]] = i;
            }
            else
            {
                m[s[i]] =i ;
            }
            if(i - lastRepeat > maxlen)
                maxlen = i - lastRepeat;
                
        }
        return maxlen;

    }

};
int main()
{
    Solution so;
    cout<<so.lengthOfLongestSubstring("acca");
    return 0;
    
}
