/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newLLnode = new ListNode();
        ListNode* newLL = newLLnode;

        while (list1 && list2){
            cout<< list1->val << list2->val<<"next" <<endl;
            if(list1->val > list2->val){
                newLL-> next = list2;
                list2 = list2->next;
            }
            else{
                newLL -> next = list1;
                list1 = list1->next;
            }
            // else if (list1->val == list2->val){
            //     newLL-> next = list1;
            //     list1= list1->next;
            //     newLL = newLL-> next;
            //     newLL-> next = list2;
            //     list2 = list2-> next;
            // }
            newLL= newLL->next;
        }
        if(list1){
            newLL->next = list1;
        }
        if(list2){
            newLL->next = list2;
        }
        return newLLnode-> next;
    }
};
