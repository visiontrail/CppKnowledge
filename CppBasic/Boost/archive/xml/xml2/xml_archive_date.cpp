#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp> 
#include <boost/archive/binary_oarchive.hpp> 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <fstream>
#include <string>

typedef struct date
{
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

    date(int d, int m, int y) : m_day(d), m_month(m), m_year(y)
    {
    }
    date() : m_day(1), m_month(1), m_year(2000)
    {
    }
    friend std::ostream &operator<<(std::ostream &out, date &d)
    {
        out << "day:" << d.m_day
            << " month:" << d.m_month
            << " year:" << d.m_year;
        return out;
    }
    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(m_day);
        archive &BOOST_SERIALIZATION_NVP(m_month);
        archive &BOOST_SERIALIZATION_NVP(m_year);
    }
} date;

std::string save()
{
    // std::ofstream file("archive.xml");
    std::ostringstream oss;
    boost::archive::xml_oarchive oa(oss);

    date d(15, 8, 1947);
    oa &BOOST_SERIALIZATION_NVP(d);

    return oss.str();
}

void load(std::string ret)
{
    // std::ifstream file("archive.xml"); 
    ret = ret.substr(158);
    std::istringstream iss(ret);
    std::cout << "get the xml : \n" << iss.str() << std::endl;

    boost::property_tree::ptree pt;
    read_xml(iss, pt);

    date d;
    std::cout << pt.get("d.m_day", NULL) << std::endl;

    // boost::archive::xml_iarchive ia(iss);
    // date dr;
    // ia >> BOOST_SERIALIZATION_NVP(dr);
    // std::cout << dr;
}

int main()
{
    load(save());
    return 0;
}