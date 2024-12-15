class Solution {
public:
    double calculatediff(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue< pair<double,pair<int,int>>> pq;

       for(auto cla : classes)
       {
        pq.push( {calculatediff(cla[0], cla[1]), {cla[0], cla[1]} }   );
       }
        

       while(extraStudents--)
       {
         auto it = pq.top();
         pq.pop();
         int pass = it.second.first;
         int total = it.second.second;
         pq.push({calculatediff(pass+1, total + 1)
         ,{pass+1, total +1}});
       }
        double sum = 0;
       while(!pq.empty())
       {
         auto top = pq.top();
         pq.pop();
         sum +=  (double)top.second.first/top.second.second;

       }

       return sum/classes.size();
    }
};