#User function template for Python

class Solution:
    # your task is to complete this function
    # function should return an integer
    def atoi(self,s):
        # Code here:
        c = 0
        if s[0]=='-':
            c=1
        if c==1:
            if s[1] in '1234567890':
                c = int(s[1])
                for i in range(2,len(s)):
                    if s[i] not in '1234567890':
                        return -1
                    c = (c*10)+int(s[i])
            else:return -1
            c = c*(-1)
        else:
            if s[0] in '1234567890':
                c = int(s[0])
                for i in range(1,len(s)):
                    if s[i] not in '1234567890':
                        return -1
                    c = (c*10)+int(s[i])
            else:return -1
        return c
                
                    


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t=int(input())
    for i in range(t):
        string = input().strip();
        ob=Solution()
        print(ob.atoi(string))
# } Driver Code Ends