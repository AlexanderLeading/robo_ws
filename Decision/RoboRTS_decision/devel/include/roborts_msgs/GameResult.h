// Generated by gencpp from file roborts_msgs/GameResult.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_GAMERESULT_H
#define ROBORTS_MSGS_MESSAGE_GAMERESULT_H


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
struct GameResult_
{
  typedef GameResult_<ContainerAllocator> Type;

  GameResult_()
    : result(0)  {
    }
  GameResult_(const ContainerAllocator& _alloc)
    : result(0)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;



  enum {
    DRAW = 0u,
    RED_WIN = 1u,
    BLUE_WIN = 2u,
  };


  typedef boost::shared_ptr< ::roborts_msgs::GameResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::GameResult_<ContainerAllocator> const> ConstPtr;

}; // struct GameResult_

typedef ::roborts_msgs::GameResult_<std::allocator<void> > GameResult;

typedef boost::shared_ptr< ::roborts_msgs::GameResult > GameResultPtr;
typedef boost::shared_ptr< ::roborts_msgs::GameResult const> GameResultConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::GameResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::GameResult_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::roborts_msgs::GameResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::GameResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GameResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GameResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GameResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GameResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::GameResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4d09240fdf4519a3920c8056c8354c3d";
  }

  static const char* value(const ::roborts_msgs::GameResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4d09240fdf4519a3ULL;
  static const uint64_t static_value2 = 0x920c8056c8354c3dULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::GameResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/GameResult";
  }

  static const char* value(const ::roborts_msgs::GameResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::GameResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#game result\n\
uint8  DRAW=0\n\
uint8  RED_WIN=1\n\
uint8  BLUE_WIN=2\n\
uint8  result\n\
";
  }

  static const char* value(const ::roborts_msgs::GameResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::GameResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GameResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::GameResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::GameResult_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_GAMERESULT_H
