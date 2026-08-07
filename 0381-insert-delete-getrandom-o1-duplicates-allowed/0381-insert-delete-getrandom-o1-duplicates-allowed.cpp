class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {

    }

    bool insert(int val) {

        bool notPresent = (mp.find(val) == mp.end());

        nums.push_back(val);

        mp[val].insert(nums.size() - 1);

        return notPresent;
    }

    bool remove(int val) {

        if (mp.find(val) == mp.end())
            return false;

        // Take any index of val
        int index = *mp[val].begin();

        // Remove this index
        mp[val].erase(index);

        int lastElement = nums.back();
        int lastIndex = nums.size() - 1;

        if (index != lastIndex) {

            nums[index] = lastElement;

            mp[lastElement].erase(lastIndex);
            mp[lastElement].insert(index);
        }

        nums.pop_back();

        if (mp[val].empty())
            mp.erase(val);

        return true;
    }

    int getRandom() {

        int index = rand() % nums.size();

        return nums[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */