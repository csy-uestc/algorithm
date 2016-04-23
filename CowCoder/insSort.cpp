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
void insSort(int * A ,int n)
{
    int key = 0,k=0;
    for(int i =1 ;i<n;i++)
    {
        key = A[i];
        for( k=i-1;key<A[k];k-- )
        {
            if(k == 0) { k--;break;}
            A[k+1] = A[k];
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
