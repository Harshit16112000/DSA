class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
     unordered_map<string, unordered_map<string,double>> graph1, graph2;

     buildGraph(initialCurrency, pairs1, rates1, graph1);
     buildGraph(initialCurrency, pairs2, rates2, graph2);

     unordered_map<string,double> mpp = getMaxFirst(initialCurrency, graph1);
     unordered_map<string,double> mpp2 = getMaxFirst(initialCurrency, graph2, mpp);
    return mpp2[initialCurrency];
    }

     void buildGraph(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, 
           unordered_map<string, unordered_map<string,double>> &mpp) {
            for(int i=0;i<pairs1.size();i++)
            {
                string from = pairs1[i][0];
                string to = pairs1[i][1];
                mpp[from][to] = rates1[i];
                mpp[to][from] = 1.0/rates1[i];
            }
    }

    unordered_map<string,double> getMaxFirst(string initialCurrency, unordered_map<string, unordered_map<string, double>> graph) {
        unordered_map<string,double> mpp;
        mpp[initialCurrency] = 1.0;

        queue<string> q;
        q.push(initialCurrency);

        while(!q.empty())
        {
            string node = q.front();
            q.pop();
            double currentAmount = mpp[node];
            for(auto it: graph[node])
            {
                double newAmount = it.second * currentAmount;
                string neighbour = it.first;
                if(newAmount > mpp[neighbour])
                {
                    mpp[neighbour] = newAmount;
                    q.push(neighbour);
                }

            }
        }
        return mpp;
    }


    unordered_map<string,double> getMaxFirst(string initialCurrency, unordered_map<string, unordered_map<string, double>> graph,unordered_map<string,double> cal ) {
        unordered_map<string,double> mpp = cal;
        queue<string> q;
        for(auto ele: cal)
            q.push(ele.first);
       

        while(!q.empty())
        {
            string node = q.front();
            q.pop();
            double currentAmount = mpp[node];
            for(auto it: graph[node])
            {
                double newAmount = it.second * currentAmount;
                string neighbour = it.first;
                if(newAmount > mpp[it.first])
                {
                    mpp[neighbour] = newAmount;
                    q.push(neighbour);
                }

            }
        }
        return mpp;
    }
};