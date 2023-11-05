#pragma once

#include <ostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

class log
{
public:
    static inline std::FILE *file {};
    static inline bool use_stdout {true};

    static void output_file(std::string const &filename)
    {
        file = std::fopen(filename.c_str(), "w");
    }
    
    static void closefile()
    {
        fclose(file);
        file = nullptr;
    }

    static void stdout(bool b)
    {
        use_stdout = b;
    }
    
    template <typename... Args>
    static void info(std::string_view s, Args... args)
    {
        print_help(fmt::color::white, s, args...);
    }

    template <typename... Args>
    static void warning(std::string_view s, Args... args)
    {
        print_help(fmt::color::orange, s, args...);
    }
    
    template <typename... Args>
    static void error(std::string_view s, Args... args)
    {
        print_help(fmt::color::brown, s, args...);
    }
    
    template <typename... Args>
    static void debug(std::string_view s, Args... args)
    {
        print_help(fmt::color::steel_blue, s, args...);
    }

private:
    
    template <typename... Args>
    static void print_help(fmt::color color, std::string_view s, Args... args)
    {
        std::time_t t { std::time(nullptr) };
        
        if (file != nullptr)
        {
            fmt::print(file, "[{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(t), fmt::format(s, args...));
        }

        if (use_stdout)
        {
            fmt::print(fmt::fg(color), "[{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(t), fmt::format(s, args...));
        }
    }
        
};
