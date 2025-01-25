class Solution {
public:
    int maxLength(vector<string>& arr) {
        return solve (arr, 0, "");
    }

    int solve(vector<string>&arr, int index, string str)
    {
        set<char> uset(str.begin(), str.end());
        if(uset.size() != str.size())  return 0;
        if(index >= arr.size())  return str.size();

        for(char c: arr[index])   str.push_back(c);
        int take = solve(arr,index+1, str );
        
        for(char c: arr[index])   str.pop_back();
        int nontake = solve(arr, index+1, str);

        return max(take, nontake);
    }
};