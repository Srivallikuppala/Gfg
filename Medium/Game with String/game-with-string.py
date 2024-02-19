#User function Template for python3

class Solution:
    def minValue(self, s, k):
        # code here
        d = {}
        r = []
        for i in s:
            if i not in d:
                d[i] = 1
            else:d[i]+=1
        for i in d:
            r.append(d[i])
        while(k):
            x = max(r)
            r.remove(x)
            r.append(x-1)
            k-=1
        c = 0
        for i in r:
            c+=i*i
      #  print(c)
        return c
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        k = int(input())
        
        ob = Solution()
        print(ob.minValue(s, k))
# } Driver Code Ends