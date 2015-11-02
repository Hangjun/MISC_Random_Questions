/* Given two sorted linked lists l1 and l2, merge them into a single sorted list without allocating additional memory */

#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
// merge two sorted lists in place
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = l1;
    ListNode *prevNode = dummyNode;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            l1 = l1->next;
        } else {
            ListNode *tmp = l2->next;
            prevNode->next = l2;
            l2->next = l1;
            l2 = tmp;
        }
        prevNode = prevNode->next;
    }
    if (l2 != NULL) {
        prevNode->next = l2;
    }
    ListNode *newHead = dummyNode->next;
    delete dummyNode;
    return newHead;
}
  
int main() {
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);
	
	ListNode *l2 = new ListNode(2);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(6);
	
	ListNode *head = mergeTwoLists(l1, l2);
	ListNode *p = head;
	while (p) {
	    cout << p->val << " ";
	    p = p->next;
	}
	return 0;
}
