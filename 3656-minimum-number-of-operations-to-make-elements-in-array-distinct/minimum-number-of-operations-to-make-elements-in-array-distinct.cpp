class Solution {
public:
    bool Duplicates( vector<int> nums) {
    set<int> st;
    for (int num : nums) {
        if (st.find(num) != st.end()) {
            return true;
        }
        st.insert(num);
    }
    return false;
    }

    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while(Duplicates(nums))
            {
                int checkremainingElement = min(3, (int)nums.size());
                 nums.erase(nums.begin(), nums.begin() + checkremainingElement);
                cnt++;
            }
        return cnt;
    }
};