//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* rev(Node* head){
        Node *x = NULL , *temp = NULL , *curr = head;
        while(curr!=NULL){
            x = curr->next;
            curr->next = temp;
            temp = curr;
            curr = x;
        }
        head = temp;
        return head;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
       
        Node* first =  rev(head);
        int x = 0 , c = 1 , x1 = 0,a = 0;
        Node* head1 = NULL;
        while(first!=NULL){
            x = first->data;
            x1 = (x+c)%10;
            Node *temp = new Node(x1);
            c = (x+c)/10;
            temp->next = head1;
            head1  = temp;
            first = first->next;
        }
        if(c!=0){
            Node *temp = new Node(c);
            c = 0;
            temp->next = head1;
            head1  = temp;
        }
        return head1;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends