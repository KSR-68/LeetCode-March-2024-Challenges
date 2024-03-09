// 977. Squares of a Sorted Array
/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <bits/stdc++.h>
using namespace std;
// Brute Force O(NlogN)
/* vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> ans;
    for (auto num : nums)
    {
        int n = num * num;
        ans.emplace_back(n);
    }
    sort(ans.begin(), ans.end());
    return ans;
} */

// Better O(N) and O(N) Space
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[left] > nums[right])
        {
            ans[i] = nums[left];
            left++;
        }
        else
        {
            ans[i] = nums[right];
            right--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ans = sortedSquares(nums);

    for (int i : ans)
        cout << i << " ";

    return 0;
}