class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        vector<int> oneIndex;

        for(int i=0;i<n;i++)
        {
            if(boxes[i] == '1')  oneIndex.push_back(i);
        }

        for(int i=0;i<n;i++)
        {
            long long cnt = 0;
            for(int j=0;j<oneIndex.size(); j++)
            {
                cnt += (abs(oneIndex[j] - i));
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};