#User function Template for python3

class Solution:
    def nthCharacter(self, s, r, n):
        # code here
        # a = len(s)
        # x = 2*r
        # b = (n-1)//x
        # l = s[b]
        # r1 = ""
        # n = n%x
        # while r:
        #     r-=1
        #     for i in l:
        #         if i=='1':r1+='1'+'0'
        #         else:r1+='0'+'1'
        #     l = r1
        # # print(l)
        # return r1[n]
        k = -1
        m = ""
        for i in s:
            l = i
            for j in range(r):
                a = len(l)
                x = ""
                while a:
                    if l[len(l)-a]=="1":x+="1"+"0"
                    else:x+="0"+"1"
                    a-=1
                if len(m)>n:
                    break
                l = x
            m+=x
        return m[n]   
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        snr = input().split()
        S, R, N = snr[0], int(snr[1]), int(snr[2])
        ob = Solution()
        print(ob.nthCharacter(S, R, N))
# } Driver Code Ends