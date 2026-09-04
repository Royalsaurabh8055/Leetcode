class LockingTree {
public:

    vector<int> parent;

    // locked[i] = 0  → node is unlocked
    // locked[i] = user → node is locked by that user
    vector<int> locked;

    // children[i] contains all children of node i
    vector<vector<int>> children;


    LockingTree(vector<int>& parent) {

        this->parent = parent;

        int n = parent.size();

        locked.resize(n, 0);
        children.resize(n);

        // Build children list
        for (int i = 1; i < n; i++) {

            children[parent[i]].push_back(i);
        }
    }


    bool lock(int num, int user) {

        // Already locked
        if (locked[num] != 0) {
            return false;
        }

        // Lock it
        locked[num] = user;

        return true;
    }


    bool unlock(int num, int user) {

        // Only the same user can unlock
        if (locked[num] != user) {
            return false;
        }

        locked[num] = 0;

        return true;
    }


    bool upgrade(int num, int user) {

        // 1. Node itself must be unlocked
        if (locked[num] != 0) {
            return false;
        }


        // 2. No ancestor should be locked
        int curr = parent[num];

        while (curr != -1) {

            if (locked[curr] != 0) {
                return false;
            }

            curr = parent[curr];
        }


        // 3. Find locked descendants using BFS
        queue<int> q;

        q.push(num);

        bool foundLocked = false;

        while (!q.empty()) {

            int node = q.front();
            q.pop();


            // Check all children
            for (int child : children[node]) {

                q.push(child);

                // If child is locked
                if (locked[child] != 0) {

                    foundLocked = true;

                    // Unlock it
                    locked[child] = 0;
                }
            }
        }


        // No locked descendant
        if (!foundLocked) {
            return false;
        }


        // Lock current node
        locked[num] = user;

        return true;
    }
};