class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>ans(nums.begin(),nums.end());
        int mul=k;
        while(ans.count(mul)){
            mul+=k;
        }
        return mul;
    }
};