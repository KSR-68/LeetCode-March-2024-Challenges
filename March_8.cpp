// 3005. Count Elements With Maximum Frequency
/*
You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

Example 1:
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
*/

#include <bits/stdc++.h>
using namespace std;

//Initial Solution
/* int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int sum = 0;
    int max_freq = 0;
    for (auto i : nums)
    {
        freq[i]++;
        max_freq = max(max_freq, freq[i]);
    }
    for (auto i : freq)
    {
        if (i.second == max_freq)
        {
            sum += max_freq;
        }
    }
    return sum;
} */

//One Pass Solution
int maxFrequecyElements(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int totalFrequency = 0;
    int maxFrequency = 0;

    for (int num : nums)
    {
        freq[num]++;
        int curr_frequency = freq[num];

        if (curr_frequency > maxFrequency)
        {
            maxFrequency = curr_frequency;
            totalFrequency = curr_frequency;
        }

        else if (curr_frequency == maxFrequency)
            totalFrequency += curr_frequency;
    }
    return totalFrequency;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }

    int ans = maxFrequecyElements(nums);
    cout << ans;
    return 0;
}