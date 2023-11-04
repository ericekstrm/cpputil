#include <gtest/gtest.h>

#include <cpputil/logger.h>
#include <fstream>

#include <sstream>

using namespace std;

TEST(Logger, Base)
{
    // log::stdout(false);
    log::output_file("test.txt");

    log::info("abc");
    log::warning("d{}f", 'e');
    log::error("ghi");
    log::debug("jkl");

    log::closefile();

    std::ifstream ifs {"test.txt"};
    std::string filecontents {std::istreambuf_iterator<char>(ifs),
                              std::istreambuf_iterator<char>()};

    ASSERT_EQ(filecontents, "[] abc\n[] cde\n");
    ifs.close();
}
