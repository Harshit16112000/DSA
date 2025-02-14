class ProductOfNumbers {
public:
vector<int> ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
      int nums = 1;
      reverse(ans.begin(), ans.end());
      for(int i=0;i<k;i++)
      {
            nums *= ans[i];
      }  
      reverse(ans.begin(), ans.end());
      return nums;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */