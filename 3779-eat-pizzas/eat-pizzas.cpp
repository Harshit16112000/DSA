class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
       long long sum = 0;
        sort(pizzas.begin(), pizzas.end());

        int sumcount = pizzas.size()/4;
        int flag = true;
        int index = pizzas.size() - 1;
        
        int oddcount = ceil((double)sumcount/2);
        int evencount = sumcount - oddcount;
        while(oddcount != 0)
        {
            sum += pizzas[index];
            oddcount--;
            index--;
        }
        index--;
        while(evencount != 0)
        {
            sum += pizzas[index];
            evencount--;
            index = index-2;
        }
        return sum;
        
    }
};