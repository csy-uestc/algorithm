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
class QuickSort {
public:
    int* quickSort(int* A, int n) {
        // write code here
        qSort(A,0,n-1);
        return A;
    }
    void qSort(int * A,int low,int high){
        if(low >= high) return;
        int mid = partion(A,low,high);
        qSort(A,low,mid-1);
        qSort(A,mid+1,high);
    }
    int partion(int * A,int low,int high){
        int key = A[low];
        while(low<high){
            while(low<high && A[high] > key) high--;
            A[low] = A[high];
            while(low<high && A[low] <= key) low++;
            A[high] = A[low];
        }
        A[low] = key;
        return low;

}
};
int main()
{
    int arr[]= {4,3,5,6,7,88,33,1,12,45,678,234,4,5,6,3,2,2,23,3,5,5,6,7,7,4545,5,4,53,24,2,4,3,24,42,4,2,42};
    QuickSort s;
    int n = sizeof(arr)/sizeof(int);
    s.quickSort(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
    return 1;
}
