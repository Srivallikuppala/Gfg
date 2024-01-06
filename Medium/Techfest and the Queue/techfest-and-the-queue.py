
from typing import List

class Solution:
    def sumOfPowers(self, a : int, b : int) -> int:
        def factor(n):
            primes=[True]*(n + 1)
            primes[0]=primes[1]=False
            p=2
            while p*p<=n:
                if primes[p]==True:
                    for i in range(p*p,n+1,p):
                        primes[i] = False
                p+=1
            return [i for i in range(2, n + 1) if primes[i]]
        max_limit=int(b ** 0.5)+1
        primes=factor(max_limit)
        ts=0
        for i in range(a,b+1):
            num = i
            s=0
            for prime in primes:
                if prime * prime>num:
                    break
                if num % prime == 0:
                    c=0
                    while num%prime == 0:
                        num //=prime
                        c+=1
                    s+=c
            if num > 1:
                s += 1
            ts+=s
    
        return ts
        
        



#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=int(input())
        b=int(input())
        
        obj = Solution()
        res = obj.sumOfPowers(a,b)
        
        print(res)
        

# } Driver Code Ends