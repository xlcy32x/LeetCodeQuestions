#include "..\..\Header\inc.h"

class Solution : public SolutionBase<Solution>
{
public:
    Solution()
    {
        std::cout<<"Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum."<<std::endl;
    }

    int maxSubArray_NaiveSolution(std::vector<int>& nums)
    {
      int highestValue = nums[0];
      for (int i = 0; i < nums.size(); ++i)
      {
        int value = 0;
        for (int j = i; j < nums.size(); ++j)
        {
          // index 0 to index 1
          // index 0 to index 2
          value += nums[j];
          //map[i][j] = value;
          if (value > highestValue)
            highestValue = value;
          std::cout << '[' << i << ", " << j << "] = " << value << std::endl;
        }
      }
      return highestValue;
    }

    int maxSubArray_Naive(std::vector<int>& nums)
    {
      int highestValue = nums[0];
      for (int i = 0; i < nums.size(); ++i)
      {
        int value = 0;
        for (int j = i; j < nums.size(); ++j)
        {
          // index 0 to index 1
          // index 0 to index 2
          value += nums[j];
          //map[i][j] = value;
          if (value > highestValue)
            highestValue = value;
          std::cout << '[' << i << ", " << j << "] = " << value << std::endl;
        }
      }
      return highestValue;
    }

    //test case to be input here
    void Do(std::vector<int>& nums)
    {
        std::cout<<"Result : "<<maxSubArray_NaiveSolution(nums)<<std::endl;
    }
};

int main()
{
    std::unique_ptr<SolutionBase<Solution>> solutionPtr(new Solution);
    solutionPtr->Do(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4});
    solutionPtr->Do(std::vector<int>{-2, 1});
    // std::cin.get();
}