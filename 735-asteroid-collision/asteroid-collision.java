class Solution {
    public int[] asteroidCollision(int[] asteroids) {
      Stack<Integer> st = new Stack<>();
      ArrayList<Integer> result = new ArrayList<>();
      for(int i=0;i<asteroids.length;i++)
      {
            if(st.empty()) {

             st.push(asteroids[i]);
             
            }
            else if(asteroids[i] > 0 && st.peek() > 0){
                st.push(asteroids[i]);            
            }
            else if(asteroids[i] < 0 && st.peek() > 0)
            {
                 boolean destroyed = false;
                while (!st.empty() && st.peek() > 0) {
                    if (Math.abs(asteroids[i]) > st.peek()) {
                        st.pop();                
                    } else if (Math.abs(asteroids[i]) == st.peek()) {
                        st.pop();               
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;       
                        break;
                    }
                }
                if (!destroyed) st.push(asteroids[i]);
            }
            else if(asteroids[i] > 0 && st.peek() < 0)
            {
                st.push(asteroids[i]);
            }
            else if(asteroids[i] < 0 && st.peek() < 0)
            {
                st.push(asteroids[i]);    
            }
      }

      while(!st.empty())
      {
        result.add(st.peek());
        st.pop();
      }



      Collections.reverse(result);

    int[] ans = new int[result.size()];
    for(int i = 0; i < result.size(); i++) {
        ans[i] = result.get(i);
    }

    return ans;
    }
}