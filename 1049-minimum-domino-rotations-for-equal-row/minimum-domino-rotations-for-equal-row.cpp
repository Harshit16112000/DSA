class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> topCandidate = getMostFrequentValue(tops);
        int topRotations = tops.size() - topCandidate[1];

        for(int i = 0; i < tops.size(); i++) {
            if (tops[i] == topCandidate[0] || bottoms[i] == topCandidate[0])
                continue;
            topRotations = -1;
            break;
        }

        vector<int> bottomCandidate = getMostFrequentValue(bottoms);
        int bottomRotations = bottoms.size() - bottomCandidate[1];

        for(int i = 0; i < bottoms.size(); i++) {
            if (tops[i] == bottomCandidate[0] || bottoms[i] == bottomCandidate[0])
                continue;
            bottomRotations = -1;
            break;
        }

        if (topRotations == -1 && bottomRotations == -1) return -1;
        if (topRotations == -1) return bottomRotations;
        if (bottomRotations == -1) return topRotations;

        return min(topRotations, bottomRotations);
    }

    vector<int> getMostFrequentValue(vector<int>& arr) {
        map<int, int> freqMap;

        for (int val : arr)
            freqMap[val]++;

        int maxFreq = 0;
        int candidateValue = 0;
        for (auto& [key, value] : freqMap) {
            if (value > maxFreq) {
                maxFreq = value;
                candidateValue = key;
            }
        }

        return {candidateValue, maxFreq};
    }
};
