class Solution {
public:
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;

        vector<vector<int>> ans;
        for(int size = 0; size<=nums.size(); size++){
            if(size == 0){
                ans.push_back({});
                continue;
            }

            if(size == nums.size()){
                ans.push_back(nums);
                continue;
            }
                

            vector<int> size_vec;
            backtrack(ans, size_vec, 0, size);
        }
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& path, int index, int size){
        if(path.size() == size){
            ans.push_back(path);
            return;
        }


        for(int j = index; j<nums.size(); j++){
            path.push_back(nums[j]);
            backtrack(ans, path, j+1, size);
            path.pop_back();
        }
    }
};
