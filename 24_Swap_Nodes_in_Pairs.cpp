#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode (int x) : val(x) , next(nullptr) {};
};

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
//         head = dummy;
//         if(head->next == NULL || head->next->next == NULL) return head->next;
//         ListNode* ptr1 = head;
//         ListNode* ptr2 = ptr1->next->next;
//         while(ptr2){
//             //Swap Node
//             ptr1->next->next = ptr2->next;
//             ptr2->next = ptr1->next;
//             ptr1->next = ptr2;
//             // Relocate Pos
//             ptr1 = ptr1->next->next;
//             if(ptr1->next && ptr1->next->next) ptr2 = ptr1->next->next;
//             else break;
//         }
//         return head->next;
//     }
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        if(dummy->next == NULL || dummy->next->next == NULL) return dummy->next;
        while(cur){
            ListNode* ptr1 = cur;
            ListNode* ptr2 = cur->next->next;
            //Swap Node
            ptr1->next->next = ptr2->next;
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            // Relocate Pos
            cur = cur->next->next;
            if(cur->next && cur->next->next) continue;
            else break;
        }
        return dummy->next;
    }
};

int main(){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int i :{1,2,3,4}){
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    ListNode* input1 = dummy.next;
    Solution a;
    ListNode* output = a.swapPairs(input1);
    while(output){
        cout << output->val << " ";
        output = output->next;
    }
    return 0;
}