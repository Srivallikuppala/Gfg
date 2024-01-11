#User function Template for python3

class Solution:

    def removeKdigits(self, l,k):
        # code here
        s = []
        for i in range(len(l)):
            while (s and k>0 and s[-1] >l[i]):
                s.pop()
                k-=1
            s.append(l[i])
        while (k>0):
            s.pop()
            k-=1
        i = 0
        while i < len(s) and s[i] == '0':
            i += 1
        if i == len(s):
            return "0"
        return "".join(s[i:])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()
        K = int(input())

        obj = Solution()

        ans = obj.removeKdigits(S, K)

        print(ans)


# } Driver Code Ends