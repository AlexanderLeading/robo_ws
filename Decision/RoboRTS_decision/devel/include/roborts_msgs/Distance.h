// Generated by gencpp from file roborts_msgs/Distance.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_DISTANCE_H
#define ROBORTS_MSGS_MESSAGE_DISTANCE_H


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
struct Distance_
{
  typedef Distance_<ContainerAllocator> Type;

  Distance_()
    : distance(0.0)  {
    }
  Distance_(const ContainerAllocator& _alloc)
    : distance(0.0)  {
  (void)_alloc;
    }



   typedef double _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::roborts_msgs::Distance_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::Distance_<ContainerAllocator> const> ConstPtr;

}; // struct Distance_

typedef ::roborts_msgs::Distance_<std::allocator<void> > Distance;

typedef boost::shared_ptr< ::roborts_msgs::Distance > DistancePtr;
typedef boost::shared_ptr< ::roborts_msgs::Distance const> DistanceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::Distance_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::Distance_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::roborts_msgs::Distance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::Distance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::Distance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::Distance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::Distance_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::Distance_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::Distance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "acff7fda0c683c872875f5c4b069f124";
  }

  static const char* value(const ::roborts_msgs::Distance_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xacff7fda0c683c87ULL;
  static const uint64_t static_value2 = 0x2875f5c4b069f124ULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::Distance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/Distance";
  }

  static const char* value(const ::roborts_msgs::Distance_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::Distance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 distance\n\
";
  }

  static const char* value(const ::roborts_msgs::Distance_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::Distance_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Distance_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::Distance_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::Distance_<ContainerAllocator>& v)
  {
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_DISTANCE_H
