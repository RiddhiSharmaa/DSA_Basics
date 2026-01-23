#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycle(ListNode* head){
        map<int, bool>mpp;
        ListNode* temp = head;
        while (temp != nullptr){
            if (mpp.find(temp->data) == mpp.end()){
                mpp[temp->data] = true;
            } else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

class Solution {
private:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr){
            temp = temp->next;
            len++;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next ) return head;
        int len = getLength(head);
        int pos = k%len;

        ListNode* temp = head;
        if (pos == 0) return head;
        while (pos != 0){
            temp = temp->next;
            pos--;
        }

        ListNode* nextNode = temp->next;
        temp->next = nullptr;
        if (nextNode == nullptr) return head;
        ListNode* dummy = nextNode;

        while (nextNode->next != nullptr){
            nextNode = nextNode->next;
        }
        nextNode->next = head;
        return dummy;
    }
};