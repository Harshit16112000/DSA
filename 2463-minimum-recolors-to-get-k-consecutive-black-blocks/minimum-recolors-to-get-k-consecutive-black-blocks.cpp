class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int n = blocks.size();

        int i = 0;
        int j = 0;
        while(j < k)
        {
            if(blocks[j] == 'W')  count++;
            j++;
        }

        int maxi = count;
        while(j < n)
        {
            maxi = min(maxi, count);
            if(blocks[i] == 'W')   {  count--; }
            i++;

            if(blocks[j] == 'W') { count ++; }
            j++;
             
        }
          maxi = min(maxi, count);

        return maxi;
    }
};