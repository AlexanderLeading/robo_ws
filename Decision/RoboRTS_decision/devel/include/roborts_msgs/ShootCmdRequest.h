// Generated by gencpp from file roborts_msgs/ShootCmdRequest.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_SHOOTCMDREQUEST_H
#define ROBORTS_MSGS_MESSAGE_SHOOTCMDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roborts_msgs
{
template <class ContainerAllocator>
struct ShootCmdRequest_
{
  typedef ShootCmdRequest_<ContainerAllocator> Type;

  ShootCmdRequest_()
    : mode(0)
    , number(0)
    , shoot_freq(0)  {
    }
  ShootCmdRequest_(const ContainerAllocator& _alloc)
    : mode(0)
    , number(0)
    , shoot_freq(0)  {
  (void)_alloc;
    }



   typedef uint8_t _mode_type;
  _mode_type mode;

   typedef uint8_t _number_type;
  _number_type number;

   typedef uint8_t _shoot_freq_type;
  _shoot_freq_type shoot_freq;





  typedef boost::shared_ptr< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ShootCmdRequest_

typedef ::roborts_msgs::ShootCmdRequest_<std::allocator<void> > ShootCmdRequest;

typedef boost::shared_ptr< ::roborts_msgs::ShootCmdRequest > ShootCmdRequestPtr;
typedef boost::shared_ptr< ::roborts_msgs::ShootCmdRequest const> ShootCmdRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roborts_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'roborts_msgs': ['/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg', '/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg', '/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8a6fbabf4a81c5455c2d4486632e499e";
  }

  static const char* value(const ::roborts_msgs::ShootCmdRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8a6fbabf4a81c545ULL;
  static const uint64_t static_value2 = 0x5c2d4486632e499eULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/ShootCmdRequest";
  }

  static const char* value(const ::roborts_msgs::ShootCmdRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 mode\n\
uint8 number\n\
uint8 shoot_freq\n\
";
  }

  static const char* value(const ::roborts_msgs::ShootCmdRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mode);
      stream.next(m.number);
      stream.next(m.shoot_freq);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ShootCmdRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::ShootCmdRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::ShootCmdRequest_<ContainerAllocator>& v)
  {
    s << indent << "mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "number: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.number);
    s << indent << "shoot_freq: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.shoot_freq);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_SHOOTCMDREQUEST_H
