#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end){
    int size=end-start+1,gap=size;
    do{
        gap=ceil(gap/2.0);
        int i=start,j=start+gap;
        while(j<size){
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            i++,j++;
        }
    } while(gap!=1);

    return;
}

void mergeSort(int *arr,int start,int end){
    if(start<end){
        int mid=start+end>>1;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end);
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}
