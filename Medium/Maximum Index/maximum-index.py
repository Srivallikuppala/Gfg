#User function Template for python3

class Solution:
    #Complete this function
    # Function to find the maximum index difference.
    def maxIndexDiff(self,a, n): 
        ##Your code here
        x = []
        y = []
        x.append(a[0])
        y.append(a[-1])
        for i in range(1,n):x.append(min(x[i-1],a[i]))
        for j in range(n-2,-1,-1):y.append(max(a[j],abs(y[n-j-2])))
        y = y[::-1]
      #  print(x,y)
        i = j = maxi = 0
        while i<n and j<n:
            if(x[i]<=y[j]):j+=1
            else:
                maxi =max(maxi,j-i-1)
                i+=1
        maxi = max(maxi,j-i-1)
        #print(maxi)
        return maxi

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