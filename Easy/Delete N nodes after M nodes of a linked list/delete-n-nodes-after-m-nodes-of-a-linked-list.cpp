//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

// } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        //Add code here  
        Node* temp = head;
        int c = 1 , c1 = 0 ;
        while(head->next!=NULL){
            if(c==m){
                Node* prev = head;
                c = 0;
                while(c1!=n and c1!=n+1){
                    if(head->next->next!=NULL){   
                        head = head->next;
                    }
                    else{
                        c1 = n;
                    }
                    c1+=1;
            
                }
                if(c1==n) prev->next = head->next;
                else if(c1==n+1) {
                    prev->next = NULL;
                    break;
                }
                c1 = 0;
                
            }
            c+=1;
            head = head->next;
        }
        // while(temp!=NULL){
        //     cout<<temp->data;
        //     temp = temp->next;
        // }
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}

// } Driver Code Ends