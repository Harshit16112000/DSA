class NumberContainers {
public:
    unordered_map<int,int> container;
    unordered_map<int, set<int>> values;
        
    NumberContainers() {    
    }
    
    void change(int index, int number) {
        if(container.find(index) != container.end())
        {
            int oldNumber = container[index];
            values[oldNumber].erase(index);
        }
        container[index] = number;
        values[number].insert(index);
    }
    
    int find(int number) {
        
        if(values.find(number) != values.end() &&  !values[number].empty())
        {
            return *values[number].begin();
        }


        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */