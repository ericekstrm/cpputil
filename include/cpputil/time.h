#pragma once

#include <chrono>

class Timer
{
public:

    Timer()
        : prev {std::chrono::steady_clock::now()}
    {
    }

    template<typename Rep = std::ratio<1>>
    double now() const
    {
        auto time_now = std::chrono::steady_clock::now();
        std::chrono::duration<double, Rep> diff { time_now - prev };
        return diff.count();
    }
    
    void reset()
    {
        prev = std::chrono::steady_clock::now();
    }
    
private:
    
    std::chrono::time_point<std::chrono::steady_clock> prev;
    
};
