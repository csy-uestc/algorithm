/*************************************************************************
	> File Name: 01TwoSum.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2016 02:23:39 PM CST
 ************************************************************************/
#include<iostream>
//#include<hash_map>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> hmap;//存储元素，key为元素的大小，value为元素编号
            vector<int> re;
            int i=0;
            for(;i<nums.size();i++)
            {
                if(hmap.find(nums[i]) ==hmap.end())
                    hmap[target-nums[i]]=i;
                else
                {              
                    re.push_back(hmap[nums[i]]);
                    re.push_back(i);
                    break;
                }
            }
        return re;
    }
};
int main()
{
    vector<int> num={2,4,4};
    int target = 8;
    Solution so;
    vector<int> v=so.twoSum(num,target);
    if(v.size() > 0)
    cout<<v[0]<<"   "<<v[1];
    return 0;
}
