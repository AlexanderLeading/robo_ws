; Auto-generated. Do not edit!


(cl:in-package roborts_msgs-msg)


;//! \htmlinclude DodgeMode.msg.html

(cl:defclass <DodgeMode> (roslisp-msg-protocol:ros-message)
  ((is_dodge
    :reader is_dodge
    :initarg :is_dodge
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass DodgeMode (<DodgeMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DodgeMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DodgeMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roborts_msgs-msg:<DodgeMode> is deprecated: use roborts_msgs-msg:DodgeMode instead.")))

(cl:ensure-generic-function 'is_dodge-val :lambda-list '(m))
(cl:defmethod is_dodge-val ((m <DodgeMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:is_dodge-val is deprecated.  Use roborts_msgs-msg:is_dodge instead.")
  (is_dodge m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DodgeMode>) ostream)
  "Serializes a message object of type '<DodgeMode>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_dodge) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DodgeMode>) istream)
  "Deserializes a message object of type '<DodgeMode>"
    (cl:setf (cl:slot-value msg 'is_dodge) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DodgeMode>)))
  "Returns string type for a message object of type '<DodgeMode>"
  "roborts_msgs/DodgeMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DodgeMode)))
  "Returns string type for a message object of type 'DodgeMode"
  "roborts_msgs/DodgeMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DodgeMode>)))
  "Returns md5sum for a message object of type '<DodgeMode>"
  "e86a3c0123103abb455aca69f2a22f53")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DodgeMode)))
  "Returns md5sum for a message object of type 'DodgeMode"
  "e86a3c0123103abb455aca69f2a22f53")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DodgeMode>)))
  "Returns full string definition for message of type '<DodgeMode>"
  (cl:format cl:nil "bool is_dodge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DodgeMode)))
  "Returns full string definition for message of type 'DodgeMode"
  (cl:format cl:nil "bool is_dodge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DodgeMode>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DodgeMode>))
  "Converts a ROS message object to a list"
  (cl:list 'DodgeMode
    (cl:cons ':is_dodge (is_dodge msg))
))
