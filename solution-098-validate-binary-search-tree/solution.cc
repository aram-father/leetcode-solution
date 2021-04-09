/**
 * @file solution.cc
 * @author Wonseok Lee <aram_father@naver.com>
 * @brief Solution for leetcode Validate Binary Search Tree
 * @version 0.1
 * @date 2021-04-09
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <vector>
#include <stack>

class Solution
{
public:
  bool is_first_visit_ = true;
  int last_visited_number_;

  bool isValidBST(TreeNode* root)
  {
    if (!root)
    {
      return true;
    }

    if (!isValidBST(root->left))
    {
      return false;
    }

    if (!is_first_visit_ && last_visited_number_ >= root->val)
    {
      return false;
    }

    is_first_visit_ = false;
    last_visited_number_ = root->val;

    if (!isValidBST(root->right))
    {
      return false;
    }

    return true;
  }
};