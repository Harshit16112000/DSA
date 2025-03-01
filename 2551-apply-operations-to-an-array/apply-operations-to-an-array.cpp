class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        stack<int> st;
     for(int i=0;i<nums.size()-1;)
     {
        if(nums[i] == nums[i+1])
        {
            st.push(nums[i] *2);
            i = i+2;
        }
        else {
            st.push(nums[i]);
            i = i+1;
        }
     }
    //cout << nums[nums.size() -1];
     if(nums[nums.size() - 1] != nums[nums.size() -2])
     st.push(nums[nums.size() -1]);

     vector<int> ans(nums.size() , 0);

    stack<int> st2;
    
     while(!st.empty())   
        {
            st2.push(st.top());
            //cout << st.top();
            
            st.pop();
        }

        int index = 0;
        while(!st2.empty())
        {
            if(st2.top() == 0)  { st2.pop(); continue; }
            ans[index] = st2.top();
            st2.pop();
            index++;
        }

        return ans;
    }
};