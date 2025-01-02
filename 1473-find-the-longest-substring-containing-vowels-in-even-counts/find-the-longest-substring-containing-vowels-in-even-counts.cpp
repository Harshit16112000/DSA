class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mpp;

        mpp["00000"] = -1;

        vector<int> arr(5, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                arr[0] = (1 + arr[0]) % 2;
            if (s[i] == 'e')
                arr[1] = (1 + arr[1]) % 2;
            if (s[i] == 'i')
                arr[2] = (1 + arr[2]) % 2;
            if (s[i] == 'o')
                arr[3] = (1 + arr[3]) % 2;
            if (s[i] == 'u')
                arr[4] = (1 + arr[4]) % 2;

            string str = "";
            for (int j = 0; j < 5; j++)
                str += to_string(arr[j]);
            if (mpp.contains(str)) {
                ans = max(ans, i - mpp[str]);
            } else {
                mpp[str] = i;
            }
        }

        return ans;
    }
};