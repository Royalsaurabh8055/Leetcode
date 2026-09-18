class Solution {
public:
    int pairSum(ListNode* head) {

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Compare first half with reversed second half
        int ans = 0;

        while (prev != nullptr) {
            ans = max(ans, head->val + prev->val);

            head = head->next;
            prev = prev->next;
        }

        return ans;
    }
};