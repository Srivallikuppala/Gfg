//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL) return true;
        Node* head1 = NULL;
        Node *slow = head, *fast = head , *prev = NULL;
        while(fast!=NULL and fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        if(fast==NULL){
            head1 = slow;
            prev->next = NULL;
            
        }
        else if(fast->next==NULL){
            prev->next = NULL;
            head1 = slow->next;   
        }
        Node* nexts = NULL;
        Node* prevs = NULL;
        Node* curr = head1;
        while(curr!=NULL){
            nexts = curr->next;
            curr->next = prevs;
            prevs = curr;
            curr = nexts;
        }
        head1 = prevs;
        while(head!=NULL){
            if(head->data!=head1->data) return false;
            head = head->next;
            head1 = head1->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends