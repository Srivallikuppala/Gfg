//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first =  rev(first);
        second = rev(second);
        int x = 0 , c = 0 , x1 = 0;
        Node *head = NULL;
        while(first!=NULL && second!=NULL){
            x = first->data+second->data;
            x1 = (x+c)%10;
            Node *temp = new Node(x1);
            c = (x+c)/10;
            temp->next = head;
            head  = temp;
            first = first->next;
            second = second->next;
        }
        while(first!=NULL){
            x = first->data;
            x1 = (x+c)%10;
            Node *temp = new Node(x1);
            c = (x+c)/10;
            temp->next = head;
            head  = temp;
            first = first->next;
        }
        while(second!=NULL){
            x = second->data;
            x1 = (x+c)%10;
            Node *temp = new Node(x1);
            c = (x+c)/10;
            temp->next = head;
            head  = temp;
            second = second->next;
        }
        if(c!=0){
            Node *temp = new Node(c);
            c = 0;
            temp->next = head;
            head  = temp;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends