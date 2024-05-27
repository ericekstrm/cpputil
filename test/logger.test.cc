#include <gtest/gtest.h>

#include <cpputil/logger.h>

using namespace std;

TEST(Logger, Base)
{
    log::stdout(false);
    // log::output_file("test.txt");

    log::info("abc");
    log::warning("d{}f", 'e');
    log::error("ghi");
    log::debug("jkl");

    // log::closefile();
}
