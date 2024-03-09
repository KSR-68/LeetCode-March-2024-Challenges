#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
            return nums1[i];
        else if (nums1[i] < nums2[j])
            i++;
        else if (nums2[j] < nums1[i])
            j++;
    }
    return -1;
}

int main()
{
    vector<int> nums1;
    vector<int> nums2;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums1.emplace_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        nums2.emplace_back(a);
    }

    int ans = getCommon(nums1,nums2);
    cout<<ans;

    return 0;
}
