/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2016 10:14:44 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;
class Cknap
{
    public:
   
    Cknap(vector<int> &_v,vector<int> &_w,int _weight,int _n):V(_v),W(_w),weight(_weight),n(_n){init();}
    int opt_v(int wght,int n)
    {
        //cout<< "weight:"<<wght<<"  n:"<<n<<endl;
        if(n==0||wght==0)
        return 0;
        if(W[n]>wght)
        return opt_v(wght,n-1);
        int sel_n=opt_v(wght-W[n],n-1)+V[n];
        int d_sn =opt_v(wght,n-1);
        if(sel_n>=d_sn)
        {
            //cout<<sel_n<<endl;
            return sel_n;
        }
        else 
        {
            return d_sn;
        }
    }
    private:
    vector<int> V;//价值数组0-n,0不用
    vector<int> W;//重量数组0-w,0不用
    int weight;//重量
    int n;//输入大小
    void init()
    {
        int i;//X wei
        int j;//Y value;
        vector<int> wei;//重量数组，X坐标
        for(j=0;j<n+1;j++)
        {
            for(i=0;i<weight+1;i++)
                 wei.push_back(0);
            opt.push_back(wei);
        }

        //填充数据opt[n][w]
        for(i=1;i<n+1;i++)//只有前i个元素时
        {
            for(j=1;j<weight+1;j++)//
                {
                    if( W[i] > j )
                    {
                        opt[i][j]=opt[i-1][j];
                        cout<< opt[i][j]<<" ";
                    }
                    else
                    {
                        int val1=opt[i-1][j-W[i]]+V[i];
                        //cout<< "val1:"<<val1<<"i-1 :"<<i-1<<"  J:"<<weight-W[j]<<endl;
                        int val2=opt[i-1][j];
                        //cout<< "val2:"<<val2<<endl;
                        opt[i][j] = val1>=val2?val1:val2;
                        cout<<opt[i][j]<<" ";
                    }
                }
            cout<<endl;
        }    
    }
    vector< vector<int> >  opt;
};

int main()
{
    int W=100,N=26;
    vector<int> vec_v={0,1,6,8,12,15,18,30,31,33,39,40,41,43,44,45,46,47,50,70,80,90,91,92,93,94,95};
    vector<int> vec_w={0,1,2,5,6,7,10,20,21,24,28,29,31,33,35,37,39,40,41,45,5,52,54,58,60,62,64,66};
    Cknap nap(vec_v,vec_w,W,N);
    cout<<nap.opt_v(W,N);
    return 0;
}
