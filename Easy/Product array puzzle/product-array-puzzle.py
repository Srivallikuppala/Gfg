#User function Template for python3

class Solution:
    def productExceptSelf(self, nums, n):
        #code here
        x = 1
        for i in nums:
            if i!=0:x = x*i
        r =[]
        if nums.count(0)>1:
            r = [0]*len(nums)
        elif nums.count(0)==1:
            for i in nums:
                if i==0:r.append(x)
                else:r.append(0)
        else:
            for i in nums:
                r.append(x//i)
        return r


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())

    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().split()]

        ans=Solution().productExceptSelf(arr,n)
        print(*ans)
# } Driver Code Ends