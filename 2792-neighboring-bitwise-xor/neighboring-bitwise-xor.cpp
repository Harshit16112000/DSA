class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor1 = 0;
        for(int i=0;i<derived.size();i++)
        {
            xor1 = xor1 ^ derived[i];
        }

        if(xor1 == 0)  return true;
        return false;
    }
};