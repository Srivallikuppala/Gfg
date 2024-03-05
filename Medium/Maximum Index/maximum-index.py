#User function Template for python3

class Solution:
    #Complete this function
    # Function to find the maximum index difference.
    def maxIndexDiff(self,a, n): 
        ##Your code here
        i = 0
        j = n-1
        x = 0
        c = 0
        for i in range(0,n-1):
            j = n-1
            while i<j:
                #print(i,j)
                if a[i]<=a[j]:
                    x = max(x,j-i)
                    if x>=n-2-i:return x
                j-=1
        return x

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            ob=Solution()
            print(ob.maxIndexDiff(arr,n))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends