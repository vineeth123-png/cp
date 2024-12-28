#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


class Solution {
public:
    int sizeOfSubArray, n;
    vector<int> nums;

    vector<int> rec_call(int idx, int numOfSubArraysLeft, vector<vector<vector<int>>>& dp) {
        // if Prefix's size is 3 and size of subarray is 4, we cant form an subarray.
        int numOfElementsNeeded = numOfSubArraysLeft * sizeOfSubArray;
        if (numOfSubArraysLeft == 0) {return {0};}
        if (idx < 0 || idx+1 < numOfElementsNeeded) {return {-2};}
        auto res = dp[idx][numOfSubArraysLeft];
        if (res[0] != -1) {return res;}
        
        auto resFoundBySkippingIdx = rec_call(idx-1, numOfSubArraysLeft, dp);
        int sumOfASubArray = 0;
        for(int i = idx-sizeOfSubArray+1; i<=idx; i++) {
            sumOfASubArray += nums[i];
        }
        auto resFoundByCountingASubarrayEndingWithIdx = rec_call(idx-sizeOfSubArray, numOfSubArraysLeft-1, dp);

        if (resFoundByCountingASubarrayEndingWithIdx[0] == -2 && resFoundBySkippingIdx[0] == -2) {
            // if we cant form a subarray
            dp[idx][numOfSubArraysLeft] = {-2};
            return resFoundBySkippingIdx;
        } else if (resFoundByCountingASubarrayEndingWithIdx[0] == -2) {
            dp[idx][numOfSubArraysLeft] = resFoundBySkippingIdx;
            return dp[idx][numOfSubArraysLeft];
        } else if (resFoundBySkippingIdx[0] == -2) {
            int sizeOfResult = 1 + numOfSubArraysLeft;
            vector<int> result(sizeOfResult);
            // result[0] = sum;
            result[0] = sumOfASubArray + resFoundByCountingASubarrayEndingWithIdx[0];
            for(int i = 0; i<numOfSubArraysLeft-1; i++) {
                result[i+1] = resFoundByCountingASubarrayEndingWithIdx[i+1];
            }
            result[sizeOfResult-1] = idx-sizeOfSubArray+1;
            dp[idx][numOfSubArraysLeft] = result;
            return dp[idx][numOfSubArraysLeft];
        }

        if (sumOfASubArray + resFoundByCountingASubarrayEndingWithIdx[0] > resFoundBySkippingIdx[0]) {
            // found a subarray with greater sum
            int sizeOfResult = 1 + numOfSubArraysLeft;
            vector<int> result(sizeOfResult);
            // result[0] = sum;
            result[0] = sumOfASubArray + resFoundByCountingASubarrayEndingWithIdx[0];
            for(int i = 0; i<numOfSubArraysLeft-1; i++) {
                result[i+1] = resFoundByCountingASubarrayEndingWithIdx[i+1];
            }
            result[sizeOfResult-1] = idx-sizeOfSubArray+1;
            dp[idx][numOfSubArraysLeft] = result;
        } else {
            dp[idx][numOfSubArraysLeft] = resFoundBySkippingIdx;
        }

        return dp[idx][numOfSubArraysLeft];
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // dp[PrefixOfArrayToBeCovered][numOfSubArraysLeft] = [sum, ...idx]

        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(4, vector<int>(4, -1)));
        sizeOfSubArray = k; n = nums.size();
        this->nums = nums;

        // base case
        for(int i = 0; i<nums.size(); i++) {
            dp[i][0] = {0};
        }

        vector<int> result = rec_call(nums.size()-1, 3, dp);
        cout<<"SUM: " <<result[0]<<"\n";
        vector<int> res(3);
        for(int i = 0; i<3; i++) {
            res[i] = result[i+1];
        }
        return res;
    }
};
int main() {
    // Add your test cases here
    // Example:
    // Solution solution;
    // cout << solution.exampleMethod(5) << "\n";

    vector<int> nums = {1,2,1,2,1,2,1,2,1};
    int k = 2;
    Solution solution;
    vector<int> result = solution.maxSumOfThreeSubarrays(nums, k);
    for(int i = 0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}