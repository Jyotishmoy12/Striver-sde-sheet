#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>*reverse(LinkedListNode<int> *head){
    LinkedListNode<int> *pre=NULL;
    LinkedListNode<int> *next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL) return true;
    // first find the middle
    LinkedListNode<int> *fast=head;
    LinkedListNode<int> *slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // now reverse the ll after the middle since slow pointer is at the middle now reverse it after the slow pointer
    slow->next=reverse(slow->next);
    slow=slow->next;
    // compare both the halves
    LinkedListNode<int> *dummy=head;
    while(slow!=NULL){
        if(slow->data !=dummy->data) return false;
        slow=slow->next;
        dummy=dummy->next;
    }
    return true;


}
