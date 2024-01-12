#User function Template for python3
def primes(x):
    t = [1 for i in range(0,x+1)]
    t[0],t[1]=0,0
    r = []
    for i in range(2,int(pow(x,0.5))+1):
        if t[i]==1:
            for j in range(i*i,x+1,i):t[j]=0
    for i in range(2,len(t)):
        if t[i]==1:r.append(i)
                
    return r
class Solution:
    def primeProduct(self, n,m):
        y = [1 for i in range(n,m+1)]
        x = primes(int((m**0.5)))
        if n==1:y[0]=0
        for i in x:
            r = 0
            if n%i!=0:r = (((n//i)+1)*(i))-n
            for j in range(r,m+1-n,i):
                if i!=j+n:y[j]=0
            
        r1 = 1
        for i in range(len(y)):
            if y[i]==1:
                r1 = r1*(i+n)
        return r1%(1000000007)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        L, R = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.primeProduct(L, R))
# } Driver Code Ends