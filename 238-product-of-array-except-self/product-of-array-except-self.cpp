class Solution {
public:
    vector<int> productExceptSelf(vector<int>& list) {
        int multi = 1;
        vector<int> result;
        int cntOfZero = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == 0) {
                cntOfZero++;
                continue;
            }
            multi = multi * list[i];
        }
        if(cntOfZero == 0)
        {
            for(int i=0;i<list.size();i++)
            {
                result.push_back(multi/list[i]);
            }
        }
        if (cntOfZero == 1) {
            for (int i = 0; i < list.size(); i++) {
                if (list[i] != 0)
                    result.push_back(0);
                else
                    result.push_back(multi);
            }
        }
        if (cntOfZero >= 2) {
            for (int i = 0; i < list.size(); i++) {
                result.push_back(0);
            }
        }

        return result;
    }
};