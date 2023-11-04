#pragma once

#include <ostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

class log
{
public:
    static void print_all_fmt_colors()
    {
        std::map<std::string, fmt::color> m {
            {"alice_blue", fmt::color::alice_blue},           // rgb(240,248,255)
            {"antique_white", fmt::color::antique_white},     // rgb(250,235,215)
            {"aqua", fmt::color::aqua},                       // rgb(0,255,255)
            {"aquamarine", fmt::color::aquamarine},           // rgb(127,255,212)
            {"azure", fmt::color::azure},                     // rgb(240,255,255)
            {"beige", fmt::color::beige},                     // rgb(245,245,220)
            {"bisque", fmt::color::bisque},                   // rgb(255,228,196)
            {"black", fmt::color::black},                     // rgb(0,0,0)
            {"blanched_almond", fmt::color::blanched_almond}, // rgb(255,235,205)
            {"blue", fmt::color::blue},                       // rgb(0,0,255)
            {"blue_violet", fmt::color::blue_violet},         // rgb(138,43,226)
            {"brown", fmt::color::brown},                     // rgb(165,42,42)
            {"burly_wood", fmt::color::burly_wood},           // rgb(222,184,135)
            {"cadet_blue", fmt::color::cadet_blue},           // rgb(95,158,160)
            {"chartreuse", fmt::color::chartreuse},           // rgb(127,255,0)
            {"chocolate", fmt::color::chocolate},             // rgb(210,105,30)
            {"coral", fmt::color::coral},                     // rgb(255,127,80)
            {"cornflower_blue", fmt::color::cornflower_blue}, // rgb(100,149,237)
            {"cornsilk", fmt::color::cornsilk},               // rgb(255,248,220)
            {"crimson", fmt::color::crimson},                 // rgb(220,20,60)
            {"cyan", fmt::color::cyan},                       // rgb(0,255,255)
            {"dark_blue", fmt::color::dark_blue},             // rgb(0,0,139)
            {"dark_cyan", fmt::color::dark_cyan},             // rgb(0,139,139)
            {"dark_golden_rod", fmt::color::dark_golden_rod}, // rgb(184,134,11)
            {"dark_gray", fmt::color::dark_gray},             // rgb(169,169,169)
            {"dark_green", fmt::color::dark_green},           // rgb(0,100,0)
            {"dark_khaki", fmt::color::dark_khaki},           // rgb(189,183,107)
            {"dark_magenta", fmt::color::dark_magenta},       // rgb(139,0,139)
            {"dark_olive_green", fmt::color::dark_olive_green}, // rgb(85,107,47)
            {"dark_orange", fmt::color::dark_orange},           // rgb(255,140,0)
            {"dark_orchid", fmt::color::dark_orchid},           // rgb(153,50,204)
            {"dark_red", fmt::color::dark_red},                 // rgb(139,0,0)
            {"dark_salmon", fmt::color::dark_salmon},         // rgb(233,150,122)
            {"dark_sea_green", fmt::color::dark_sea_green},   // rgb(143,188,143)
            {"dark_slate_blue", fmt::color::dark_slate_blue}, // rgb(72,61,139)
            {"dark_slate_gray", fmt::color::dark_slate_gray}, // rgb(47,79,79)
            {"dark_turquoise", fmt::color::dark_turquoise},   // rgb(0,206,209)
            {"dark_violet", fmt::color::dark_violet},         // rgb(148,0,211)
            {"deep_pink", fmt::color::deep_pink},             // rgb(255,20,147)
            {"deep_sky_blue", fmt::color::deep_sky_blue},     // rgb(0,191,255)
            {"dim_gray", fmt::color::dim_gray},               // rgb(105,105,105)
            {"dodger_blue", fmt::color::dodger_blue},         // rgb(30,144,255)
            {"fire_brick", fmt::color::fire_brick},           // rgb(178,34,34)
            {"floral_white", fmt::color::floral_white},       // rgb(255,250,240)
            {"forest_green", fmt::color::forest_green},       // rgb(34,139,34)
            {"fuchsia", fmt::color::fuchsia},                 // rgb(255,0,255)
            {"gainsboro", fmt::color::gainsboro},             // rgb(220,220,220)
            {"ghost_white", fmt::color::ghost_white},         // rgb(248,248,255)
            {"gold", fmt::color::gold},                       // rgb(255,215,0)
            {"golden_rod", fmt::color::golden_rod},           // rgb(218,165,32)
            {"gray", fmt::color::gray},                       // rgb(128,128,128)
            {"green", fmt::color::green},                     // rgb(0,128,0)
            {"green_yellow", fmt::color::green_yellow},       // rgb(173,255,47)
            {"honey_dew", fmt::color::honey_dew},             // rgb(240,255,240)
            {"hot_pink", fmt::color::hot_pink},               // rgb(255,105,180)
            {"indian_red", fmt::color::indian_red},           // rgb(205,92,92)
            {"indigo", fmt::color::indigo},                   // rgb(75,0,130)
            {"ivory", fmt::color::ivory},                     // rgb(255,255,240)
            {"khaki", fmt::color::khaki},                     // rgb(240,230,140)
            {"lavender", fmt::color::lavender},               // rgb(230,230,250)
            {"lavender_blush", fmt::color::lavender_blush},   // rgb(255,240,245)
            {"lawn_green", fmt::color::lawn_green},           // rgb(124,252,0)
            {"lemon_chiffon", fmt::color::lemon_chiffon},     // rgb(255,250,205)
            {"light_blue", fmt::color::light_blue},           // rgb(173,216,230)
            {"light_coral", fmt::color::light_coral},         // rgb(240,128,128)
            {"light_cyan", fmt::color::light_cyan},           // rgb(224,255,255)
            {"light_golden_rod_yellow", fmt::color::light_golden_rod_yellow},            // rgb(250,250,210)
            {"light_gray", fmt::color::light_gray},           // rgb(211,211,211)
            {"light_green", fmt::color::light_green},         // rgb(144,238,144)
            {"light_pink", fmt::color::light_pink},           // rgb(255,182,193)
            {"light_salmon", fmt::color::light_salmon},       // rgb(255,160,122)
            {"light_sea_green", fmt::color::light_sea_green}, // rgb(32,178,170)
            {"light_sky_blue", fmt::color::light_sky_blue},   // rgb(135,206,250)
            {"light_slate_gray", fmt::color::light_slate_gray}, // rgb(119,136,153)
            {"light_steel_blue", fmt::color::light_steel_blue},             // rgb(176,196,222)
            {"light_yellow", fmt::color::light_yellow}, // rgb(255,255,224)
            {"lime", fmt::color::lime},                 // rgb(0,255,0)
            {"lime_green", fmt::color::lime_green},     // rgb(50,205,50)
            {"linen", fmt::color::linen},               // rgb(250,240,230)
            {"magenta", fmt::color::magenta},           // rgb(255,0,255)
            {"maroon", fmt::color::maroon},             // rgb(128,0,0)
            {"medium_aquamarine", fmt::color::medium_aquamarine},              // rgb(102,205,170)
            {"medium_blue", fmt::color::medium_blue},     // rgb(0,0,205)
            {"medium_orchid", fmt::color::medium_orchid}, // rgb(186,85,211)
            {"medium_purple", fmt::color::medium_purple}, // rgb(147,112,219)
            {"medium_sea_green", fmt::color::medium_sea_green}, // rgb(60,179,113)
            {"medium_slate_blue", fmt::color::medium_slate_blue}, // rgb(123,104,238)
            {"medium_spring_green", fmt::color::medium_spring_green},                  // rgb(0,250,154)
            {"medium_turquoise", fmt::color::medium_turquoise}, // rgb(72,209,204)
            {"medium_violet_red", fmt::color::medium_violet_red},                  // rgb(199,21,133)
            {"midnight_blue", fmt::color::midnight_blue},     // rgb(25,25,112)
            {"mint_cream", fmt::color::mint_cream},           // rgb(245,255,250)
            {"misty_rose", fmt::color::misty_rose},           // rgb(255,228,225)
            {"moccasin", fmt::color::moccasin},               // rgb(255,228,181)
            {"navajo_white", fmt::color::navajo_white},       // rgb(255,222,173)
            {"navy", fmt::color::navy},                       // rgb(0,0,128)
            {"old_lace", fmt::color::old_lace},               // rgb(253,245,230)
            {"olive", fmt::color::olive},                     // rgb(128,128,0)
            {"olive_drab", fmt::color::olive_drab},           // rgb(107,142,35)
            {"orange", fmt::color::orange},                   // rgb(255,165,0)
            {"orange_red", fmt::color::orange_red},           // rgb(255,69,0)
            {"orchid", fmt::color::orchid},                   // rgb(218,112,214)
            {"pale_golden_rod", fmt::color::pale_golden_rod}, // rgb(238,232,170)
            {"pale_green", fmt::color::pale_green},           // rgb(152,251,152)
            {"pale_turquoise", fmt::color::pale_turquoise},   // rgb(175,238,238)
            {"pale_violet_red", fmt::color::pale_violet_red}, // rgb(219,112,147)
            {"papaya_whip", fmt::color::papaya_whip},         // rgb(255,239,213)
            {"peach_puff", fmt::color::peach_puff},           // rgb(255,218,185)
            {"peru", fmt::color::peru},                       // rgb(205,133,63)
            {"pink", fmt::color::pink},                       // rgb(255,192,203)
            {"plum", fmt::color::plum},                       // rgb(221,160,221)
            {"powder_blue", fmt::color::powder_blue},         // rgb(176,224,230)
            {"purple", fmt::color::purple},                   // rgb(128,0,128)
            {"rebecca_purple", fmt::color::rebecca_purple},   // rgb(102,51,153)
            {"red", fmt::color::red},                         // rgb(255,0,0)
            {"rosy_brown", fmt::color::rosy_brown},           // rgb(188,143,143)
            {"royal_blue", fmt::color::royal_blue},           // rgb(65,105,225)
            {"saddle_brown", fmt::color::saddle_brown},       // rgb(139,69,19)
            {"salmon", fmt::color::salmon},                   // rgb(250,128,114)
            {"sandy_brown", fmt::color::sandy_brown},         // rgb(244,164,96)
            {"sea_green", fmt::color::sea_green},             // rgb(46,139,87)
            {"sea_shell", fmt::color::sea_shell},             // rgb(255,245,238)
            {"sienna", fmt::color::sienna},                   // rgb(160,82,45)
            {"silver", fmt::color::silver},                   // rgb(192,192,192)
            {"sky_blue", fmt::color::sky_blue},               // rgb(135,206,235)
            {"slate_blue", fmt::color::slate_blue},           // rgb(106,90,205)
            {"slate_gray", fmt::color::slate_gray},           // rgb(112,128,144)
            {"snow", fmt::color::snow},                       // rgb(255,250,250)
            {"spring_green", fmt::color::spring_green},       // rgb(0,255,127)
            {"steel_blue", fmt::color::steel_blue},           // rgb(70,130,180)
            {"tan", fmt::color::tan},                         // rgb(210,180,140)
            {"teal", fmt::color::teal},                       // rgb(0,128,128)
            {"thistle", fmt::color::thistle},                 // rgb(216,191,216)
            {"tomato", fmt::color::tomato},                   // rgb(255,99,71)
            {"turquoise", fmt::color::turquoise},             // rgb(64,224,208)
            {"violet", fmt::color::violet},                   // rgb(238,130,238)
            {"wheat", fmt::color::wheat},                     // rgb(245,222,179)
            {"white", fmt::color::white},                     // rgb(255,255,255)
            {"white_smoke", fmt::color::white_smoke},         // rgb(245,245,245)
            {"yellow", fmt::color::yellow},                   // rgb(255,255,0)
            {"yellow_green", fmt::color::yellow_green}        // rgb(154,205,50)
        };

        for (auto [n, c] : m)
        {
            fmt::print(fg(c), "{}\n", n);
        }
    }
    
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
            fmt::print(file, "[{}] {}\n", fmt::localtime(t), fmt::format(s, args...));
        }

        if (use_stdout)
        {
            fmt::print(fg(color), "[{:%Y-%m-%d %H:%M:%S}] {}\n", fmt::localtime(t), fmt::format(s, args...));
        }
    }
        
};
