#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode (int x) : val(x), next(NULL) {};
};

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL) return head;
//         int List_size = 0;
//         ListNode* ptr = head;
//         while (ptr)
//         {
//             List_size++;
//             ptr = ptr->next;
//         }
//         if(k > List_size) k = k % List_size;
//         ptr = head;
//         for(int i = 0; i < k; i++){
//             ptr = head;
//             ListNode* ptr2 = head->next;
//             while (ptr->next->next) ptr = ptr->next;
//             ptr2 = ptr->next;
//             ptr2->next = head;
//             ptr->next = NULL;
//             head = ptr2;
//         }
//         return head;
//     }
// };


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL) return head;
//         int List_size = 1;
//         ListNode* ptr = head;
//         while (ptr->next)
//         {
//             List_size++;
//             ptr = ptr->next;
//         }
//         if(k >= List_size) k = k % List_size;
//         if(k == 0) return head;
//         ListNode* ptr2 = head;
//         for(int i = 1; i <= List_size - k; i++) {
//             if(ptr2->next == ptr) break; // Make sure ptr2 always behind ptr
//             else if(i != 1) ptr2 = ptr2->next; // When i = List_size make sure ptr2 do not change
//         }
//         if(ptr2->next){
//             ptr->next = head;
//             head = ptr2->next;
//             ptr2->next = NULL;
//         }
//         else{
//             ptr->next = head;
//             ptr2->next = NULL;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int List_size = 1;
        ListNode* ptr = head;
        while (ptr->next)
        {
            List_size++;
            ptr = ptr->next;
        }
        k = k % List_size;
        if(k == 0) return head;
        ListNode* ptr2 = head;
        for(int i = 1; i < List_size - k; i++) ptr2 = ptr2->next; // When i = List_size make sure ptr2 do not change
        ListNode* newhead = ptr2->next;
        ptr2->next = NULL;
        ptr->next = head;
        return newhead;
    }
};

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (!head || !head->next) return head;

//         // B1: Tính độ dài và trỏ tail
//         int n = 1;
//         ListNode* tail = head;
//         while (tail->next) {
//             tail = tail->next;
//             n++;
//         }

//         // B2: Chuẩn hóa k
//         k %= n;
//         if (k == 0) return head;

//         // B3: Tìm newTail ở vị trí n - k - 1
//         ListNode* newTail = head;
//         for (int i = 0; i < n - k - 1; i++) {
//             newTail = newTail->next;
//         }

//         // B4: Cắt & nối lại
//         ListNode* newHead = newTail->next;
//         newTail->next = NULL;
//         tail->next = head;

//         return newHead;
//     }
// };


int main(){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int i :{1,2,3,4,5}){
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    ListNode* input1 = dummy.next;
    Solution a;
    ListNode* output = a.rotateRight(input1,2);
    while(output){
        cout << output->val << " ";
        output = output->next;
    }
    cout << endl;
    return 0;
}