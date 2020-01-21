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
    stru_declarations declarations;
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
 * 利用输出流，将内存中的vectror、struct等内容转换为xml格式（序列化）
 * 目前展示自定义类型的序列化，其他vector等的序列化，放开注释即可
 * 
 * @return 返回序列化之后的结果
*/
std::string save()
{
    // std::ofstream file("archive.xml");
    std::string ret;
    std::stringstream ss;
    boost::archive::xml_oarchive oa(ss);

    // float array[] = {34.2, 78.1, 22.221, 1.0, -910.88};
    // int array2[] = {34, 78, 22, 10, -910};
    // std::list<float> L1(array, array + 5);
    // std::list<int> L2(array2, array2 + 5);
    // std::vector<float> V1(array, array + 5);

    stru_operational_info stru_oi;
    stru_oi.declarations.supported_mplane_version = "version of 1.1";
    stru_oi.clock.timezone_utc_offset = 156;
    stru_oi.re_call_home_no_ssh_timer = 116;

    // oa &BOOST_SERIALIZATION_NVP(L1); // 序列化
    // oa &BOOST_SERIALIZATION_NVP(L2);
    // oa &BOOST_SERIALIZATION_NVP(V1);
    oa &BOOST_SERIALIZATION_NVP(stru_oi);

    ret = ss.str();
    // std::cout << ret << std::endl;

    return ret;
}

void load(std::string ret)
{
    // std::ifstream file("archive.xml");
    std::stringstream iss;
    iss << ret;
    boost::archive::xml_iarchive ia(iss);

    std::cout << iss.str() << std::endl;

    // std::list<float> L2;
    // ia >> BOOST_SERIALIZATION_NVP(L2);

    // std::vector<float> V2;
    // ia >> BOOST_SERIALIZATION_NVP(V2);

    // stru_operational_info *stru_oi = new stru_operational_info;
    stru_operational_info stru_oi;
    ia >> BOOST_SERIALIZATION_NVP(stru_oi);

    // std::ostream_iterator<float> oi(std::cout, " ");
    // std::copy(L2.begin(), L2.end(), oi);
    // std::copy(V2.begin(), V2.end(), oi);
}

int main()
{
    load(save());
}
