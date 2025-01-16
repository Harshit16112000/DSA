class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int xor1 = 0;
        int xor2 = 0;
        for(int i=0;i<nums1.size();i++)
        {
            xor1 = xor1 ^ nums1[i];
            
        }

        for(int i=0;i<nums2.size();i++)
        {
            xor2 = xor2 ^ nums2[i];
            
        }
        cout << xor1 << " ";
        cout << xor2 << " ";
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1%2 == 0 && n2%2 == 0)
           return 0;
        if(n2%2 == 0)
           return xor2;
        if(n1%2 == 0)
           return xor1;
        
        return xor1 ^ xor2;
    }
};