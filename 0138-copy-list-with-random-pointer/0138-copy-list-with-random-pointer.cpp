class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        // Step 1: Create copy of every node
        Node* curr = head;

        while (curr != NULL) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Connect next and random pointers
        curr = head;

        while (curr != NULL) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};