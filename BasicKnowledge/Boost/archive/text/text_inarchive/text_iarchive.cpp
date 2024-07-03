//#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <fstream>

void load()
{
    std::ifstream file("../text_outarchive/archive.txt");
    // boost::archive::text_iarchive ia(file);
    std::string s;
    // ia >> s;
    std::cout << s << std::endl;
}

int main()
{
    // load();
}