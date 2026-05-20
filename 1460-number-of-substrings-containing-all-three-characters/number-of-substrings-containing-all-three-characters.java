class Solution {
    public int numberOfSubstrings(String s) {

     int l = 0;
     int r = 0;
     int distinct = 3;
     int count = 0;
     HashMap<Character, Integer> map = new HashMap<>();

     while(r!= s.length())
     {
        map.put(s.charAt(r), map.getOrDefault(s.charAt(r),0) + 1);
        while(map.size() == 3)
        {
            map.put(s.charAt(l), map.get(s.charAt(l)) - 1);

            if (map.get(s.charAt(l)) == 0) {
                map.remove(s.charAt(l));
            }
            l++;
            count = count + (s.length()-r);
        }
        r++;

     }
     return count;   
    }
}