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
//insert order : the best conditon compare n-1,dont move element; this is the conditon of element self is ordered;
//and it needs only a extra space;
//average :time complexity:O(n^2) space:O(1)
//ac in CowCode
void insSort(int * A ,int n)
{
    int key = 0,k=0;
    for(int i =1 ;i<n;i++)
    {
        key = A[i];
        for( k=i-1;k>-1;k-- )
        {
            if(A[k] > key)  A[k+1] = A[k];
            else break;
        }
        A[++k] = key;
    }

}
int main()
{
    int arr[] = {3,5,1,4,6,87};
    int n = sizeof(arr)/sizeof(int);
    insSort(arr,n-1);//n is xi biao
        for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 1;
}
