/*************************************************************************
	> File Name: tem.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2016 03:19:20 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;
class MergeSort {
public:
    void mSort(int* A1, int * A2,int s,int t) {
        // write code here
        if(s>t) return ;
        if( s == t ) A2[s] = A1[s];
        else{
        int mid = (s+t)/2;
        mSort(A1,A2,s,mid);
        mSort(A1,A2,mid+1,t);
        merge(A1,A2,s,mid,t); }
    }
    void merge(int * A1,int * A2,int s,int mid,int t){
        int i = s,j= mid+1,k= s;
        for(;i<=mid && j<=t;k++)
        {
            if(A1[i] < A1[j])  A2[k] = A1[i++];
            else  A2[k] = A1[j++]; 
            cout<<A2[k]<<"..."<<endl;
        }
        if(i<= mid)
        while(i<= mid) A2[k++] = A1[i++];
        else
        while(j<= t) A2[k++] = A1[j++];
    }
};
int main()
{
    int arr[] = {3,443,3,5456,4,5,53,434,34,3434,3};
    int marr[sizeof(arr)/sizeof(int)];
    MergeSort m;
    m.mSort(arr,marr,0,4);
    for(int i = 0 ;i<11;i++)
        cout<<marr[i]<<endl;

    return 1;
}
