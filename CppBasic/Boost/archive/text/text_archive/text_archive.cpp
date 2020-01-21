
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <iostream>
#include <fstream>

void save()
{
    std::ofstream file("archive.txt");
    boost::archive::text_oarchive oa(file);
    std::string s = "Hello World!\n";
    oa &s; // has same effect as oa << s;
}

void load()
{
    std::ifstream file("archive.txt");
    boost::archive::text_iarchive ia(file);
    std::string s;
    ia &s;
    std::cout << s << std::endl;
}
