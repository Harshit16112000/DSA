class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mpp; // Maps x -> latest y
        unordered_map<int, int> freq; // Tracks count of each y value
        unordered_set<int> st; // Unique y values
        vector<int> ans;

        for (auto &q : queries) {
            int x = q[0], y = q[1];

            // If x is already mapped, handle the previous value
            if (mpp.find(x) != mpp.end()) {
                int prev_y = mpp[x];

                // Decrease the frequency count of prev_y
                freq[prev_y]--;

                // If the previous y is no longer associated with any x, remove it from st
                if (freq[prev_y] == 0) {
                    st.erase(prev_y);
                }
            }

            // Update x → y mapping
            mpp[x] = y;

            // Increase frequency of new y
            freq[y]++;

            // Add y to the set if it's newly introduced
            st.insert(y);

            ans.push_back(st.size());
        }

        return ans;
    }
};
