#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /*
    Q. Reverse a Singly Linked List
    */

    ListNode* reverseList(ListNode* head) {
        ListNode *i = nullptr, *k;

        while(head != nullptr) {
            k = head->next;
            head->next = i;

            i = head;
            head = k;
        }

        return i;
    }
};
