#include "..\..\Header\inc.h"

class TransportTicket : public SolutionBase<TransportTicket>
{
public:
  TransportTicket()
    {
        std::cout<<"One day pass is 2$, 7 day pass is 7$ (can be used for 7 consective days, lets say 2-8, or 3-9)"<<std::endl;
        std::cout<<"One month pass is 25$"<<std::endl;
        std::cout<<"The guys will need to transport on any combinations of the days in a months. eg: {1,3,4,6,7,8,9,28,29}"<<std::endl;
        std::cout<<"Find the most cost effective ways to buying the ticket."<<std::endl;
        std::cout<<"--------------------------------------------------------"<<std::endl;
        std::cout<<"In above example, buy a 7 day pass for 3-9, cost 7$"<<std::endl;
        std::cout<<"The 1st of the month, buy a one day pass, for 2$"<<std::endl;
        std::cout<<"the 28/29, buy a one day pass for each day, for 2*2=4$"<<std::endl;
        std::cout<<"total cost is 13$."<<std::endl;
    }

    std::vector<int> GetWeekWindow(const std::vector<unsigned>& days, int start)
    {
        const int lastDayOfMonth = 31;
        const int day7 = days[start] + 6;
        int lastDayOfWeek = day7 >= lastDayOfMonth ? lastDayOfMonth : day7;
        std::vector<int> weekWindow;
        weekWindow.reserve(7);
        weekWindow.emplace_back(start);

        for(int i = start + 1; i < days.size(); ++i)
        {
            if(days[i] > lastDayOfWeek)
            {
                break;
            }
            weekWindow.push_back(i);
        }
        return weekWindow;
    }

    int CalculateTicketCost(const std::vector<unsigned>& days)
    {
        if(days.size() > 12)
        {
            return 25;
        }

        if(days.size() <= 3)
        {
            return days.size() * 2;
        }

        const int daysInMonthCount = 31;
        std::vector<std::vector<int>> weekWindowList;
        weekWindowList.reserve(days.size());
        
        // Computing Week Windows
        for(int i = 0; i < days.size(); ++i)
        {
            std::vector<int> weekWindow = GetWeekWindow(days, i);
            weekWindowList.push_back(weekWindow);
            for (auto& elem : weekWindow)
              std::cout << elem << ", ";
            std::cout << std::endl;
        }

        //Leaving only Week Window with no duplicated window
        std::vector<int> weekWindowListWithNoDuplicates;
        weekWindowListWithNoDuplicates.reserve(weekWindowList.size());
        for(int i = 0; i < weekWindowList.size();++i)
        {
            weekWindowListWithNoDuplicates.push_back(i);
            for(int j = i + 1; j < weekWindowList.size(); ++j)
            {
                if (weekWindowList[j].back() > weekWindowList[i].back())
                {
                    i = j - 1;
                    break;
                }
                else
                {
                  if (i == weekWindowList.size() - 2 && j == weekWindowList.size() - 1)
                    i = j;
                }
            }
        }
        for (auto& elem : weekWindowListWithNoDuplicates)
            std::cout << elem << ", ";
        std::cout << std::endl;

        //check for window overlap.
        for (int i = 0; i < weekWindowListWithNoDuplicates.size(); ++i)
        {
          int currentWeekSize = weekWindowList[weekWindowListWithNoDuplicates[i]].size();
          if(currentWeekSize > 3)
          {
            for (int j = i + 1; j < weekWindowListWithNoDuplicates.size(); ++j)
            {
              if (weekWindowList[weekWindowListWithNoDuplicates[i]].back() >= weekWindowList[weekWindowListWithNoDuplicates[j]].front()
                && weekWindowList[weekWindowListWithNoDuplicates[i]].back() <= weekWindowList[weekWindowListWithNoDuplicates[j]].back())
              {
                
              }
            }
          }
          
        }
        return 0;
    }

    void Do(const std::vector<unsigned>& days)
    {
        std::cout<<"Days commute to work : "<<std::endl;
        std::cout<<"[";
        for(auto& elem : days)
        {
            std::cout<<elem<<' ';
        }
        std::cout<<"]"<<std::endl;
        std::cout << "total cost is " << CalculateTicketCost(days) << "$." << std::endl;
    }
};


int main()
{
    int * ptr = nullptr;
    *ptr = 10;
    std::unique_ptr<SolutionBase<TransportTicket>> solutionPtr(new TransportTicket);
    solutionPtr->Do<const std::vector<unsigned>&>(std::vector<unsigned>{1, 3,4,6,7,8,9,28,29});
    std::cin.get();
}