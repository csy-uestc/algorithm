/*************************************************************************
	> File Name: 338CountingBits.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2016 07:35:35 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> countBits(int num) {
    int i=0;
    vector<int> vec;
        for(;i<=num;i++)
        vec.push_back(cntBit(i));

        return vec;
    }
    int cntBit(int num)
    {
        int count=0;
        for(;num>0;num /= 2)
        {
            if(num & 0x1)
                count++;       
        }
        return count;
    }
};
int main()
{
    Solution so;

    vector<int> ve = so.countBits(10);
    for(int i=0;i<ve.size();i++)
        cout<<ve[i]<<endl;
    return 0;
}
