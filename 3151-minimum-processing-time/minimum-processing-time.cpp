class Solution {
public:
    
    
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
         sort(tasks.begin(), tasks.end());

         sort(processorTime.begin(), processorTime.end(), greater<>());

        int maxi = 0;
        int cnt = 0;
         for(int i=3;i<tasks.size();i=i+4)
         {
            cout << tasks[i] << " ";
            maxi = max(maxi, processorTime[cnt] + tasks[i]);
            cnt++;
         }   
         return maxi;
    }
};