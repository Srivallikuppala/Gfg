//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int vct[], int low, int mid, int high)
    {
         // Your code here
        int i = low , j = mid+1 , k = 0;
    	int temp[high-low-1];
    	while(i<=mid and j<=high){
    		if(vct[i]>vct[j]) temp[k++] = (vct[j++]);
    		else temp[k++] = (vct[i++]);
    	}
    	while(i<=mid) temp[k++]=(vct[i++]);
    	while(j<=high) temp[k++] = (vct[j++]);
    	for(int i = low ; i <= high ; i++) vct[i]=temp[i-low];
    	return;
    }
    public:
    void mergeSort(int vct[], int low, int high)
    {
        //code here
        if(high<=low) return;
    	int mid = low+(high-low)/2;
    	mergeSort(vct,low,mid);
    	mergeSort(vct,mid+1,high);
    	merge(vct,low,mid,high);
    	return;	
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends