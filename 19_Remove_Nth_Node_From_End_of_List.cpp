#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

// class Solution
// {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* ptr = head;
//         int List_size = 0;
//         while(ptr) {
//             List_size++;
//             ptr =ptr->next;
//         }
//         ptr = head;
//         n = List_size - n;
//         if(n == 0) {
//             head = head->next;
//             return head;
//         }
//         n--;
//         while (ptr->next)
//         {
//             if(n != 0) ptr = ptr->next;
//             else {
//                 ptr->next = ptr->next->next;
//                 break; 
//             }
//             n--;
//         }
//         return head;
//     }
// };

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        ListNode* ptr = head;
        ListNode* fast = head;
        for(int i = 0; i <= n; i++){
            if(fast) fast = fast->next;
            else break;
        }
        while(fast){
            ptr = ptr->next;
            fast = fast->next;
        }
        ptr->next = ptr->next->next;
        return head->next;
    }
};

int main(){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int target = 2;
    for(int i :{1,2,3,4,5}){
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    ListNode* input = dummy.next;
    Solution a;
    ListNode* output = a.removeNthFromEnd(input,target);
    while(output){
        cout << output->val << " ";
        output = output->next;
    }
    return 0;
}


