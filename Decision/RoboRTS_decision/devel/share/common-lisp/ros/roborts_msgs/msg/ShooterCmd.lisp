; Auto-generated. Do not edit!


(cl:in-package roborts_msgs-msg)


;//! \htmlinclude ShooterCmd.msg.html

(cl:defclass <ShooterCmd> (roslisp-msg-protocol:ros-message)
  ((is_shoot
    :reader is_shoot
    :initarg :is_shoot
    :type cl:boolean
    :initform cl:nil)
   (shoot_cmd
    :reader shoot_cmd
    :initarg :shoot_cmd
    :type cl:fixnum
    :initform 0)
   (c_shoot_cmd
    :reader c_shoot_cmd
    :initarg :c_shoot_cmd
    :type cl:fixnum
    :initform 0)
   (fric_wheel_run
    :reader fric_wheel_run
    :initarg :fric_wheel_run
    :type cl:fixnum
    :initform 0)
   (shoot_freq
    :reader shoot_freq
    :initarg :shoot_freq
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ShooterCmd (<ShooterCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ShooterCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ShooterCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roborts_msgs-msg:<ShooterCmd> is deprecated: use roborts_msgs-msg:ShooterCmd instead.")))

(cl:ensure-generic-function 'is_shoot-val :lambda-list '(m))
(cl:defmethod is_shoot-val ((m <ShooterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:is_shoot-val is deprecated.  Use roborts_msgs-msg:is_shoot instead.")
  (is_shoot m))

(cl:ensure-generic-function 'shoot_cmd-val :lambda-list '(m))
(cl:defmethod shoot_cmd-val ((m <ShooterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:shoot_cmd-val is deprecated.  Use roborts_msgs-msg:shoot_cmd instead.")
  (shoot_cmd m))

(cl:ensure-generic-function 'c_shoot_cmd-val :lambda-list '(m))
(cl:defmethod c_shoot_cmd-val ((m <ShooterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:c_shoot_cmd-val is deprecated.  Use roborts_msgs-msg:c_shoot_cmd instead.")
  (c_shoot_cmd m))

(cl:ensure-generic-function 'fric_wheel_run-val :lambda-list '(m))
(cl:defmethod fric_wheel_run-val ((m <ShooterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:fric_wheel_run-val is deprecated.  Use roborts_msgs-msg:fric_wheel_run instead.")
  (fric_wheel_run m))

(cl:ensure-generic-function 'shoot_freq-val :lambda-list '(m))
(cl:defmethod shoot_freq-val ((m <ShooterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:shoot_freq-val is deprecated.  Use roborts_msgs-msg:shoot_freq instead.")
  (shoot_freq m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ShooterCmd>) ostream)
  "Serializes a message object of type '<ShooterCmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_shoot) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoot_cmd)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'c_shoot_cmd)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fric_wheel_run)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoot_freq)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'shoot_freq)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ShooterCmd>) istream)
  "Deserializes a message object of type '<ShooterCmd>"
    (cl:setf (cl:slot-value msg 'is_shoot) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoot_cmd)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'c_shoot_cmd)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fric_wheel_run)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoot_freq)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'shoot_freq)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ShooterCmd>)))
  "Returns string type for a message object of type '<ShooterCmd>"
  "roborts_msgs/ShooterCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ShooterCmd)))
  "Returns string type for a message object of type 'ShooterCmd"
  "roborts_msgs/ShooterCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ShooterCmd>)))
  "Returns md5sum for a message object of type '<ShooterCmd>"
  "1ce874438e33b75dd468a5f9109af925")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ShooterCmd)))
  "Returns md5sum for a message object of type 'ShooterCmd"
  "1ce874438e33b75dd468a5f9109af925")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ShooterCmd>)))
  "Returns full string definition for message of type '<ShooterCmd>"
  (cl:format cl:nil "bool is_shoot~%uint8 shoot_cmd~%uint8 c_shoot_cmd~%uint8 fric_wheel_run~%uint16 shoot_freq~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ShooterCmd)))
  "Returns full string definition for message of type 'ShooterCmd"
  (cl:format cl:nil "bool is_shoot~%uint8 shoot_cmd~%uint8 c_shoot_cmd~%uint8 fric_wheel_run~%uint16 shoot_freq~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ShooterCmd>))
  (cl:+ 0
     1
     1
     1
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ShooterCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'ShooterCmd
    (cl:cons ':is_shoot (is_shoot msg))
    (cl:cons ':shoot_cmd (shoot_cmd msg))
    (cl:cons ':c_shoot_cmd (c_shoot_cmd msg))
    (cl:cons ':fric_wheel_run (fric_wheel_run msg))
    (cl:cons ':shoot_freq (shoot_freq msg))
))
