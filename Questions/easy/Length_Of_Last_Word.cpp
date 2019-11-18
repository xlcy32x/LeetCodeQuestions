#include "..\..\Header\inc.h"

class Solution : public SolutionBase<Solution>
{
public:
    Solution()
    {
        std::cout<<"Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string. If the last word does not exist, return 0."<<std::endl;
    }

    int FindLastWord(const std::string s)
    {
      auto spaceIterator = s.rend();
      if(*s.rbegin() != ' ')
      {
        for(auto it = s.rbegin(); it != s.rend(); ++it)
        {
          if(*it == ' ')
          {
            spaceIterator = it;
            break;
          }
        }
        return spaceIterator - s.rbegin();
      }
      else
      {
        auto startIt = s.rend();
        auto endIt = s.rend();
        for(auto it = s.rbegin(); it != s.rend(); ++it)
        {
          if(*it != ' ')
          {
            startIt = it;
            endIt = startIt + 1;
            for(; endIt != s.rend(); ++endIt)
            {
              if(*endIt == ' ')
                break;
            }
            return endIt - startIt;
          }
        }
      }
      return 0;
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