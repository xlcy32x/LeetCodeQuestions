#pragma once
#include "inc.h"

template <typename DERIVING>
class SolutionBase
{
public:
    SolutionBase()
    {
        
    }

    //test case to be input in deriving class
    template <typename ...Args>
    void Do(Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        static_cast<DERIVING&>(*this).Do(std::forward<Args>(args)...);
        auto end = std::chrono::steady_clock::now();

        std::cout<<"Time Difference (milli sec) : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<std::endl;
        std::cout<<"Time Difference (micro sec) : "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;
        std::cout<<"Time Difference (nano sec) : "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()<<std::endl;
    }

    ~SolutionBase()
    {

    }
};