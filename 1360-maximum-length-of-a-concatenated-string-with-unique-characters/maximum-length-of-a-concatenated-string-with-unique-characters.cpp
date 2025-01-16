class Solution {
public:
    int maxLength(vector<string>& arr) {
        return solve (arr, 0, "");
    }

    int solve(vector<string>&arr, int index, string str)
    {
        unordered_set<char> uset(str.begin(), str.end());
        if(uset.size() != str.size())  return 0;
        if(index >= arr.size())  return str.size();

        int take = solve(arr,index+1, str + arr[index]);
        int nontake = solve(arr, index+1, str);

        return max(take, nontake);
    }
};