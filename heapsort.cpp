/*************************************************************************
    > File Name: heapsort.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 25 Jul 2015 02:54:55 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;
void buildHeap(int * A ,int n)
{
	int i = n/2,k =0,pos = 0;
	for(;i>0;i--){
		for(k = 2*i; k<=n; k=2*k){
				if(A[k/2-1] < A[k-1]) pos = k;
				if(k+1<=n && A[k-1] < A[k] && pos==k || pos==0 && A[k/2-1]<A[k]) pos = k+1;   
                if(pos) std::swap(A[k/2-1],A[pos-1]);
                pos = 0;
			}
	}

}
void adjust(int * A ,int s,int t)
{
	int i = 1,k=0,rc = A[s-1];
	for(k=s*2;k<=t;k=k*2){
        if( k<t && A[k-1]<A[k]) k++;
		//if( rc > A[k-1]); break;cause break excute any ;debug find it
        if( rc > A[k-1] ) break;
        A[s-1] = A[k-1];
        s = k;
	}
    A[s-1] = rc;
}
void heapSort(int * A,int n)
{
	for(int i= n/2;i>0;i--)
	adjust(A,i,n);
    for(int i= n;i>0;i--)
    {
        std::swap(A[i-1],A[0]);
        //adjust(A,0,i-1); will cause loop,s = 0 ,t =0;loop any while
        adjust(A,1,i-1);
    }

}
int main()
{
    int arr[] = {43,2,4,342,43,432,433,3,34,2,4,2,4,4424,32,3,3,32,43,543,3,532,432,342,32,1,1,2,2,2,3,3,4,545};
	int n = sizeof(arr)/sizeof(int);

	heapSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	return 0;
}
