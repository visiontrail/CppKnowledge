#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

typedef struct stru_declarations
{
    // 成员
    std::string supported_mplane_version;
    std::string supported_cusplane_version;
    std::vector<std::uint16_t> supported_header_mechanisms;

    friend std::ostream &operator<<(std::ostream &out, stru_declarations &d)
    {
        out << "out tag_stru_declarations";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(supported_mplane_version);
        archive &BOOST_SERIALIZATION_NVP(supported_cusplane_version);
        archive &BOOST_SERIALIZATION_NVP(supported_header_mechanisms);
    }

} stru_declarations;

typedef struct stru_operational_state
{
    // 成员
    std::string restart_datetime;

    friend std::ostream &operator<<(std::ostream &out, stru_operational_state &d)
    {
        out << "out tag_stru_operational_state";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(restart_datetime);
    }

} stru_operational_state;

typedef struct stru_clock
{
    // 成员
    uint16_t timezone_utc_offset;

    friend std::ostream &operator<<(std::ostream &out, stru_clock &d)
    {
        out << "out tag_stru_clock";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(timezone_utc_offset);
    }

} stru_clock;

typedef struct stru_operational_info
{
    // 成员
    std::vector<stru_declarations> declarations;
    stru_operational_state operational_state;
    stru_clock clock;
    uint16_t re_call_home_no_ssh_timer;

    friend std::ostream &operator<<(std::ostream &out, stru_operational_info &d)
    {
        out << "out tag_stru_operational_info";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(declarations);
        archive &BOOST_SERIALIZATION_NVP(operational_state);
        archive &BOOST_SERIALIZATION_NVP(clock);
        archive &BOOST_SERIALIZATION_NVP(re_call_home_no_ssh_timer);
    }
} stru_operational_info;

/*
 * 利用输出流，将内存中的vectror、struct等内容转换为xml格式（序列化）为stringstream
 * 目前展示的是自定义类型的序列化
 * 
 * @return 返回序列化之后的结果
*/
std::string save()
{
    // std::string ret;
    // std::stringstream ss;
    // boost::archive::xml_oarchive oa(ss);

    // stru_operational_info stru_oi;
    // stru_oi.declarations.supported_mplane_version = "version of 1.1";
    // stru_oi.declarations.supported_header_mechanisms.push_back(1);
    // stru_oi.declarations.supported_header_mechanisms.push_back(123);
    // stru_oi.clock.timezone_utc_offset = 156;
    // stru_oi.re_call_home_no_ssh_timer = 116;

    // // Binary ---> XML
    // oa &BOOST_SERIALIZATION_NVP(stru_oi);

    // ret = ss.str();
    // ret += "</boost_serialization>"; // streamstream序列化的时候，缺少了最终的结束符，可能是boost的bug

    // std::cout << "Save XML TO string stream: __________________________________________________________________ \n"
    //           << ret << std::endl;

    // return ret;
}

void save_file()
{
    std::ofstream file("archive.xml");
    boost::archive::xml_oarchive oa(file);

    stru_declarations decl;
    decl.supported_mplane_version = "version of 1.1";
    decl.supported_header_mechanisms.push_back(1);
    decl.supported_header_mechanisms.push_back(123);

    stru_declarations decl2;
    decl2.supported_mplane_version = "version of 1.2";
    decl2.supported_header_mechanisms.push_back(431);

    stru_operational_info stru_oi;
    stru_oi.declarations.push_back(decl);
    stru_oi.declarations.push_back(decl2);
    stru_oi.clock.timezone_utc_offset = 156;
    stru_oi.re_call_home_no_ssh_timer = 116;

    oa &BOOST_SERIALIZATION_NVP(stru_oi);
}

void load(std::string ret)
{
    // std::ofstream ofile("archive2.xml");
    // std::ostringstream oss;
    // ofile.write(ret.c_str(), ret.length());
    // ofile.close();
    // std::ifstream ifile("archive2.xml");

    std::cout << "Get XML from string stream: __________________________________________________________________ \n"
              << ret << std::endl;

    std::stringstream iss;
    iss << ret;

    boost::archive::xml_iarchive ia(iss);

    // XML ---> Binary
    stru_operational_info stru_oi;
    ia >> BOOST_SERIALIZATION_NVP(stru_oi);

    std::cout << "Get iarchive stru_oi.clock.timezone_utc_offset result is :"
              << stru_oi.clock.timezone_utc_offset << std::endl;
}

void load_file()
{
    std::ifstream file("archive.xml");

    boost::archive::xml_iarchive ia(file);

    stru_operational_info stru_oi;
    ia >> BOOST_SERIALIZATION_NVP(stru_oi);
    std::cout << stru_oi.clock.timezone_utc_offset << std::endl;
}

int main()
{
    // save_file();
    // sleep(1);
    load_file();

    // load(save());
}
