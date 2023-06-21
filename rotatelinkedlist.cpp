
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
       // edge cases 
        if (head==NULL || head->next ==NULL || k == 0) return head;
        
        // compute the length
        Node *cur = head;
        int len = 1;
        while (cur->next && ++len) 
            cur = cur->next;
        
        // go till that node
        cur->next = head;  // last node is pointing towards head
        k = k % len; // if k>=len
        k = len - k;  // coz we need to find len-kth node from the starting

        while (k--) cur = cur->next;  // now moving this from head since curr is pointing to the head
        
        // make the node head and break connection 
        head = cur->next; // curr->next will be the new head
        cur->next = NULL; // point the curr->next to the null and break the connection
        
        
        return head; 
}
