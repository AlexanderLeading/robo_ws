// Generated by gencpp from file roborts_msgs/TwistAccel.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_TWISTACCEL_H
#define ROBORTS_MSGS_MESSAGE_TWISTACCEL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Accel.h>

namespace roborts_msgs
{
template <class ContainerAllocator>
struct TwistAccel_
{
  typedef TwistAccel_<ContainerAllocator> Type;

  TwistAccel_()
    : twist()
    , accel()  {
    }
  TwistAccel_(const ContainerAllocator& _alloc)
    : twist(_alloc)
    , accel(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _twist_type;
  _twist_type twist;

   typedef  ::geometry_msgs::Accel_<ContainerAllocator>  _accel_type;
  _accel_type accel;





  typedef boost::shared_ptr< ::roborts_msgs::TwistAccel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::TwistAccel_<ContainerAllocator> const> ConstPtr;

}; // struct TwistAccel_

typedef ::roborts_msgs::TwistAccel_<std::allocator<void> > TwistAccel;

typedef boost::shared_ptr< ::roborts_msgs::TwistAccel > TwistAccelPtr;
typedef boost::shared_ptr< ::roborts_msgs::TwistAccel const> TwistAccelConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::TwistAccel_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::TwistAccel_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::TwistAccel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::TwistAccel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::TwistAccel_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "644e3af95741e8ff8b733f2fd1e014d8";
  }

  static const char* value(const ::roborts_msgs::TwistAccel_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x644e3af95741e8ffULL;
  static const uint64_t static_value2 = 0x8b733f2fd1e014d8ULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/TwistAccel";
  }

  static const char* value(const ::roborts_msgs::TwistAccel_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Twist twist\n\
geometry_msgs/Accel accel\n\
================================================================================\n\
MSG: geometry_msgs/Twist\n\
# This expresses velocity in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: geometry_msgs/Accel\n\
# This expresses acceleration in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
";
  }

  static const char* value(const ::roborts_msgs::TwistAccel_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.twist);
      stream.next(m.accel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TwistAccel_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::TwistAccel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::TwistAccel_<ContainerAllocator>& v)
  {
    s << indent << "twist: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.twist);
    s << indent << "accel: ";
    s << std::endl;
    Printer< ::geometry_msgs::Accel_<ContainerAllocator> >::stream(s, indent + "  ", v.accel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_TWISTACCEL_H
