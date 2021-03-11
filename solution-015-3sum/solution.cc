/**
 * @file solution.cc
 * @author Wonseok Lee <aram_father@naver.com>
 * @brief Solution for leetcode 3Sum
 * @version 0.1
 * @date 2021-03-11
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ret;

    int len = nums.size();
    int pa, pb, pc;
    int a, b, c;

    pa = 0;
    while (pa < len)
    {
      a = nums[pa];

      pb = pa + 1;
      pc = len - 1;
      while (pb < len && pb < pc)
      {
        b = nums[pb];
        c = nums[pc];
        if (b + c < -a)
        {
          // Pass the same 'b's
          while (++pb < len && nums[pb] == b)
          {
          }
        }
        else if (b + c > -a)
        {
          // Pass the same 'c's
          while (--pc >= 0 && nums[pc] == c)
          {
          }
        }
        else
        {
          ret.push_back(vector<int>{ a, b, c });
          // Pass the same 'b's
          while (++pb < len && nums[pb] == b)
          {
          }
          // Pass the same 'c's
          while (--pc >= 0 && nums[pc] == c)
          {
          }
        }
      }

      // Pass the same 'a's
      while (++pa < len && nums[pa] == a)
      {
      }
    }

    return ret;
  }
};