/**
 * @file solution.cc
 * @author Wonseok Lee <aram_father@naver.com>
 * @brief Solution for leetcode Longest Palindromic Substring
 * @version 0.1
 * @date 2021-04-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string getPreprocessed(const string& s)
  {
    string preprocessed;

    for (int i = 0; i < s.size(); ++i)
    {
      preprocessed.push_back('$');
      preprocessed.push_back(s[i]);
    }
    preprocessed.push_back('$');

    return preprocessed;
  }

  int getRadius(const string& s, int i, int hint)
  {
    int radius = hint;
    int l = i - hint - 1;
    int r = i + hint + 1;
    while (0 <= l && r < s.length())
    {
      if (s[l--] == s[r++])
      {
        ++radius;
      }
      else
      {
        break;
      }
    }

    return radius;
  }

  string filter(const string& preprocessed, int lps_pos, int lps_radius)
  {
    string filtered;

    for (int i = 0; i < 2 * lps_radius + 1; ++i)
    {
      if (preprocessed[lps_pos - lps_radius + i] != '$')
      {
        filtered.push_back(preprocessed[lps_pos - lps_radius + i]);
      }
    }

    return filtered;
  }

  string longestPalindrome(string s)
  {
    int lps_pos = 0;     // Start position of 'Longest Palindromic Substring'
    int lps_radius = 0;  // Radius of 'Longest Palindromic Substring'

    string preprocessed = getPreprocessed(s);

    int rightmost_center = 0;
    vector<int> radius(preprocessed.length(), 0);

    // Obviously, radius[0] is 0. So we can  start iteration from i = 1
    for (int i = 1; i < preprocessed.length(); ++i)
    {
      int hint;

      // Case 1
      if (rightmost_center + radius[rightmost_center] >= i)
      {
        int mirror = rightmost_center - (i - rightmost_center);
        hint = min(radius[mirror], mirror - (rightmost_center - radius[rightmost_center]));
      }
      // Case 2
      else
      {
        hint = 0;
      }

      radius[i] = getRadius(preprocessed, i, hint);

      if (radius[i] > lps_radius)
      {
        lps_pos = i;
        lps_radius = radius[i];
      }

      if (i + radius[i] > rightmost_center + radius[rightmost_center])
      {
        rightmost_center = i;
      }
    }

    return filter(preprocessed, lps_pos, lps_radius);
  }
};