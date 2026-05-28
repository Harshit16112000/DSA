class Solution {
    public String reversePrefix(String s, int k) {
        
        String firstPrefixReverse = s.substring(0,k);
        String remainingPrefix = s.substring(k);
        String reversed = new StringBuilder(firstPrefixReverse).reverse().toString();
        
        return reversed + remainingPrefix;
    }
}