// 349. Intersection of Two Arrays
/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Approach 1 - Using HashMap (Taking Frequency as decider)

/* vector<int> Intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> f;
    vector<int> ans;
    for (int i : nums1)
    {
        for (int j : nums2)
        {
            if (i == j && f[j] == 0)
            {
                ans.emplace_back(i);
                break;
            }
        }
        f[i]++; // Increase the element frequency which is already added to the result
    }
    return ans;
} */

// Approach 2 - Using a HashSet (Two Pointer Single Pass Approach)
// We Have to sort both the arrays in this approach

/* vector<int> Intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j] && s.find(nums1[i]) == s.end())
        {
            ans.emplace_back(nums1[i]);
            s.insert(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
            j++;
        else
            i++;
    }
    return ans;
} */

// Approach 3 (Make Both Arrays Sets)(Major LeetCode 0ms Solutions)
/* vector<int> Intersection(vector<int>& nums1,vector<int>& nums2){
    unordered_set<int> s1(nums1.begin(),nums1.end());
    unordered_set<int> s2(nums2.begin(),nums2.end());
    vector<int> res;
    for (int num : s1)
    {
        if (s2.find(num) != s2.end())
        {
            res.emplace_back(num);
        }
    }

    return res;
} */

vector<int> Intersection(vector<int>& nums1, vector<int>& nums2){
    vector<int> ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i = 0, j = 0;

    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i] == nums2[j]){
            if(i>0 && nums1[i] == nums1[i-1]){
                i++;
                continue;
            }
            ans.emplace_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]) i++;
        else j++;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    vector<int> ans = Intersection(nums1, nums2);
    for (int i : ans)
        cout << i << " ";

    return 0;
}