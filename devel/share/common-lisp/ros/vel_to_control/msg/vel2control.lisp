; Auto-generated. Do not edit!


(cl:in-package vel_to_control-msg)


;//! \htmlinclude vel2control.msg.html

(cl:defclass <vel2control> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass vel2control (<vel2control>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <vel2control>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'vel2control)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name vel_to_control-msg:<vel2control> is deprecated: use vel_to_control-msg:vel2control instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <vel2control>) ostream)
  "Serializes a message object of type '<vel2control>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <vel2control>) istream)
  "Deserializes a message object of type '<vel2control>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<vel2control>)))
  "Returns string type for a message object of type '<vel2control>"
  "vel_to_control/vel2control")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'vel2control)))
  "Returns string type for a message object of type 'vel2control"
  "vel_to_control/vel2control")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<vel2control>)))
  "Returns md5sum for a message object of type '<vel2control>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'vel2control)))
  "Returns md5sum for a message object of type 'vel2control"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<vel2control>)))
  "Returns full string definition for message of type '<vel2control>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'vel2control)))
  "Returns full string definition for message of type 'vel2control"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <vel2control>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <vel2control>))
  "Converts a ROS message object to a list"
  (cl:list 'vel2control
))
