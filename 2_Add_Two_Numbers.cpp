#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        this->val = x;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if one of l2 and l2 null
        if(l2 == NULL) return l1;
        if(l1 == NULL) return l2;
        int remember = 0;
        int sum = 0;
        ListNode* sum_list = NULL;
        ListNode* ptr3 = NULL;
        while (l1 || l2 || remember == 1){
            sum = remember;
            if(l1) sum = sum + l1->val;
            if(l2) sum = sum + l2->val;
            remember = sum / 10;
            ListNode* new_Node = new ListNode(sum % 10);
            if(sum_list == NULL){
                sum_list = new_Node;
                ptr3 = new_Node;
            }
            else {
                ptr3->next = new_Node;
                ptr3 = ptr3->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return sum_list;
    }
};

int main(){
    ListNode* input1 = new ListNode(9);
    input1->next = new ListNode(9);
    input1->next->next = new ListNode(9);
    input1->next->next->next = new ListNode(9);

    ListNode* input2 = new ListNode(9);
    input2->next = new ListNode(9);
    input2->next->next = new ListNode(9);

    ListNode* output = NULL;
    Solution a;
    output = a.addTwoNumbers(input1, input2);
    while(output) {
        cout << output->val << " ";
        output = output->next;
    }
    return 0;
}