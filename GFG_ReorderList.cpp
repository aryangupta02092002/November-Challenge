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

class Solution{ 
public:


    // void reorderList(Node* head) {
    //     // Your code here
    //     Node *tmp = head;
    //     vector<int> v;
    //     int i=0, j=0, l=0;
        
    //     while(tmp != NULL){
    //         v.push_back(tmp->data);
    //         tmp = tmp->next;
    //         i++;
    //     }
        
    //     while(j < i){
    //         if(j%2 == 0){
    //             head->data = v[l];
    //             l++;
    //         }
    //         else{
    //             head->data = v[i-l];
    //         }
    //         j++;
    //         head = head->next;
    //     }
        
    // }


    void reorderList(Node* head) {
        // Your code here
        if(head->next == NULL || head->next->next == NULL){
            return;
        }
        Node *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *h1 = head, *h2 = slow->next;
        slow->next = NULL;
        
        Node *prev = NULL, *curr = h2, *post = h2->next;
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = post;
            if(post != NULL){
                post = post->next;
            }
        }
        h2 = prev;
        
        Node *n1 = h1, *p1 = h1->next, *n2 = h2, *p2 = h2->next;
        while(n1 != NULL && n2 != NULL){
            n1->next = n2;
            n2->next = p1;
            n1 = p1;
            n2 = p2;
            if(p1 != NULL){
                p1 = p1->next;
            }
            if(p2 != NULL){
                p2 = p2->next;
            }
        }
        if(n1 != NULL){
            n1->next = NULL;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends
