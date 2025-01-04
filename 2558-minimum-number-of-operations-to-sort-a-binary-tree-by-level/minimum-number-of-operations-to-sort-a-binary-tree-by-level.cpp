class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int totalSwaps = 0;

        // Process tree level by level using BFS
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues;

            // Store values of current level and add children to queue
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                levelValues.push_back(node->val);

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            // Add minimum swaps needed for current level
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }

private:
    int getMinSwaps(vector<int>& array) {
    int swapCount = 0; // Count the number of swaps
    vector<int> sortedArray = array; // Create a sorted version of the input array
    sort(sortedArray.begin(), sortedArray.end());

    // Map to track the current index of each value in the array
    unordered_map<int, int> valueIndexMap;
    for (int i = 0; i < array.size(); i++) {
        valueIndexMap[array[i]] = i;
    }

    // Iterate over each position and swap elements into their correct positions
    for (int i = 0; i < array.size(); i++) {
        if (array[i] != sortedArray[i]) {
            swapCount++; // Increment the swap count

            // Get the current and target positions of the value
            int targetValueIndex = valueIndexMap[sortedArray[i]];
            int currentValueIndex = valueIndexMap[array[i]];

            // Update the value-to-index mapping
            valueIndexMap[array[i]] = targetValueIndex;
            valueIndexMap[sortedArray[i]] = currentValueIndex;

            // Swap the values in the array to place the correct value in position `i`
            swap(array[targetValueIndex], array[i]);
        }
    }

    return swapCount;
}

};