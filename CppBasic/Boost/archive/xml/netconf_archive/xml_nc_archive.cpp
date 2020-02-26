#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>


typedef struct stru_netconf_client_ipaddr
{
    // 成员
    std::string mplane_ipv4;
    std::string mplane_type;
    uint32_t port;

    friend std::ostream &operator<<(std::ostream &out, stru_netconf_client_ipaddr &d)
    {
        out << "out stru_netconf_client_ipaddr";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(mplane_ipv4);
        archive &BOOST_SERIALIZATION_NVP(mplane_type);
        archive &BOOST_SERIALIZATION_NVP(port);
    }

} stru_netconf_client_ipaddr;

typedef struct stru_m_plane_server_type
{
    // 成员
    std::string netconf_client_ip_type;
    std::vector<stru_netconf_client_ipaddr> netconf_client_ipaddr;

    friend std::ostream &operator<<(std::ostream &out, stru_m_plane_server_type &d)
    {
        out << "out stru_m_plane_server_type";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(netconf_client_ip_type);
        archive &BOOST_SERIALIZATION_NVP(netconf_client_ipaddr);
    }

} stru_m_plane_server_type;

typedef struct stru_m_plane_ssh_ports
{
    // 成员
    uint32_t call_home_ssh_port;
    uint32_t server_ssh_port;

    friend std::ostream &operator<<(std::ostream &out, stru_m_plane_ssh_ports &d)
    {
        out << "out stru_m_plane_ssh_ports";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(call_home_ssh_port);
        archive &BOOST_SERIALIZATION_NVP(server_ssh_port);
    }

} stru_m_plane_ssh_ports;

typedef struct stru_m_plane_sub_interfaces
{
    // 成员
    std::string interface_name;
    std::string sub_interface;

    friend std::ostream &operator<<(std::ostream &out, stru_m_plane_sub_interfaces &d)
    {
        out << "out stru_m_plane_sub_interfaces";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(interface_name);
        archive &BOOST_SERIALIZATION_NVP(sub_interface);
    }

} stru_m_plane_sub_interfaces;

typedef struct stru_m_plane_interfaces
{
    // 成员
    std::vector<stru_m_plane_sub_interfaces> m_plane_sub_interfaces;
    stru_m_plane_ssh_ports m_plane_ssh_ports;
    stru_m_plane_server_type m_plane_server_type;


    friend std::ostream &operator<<(std::ostream &out, stru_m_plane_interfaces &d)
    {
        out << "out stru_m_plane_interfaces";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(m_plane_sub_interfaces);
        archive &BOOST_SERIALIZATION_NVP(m_plane_ssh_ports);
        archive &BOOST_SERIALIZATION_NVP(m_plane_server_type);
    }
} stru_m_plane_interfaces;


typedef struct stru_mplane_group
{
    // 成员
    stru_m_plane_interfaces m_plane_interfaces;

    friend std::ostream &operator<<(std::ostream &out, stru_mplane_group &d)
    {
        out << "out stru_mplane_group";
        return out;
    }

    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &BOOST_SERIALIZATION_NVP(m_plane_interfaces);
    }

} stru_mplane_group;

/*
 * 利用输出流，将内存中的vectror、struct等内容转换为xml格式（序列化）为stringstream
 * 目前展示的是自定义类型的序列化
 * 
 * @return 返回序列化之后的结果
*/
std::string save()
{

    return "";
}


void load(std::string ret)
{
    return;
}

void save_file()
{
}


void load_file()
{
    // 从文件中获取到netconf报文内容
    std::ifstream file("netconf_archive.xml");
    boost::archive::xml_iarchive ia(file);

    stru_mplane_group stru_oi;
    ia >> BOOST_SERIALIZATION_NVP(stru_oi);
    // std::cout << stru_oi.mp_interface.ssh_port.call_home_ssh_port << std::endl;
    
}

int main()
{
    load_file();
}
