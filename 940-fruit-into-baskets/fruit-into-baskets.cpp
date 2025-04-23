class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int l=0;
       int r = 0;
       int ans = 0;
        unordered_map<int, int> fruitCount;
       while( r < fruits.size())
       {
            
            fruitCount[fruits[r]]++;
            while(fruitCount.size() > 2)
            {
                fruitCount[fruits[l]]--;
                if (fruitCount[fruits[l]] == 0) {
                    fruitCount.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
       } 

       return ans;
    }
};