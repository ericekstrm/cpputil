#pragma once

#include <chrono>

class Timer
{
public:

    Timer()
        : prev {std::chrono::steady_clock::now()}
    {
    }

    double as_seconds() const
    {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff { now - prev };
        return diff.count();
    }
    
    double as_millis() const
    {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> diff { now - prev };
        return diff.count();
    }
    
    void reset()
    {
        prev = std::chrono::steady_clock::now();
    }
    
private:
    
    std::chrono::time_point<std::chrono::system_clock> prev;
    
};
