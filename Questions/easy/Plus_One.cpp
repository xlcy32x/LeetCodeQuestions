#include "..\..\Header\inc.h"

class Solution : public SolutionBase<Solution>
{
public:
    Solution()
    {
        std::cout<<"Given a non-empty array of digits representing a non-negative integer, plus one to the integer."<<std::endl;
        std::cout<<"The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit."<<std::endl;
        std::cout<<"You may assume the integer does not contain any leading zero, except the number 0 itself."<<std::endl;
        
        std::cout<<"Example 1:"<<std::endl;
        std::cout<<"Input: [1,2,3]"<<std::endl;
        std::cout<<"Output: [1,2,4]"<<std::endl;
        std::cout<<"Explanation: The array represents the integer 123."<<std::endl;
        
        std::cout<<"Example 2:"<<std::endl;
        std::cout<<"Input: [4,3,2,1]std::endl;
        std::cout<<"Output: [4,3,2,2]"<<std::endl;
        std::cout<<"Explanation: The array represents the integer 4321."<<std::endl;
    }

    std::vector<int> plusOne(std::vector<int>& digits)
    {
        if(digits[digits.size() -1] == 9)
        {
          std::vector<int> newDigits;
          newDigits.reserve(digits.size() + 1);
        }
        else
        {
          ++digits[digits.size() -1];
        }
        return digits;
    }

    //test case to be input here
    void Do(const std::string& s)
    {
        std::cout<<"Result : "<<FindLastWord(s)<<std::endl;
    }
};

int main()
{
    std::unique_ptr<SolutionBase<Solution>> solutionPtr(new Solution);
    solutionPtr->Do("a");
    solutionPtr->Do("a ");
    solutionPtr->Do(" a ");
    solutionPtr->Do("a    ");
    solutionPtr->Do("  a  ");
    solutionPtr->Do("  aaaaa  ");
    std::cin.get();
}