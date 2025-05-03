class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> topValue = getMaxiValue(tops);
        int result1 = tops.size() - topValue[1];
        for(int i=0;i<tops.size();i++)
        {
            if(tops[i] == topValue[0] || bottoms[i] == topValue[0])
              continue;
            result1 = -1;
        }

        vector<int> bottomValue = getMaxiValue(bottoms);
        int result2 = bottoms.size() - bottomValue[1];
        for(int i=0;i<bottoms.size();i++)
        {
            if(tops[i] == bottomValue[0] || bottoms[i] == bottomValue[0])
              continue;
            result2 = -1;
        }

        if(result1 == -1 && result2 == -1)  return -1;
        if(result1 == -1)  return result2;
        if(result2 == -1)  return result1;
        return min( (tops.size() - topValue[1]), bottoms.size() - bottomValue[1]);        
    }

    vector<int> getMaxiValue(vector<int>& arr) {
        map<int, int> mpp;

        for (auto it : arr)
            mpp[it]++;
        int maxi = 0;
        int num = 0;
        for (auto& [key, value] : mpp) {
            if(value > maxi)
            {
            maxi = max(maxi, value);
            num = key;
            }
        }
        return  {num, maxi};
    }
};