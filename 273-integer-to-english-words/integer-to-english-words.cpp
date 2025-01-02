class Solution {
public:
    // Globally declare arrays
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand", "Million", "Billion"};
    
    // Helper function to convert numbers less than 1000
    string helper(int nums)
    {
        if (nums == 0) return "";
        if(nums < 20)  return ones[nums] + " ";

        if(nums < 100)  return tens[nums/10] + " " + helper(nums%10);
         
         return ones[nums / 100] + " Hundred " + helper(nums % 100);
    }
    
    // Main function to convert the number to words
    string numberToWords(int num) {
        // Edge case
        if (num == 0) return "Zero";
        
        string result = "";
        int i = 0; // Index for thousands array
        
        // Process each group of three digits
            while(num > 0)
            {
                if(num%1000 != 0)
                {
                    result = helper(num%1000) +  thousands[i] + " " + result;
                }
                num = num/1000;
                i++;
            }    
        // Remove any trailing spaces
        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};
