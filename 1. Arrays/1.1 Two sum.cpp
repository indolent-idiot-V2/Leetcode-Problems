##############################################################################################################################
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

Link: https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array
############################################################################################################################## 

Method-1: Bruteforce:

Algorithm: 
 1. We iterate through each and every element and find if it have any coresponding complement 
    i.e. target - nums[i] in the array.
 2. If we find the complement, we return the indices of both the elements. 

 Complexity: Time: O(n²) Space: O(1)

Pros:
1.Super simple
2. No extra memory used

Cons:
Very slow on large arrays (e.g., n = 10^5)



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i =0; i< nums.size(); i++){
            int complement = target - nums[i];
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j] == complement){
                    return {i,j};
                }
            }
        }
        
        return {};
    }
};

Method-2: Using Hashmaps

Algorithm: 
1. we compute complement for each number 
2. We check in the map if we have complement already present.
3. If is present then we return the indices
4. If it is not present then we store the complement in a hasmap in the form <complement - index>

Complexity: Time: O(n)  Space: O(n)

Pros:
1. Lightning fast ⚡
2. Returns indices efficiently
3. Best choice in 99% of interview cases

Cons:
Uses extra memory


vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numToIndex.count(complement)) {
            return {numToIndex[complement], i};
        }
        numToIndex[nums[i]] = i;
    }
    return {};
}



