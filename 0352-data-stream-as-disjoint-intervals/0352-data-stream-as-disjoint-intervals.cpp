class SummaryRanges {
public:
    set<int> st;

    SummaryRanges() {
        
    }

    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {

        vector<vector<int>> ans;

        if (st.empty())
            return ans;

        auto it = st.begin();

        int start = *it;
        int end = *it;

        ++it;

        while (it != st.end()) {

            if (*it == end + 1) {
                end = *it;
            }
            else {
                ans.push_back({start, end});
                start = end = *it;
            }

            ++it;
        }

        ans.push_back({start, end});

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */