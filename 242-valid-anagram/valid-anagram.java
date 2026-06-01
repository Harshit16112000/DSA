class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())  return false;
        HashMap<Character,Integer> hmap = new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            hmap.put(s.charAt(i), hmap.getOrDefault(s.charAt(i), 0) + 1);
        }
        for(int i=0;i<t.length();i++)
        {
            if(hmap.containsKey(t.charAt(i)))
            {
                int getValue = hmap.get(t.charAt(i));
                if(getValue <= 0) return false;
                hmap.put(t.charAt(i), getValue - 1); 
            }
            else
               return false;
        }

        
        return true;
    }
}