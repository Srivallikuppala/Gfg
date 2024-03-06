#User function Template for python3

class Solution:
    def search(self, pattern, text):
        # code here
        t = []
        for i in range(0,len(text)-len(pattern)+1):
            #print(i)
            if text[i:len(pattern)+i]==pattern:
                t.append(i+1)
        return t




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends