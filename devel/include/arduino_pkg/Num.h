// Generated by gencpp from file arduino_pkg/Num.msg
// DO NOT EDIT!


#ifndef ARDUINO_PKG_MESSAGE_NUM_H
#define ARDUINO_PKG_MESSAGE_NUM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace arduino_pkg
{
template <class ContainerAllocator>
struct Num_
{
  typedef Num_<ContainerAllocator> Type;

  Num_()
    : Control(0)
    , Duration(0)  {
    }
  Num_(const ContainerAllocator& _alloc)
    : Control(0)
    , Duration(0)  {
  (void)_alloc;
    }



   typedef int16_t _Control_type;
  _Control_type Control;

   typedef uint16_t _Duration_type;
  _Duration_type Duration;





  typedef boost::shared_ptr< ::arduino_pkg::Num_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arduino_pkg::Num_<ContainerAllocator> const> ConstPtr;

}; // struct Num_

typedef ::arduino_pkg::Num_<std::allocator<void> > Num;

typedef boost::shared_ptr< ::arduino_pkg::Num > NumPtr;
typedef boost::shared_ptr< ::arduino_pkg::Num const> NumConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arduino_pkg::Num_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arduino_pkg::Num_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::arduino_pkg::Num_<ContainerAllocator1> & lhs, const ::arduino_pkg::Num_<ContainerAllocator2> & rhs)
{
  return lhs.Control == rhs.Control &&
    lhs.Duration == rhs.Duration;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::arduino_pkg::Num_<ContainerAllocator1> & lhs, const ::arduino_pkg::Num_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace arduino_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::arduino_pkg::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arduino_pkg::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arduino_pkg::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arduino_pkg::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arduino_pkg::Num_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arduino_pkg::Num_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arduino_pkg::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1a749a2ffb665f31b6ffb7a5a9db9bad";
  }

  static const char* value(const ::arduino_pkg::Num_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1a749a2ffb665f31ULL;
  static const uint64_t static_value2 = 0xb6ffb7a5a9db9badULL;
};

template<class ContainerAllocator>
struct DataType< ::arduino_pkg::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arduino_pkg/Num";
  }

  static const char* value(const ::arduino_pkg::Num_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arduino_pkg::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 Control\n"
"uint16 Duration \n"
;
  }

  static const char* value(const ::arduino_pkg::Num_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arduino_pkg::Num_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Control);
      stream.next(m.Duration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Num_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arduino_pkg::Num_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arduino_pkg::Num_<ContainerAllocator>& v)
  {
    s << indent << "Control: ";
    Printer<int16_t>::stream(s, indent + "  ", v.Control);
    s << indent << "Duration: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.Duration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDUINO_PKG_MESSAGE_NUM_H
