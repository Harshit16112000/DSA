class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s.length() < p.length()) return new ArrayList<>();
        HashMap<Character, Integer> hmap = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<p.length();i++)
        {
            hmap.put(p.charAt(i), hmap.getOrDefault(p.charAt(i),0) + 1);
        }   

        HashMap<Character, Integer> hmap2 = new HashMap<>();
        
        int l = 0;
        int r = 0;
        while(r != p.length())
        {
           hmap2.put(s.charAt(r), hmap2.getOrDefault(s.charAt(r),0) + 1);
           r++; 
        }

        while(r < s.length())
        {
             if(hmap2.equals(hmap))  result.add(l);

             int key = hmap2.get(s.charAt(l));
             if(key > 1)
                hmap2.put(s.charAt(l), key - 1);
            else
                hmap2.remove(s.charAt(l));
            
            hmap2.put(s.charAt(r), hmap2.getOrDefault(s.charAt(r),0) + 1);
           l++;
           r++;
        }
        if(hmap2.equals(hmap))  result.add(l);
        return result;
    }
}