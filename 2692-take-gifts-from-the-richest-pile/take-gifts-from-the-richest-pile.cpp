

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        sort(gifts.begin(), gifts.end());
        while(k--)
        {
            
            gifts[gifts.size() -1] = sqrt(gifts[gifts.size() - 1]);
            sort(gifts.begin(), gifts.end());
        }

        for(int i=0;i<gifts.size();i++)
        {
            sum += gifts[i];
        }
        return sum;
    }
};