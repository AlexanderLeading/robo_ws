; Auto-generated. Do not edit!


(cl:in-package roborts_msgs-msg)


;//! \htmlinclude FusionTarget.msg.html

(cl:defclass <FusionTarget> (roslisp-msg-protocol:ros-message)
  ((num_id_target
    :reader num_id_target
    :initarg :num_id_target
    :type cl:fixnum
    :initform 0)
   (num_no_id_target
    :reader num_no_id_target
    :initarg :num_no_id_target
    :type cl:fixnum
    :initform 0)
   (id_targets
    :reader id_targets
    :initarg :id_targets
    :type (cl:vector roborts_msgs-msg:Target)
   :initform (cl:make-array 0 :element-type 'roborts_msgs-msg:Target :initial-element (cl:make-instance 'roborts_msgs-msg:Target)))
   (no_id_targets
    :reader no_id_targets
    :initarg :no_id_targets
    :type (cl:vector roborts_msgs-msg:Target)
   :initform (cl:make-array 0 :element-type 'roborts_msgs-msg:Target :initial-element (cl:make-instance 'roborts_msgs-msg:Target))))
)

(cl:defclass FusionTarget (<FusionTarget>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FusionTarget>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FusionTarget)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roborts_msgs-msg:<FusionTarget> is deprecated: use roborts_msgs-msg:FusionTarget instead.")))

(cl:ensure-generic-function 'num_id_target-val :lambda-list '(m))
(cl:defmethod num_id_target-val ((m <FusionTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:num_id_target-val is deprecated.  Use roborts_msgs-msg:num_id_target instead.")
  (num_id_target m))

(cl:ensure-generic-function 'num_no_id_target-val :lambda-list '(m))
(cl:defmethod num_no_id_target-val ((m <FusionTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:num_no_id_target-val is deprecated.  Use roborts_msgs-msg:num_no_id_target instead.")
  (num_no_id_target m))

(cl:ensure-generic-function 'id_targets-val :lambda-list '(m))
(cl:defmethod id_targets-val ((m <FusionTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:id_targets-val is deprecated.  Use roborts_msgs-msg:id_targets instead.")
  (id_targets m))

(cl:ensure-generic-function 'no_id_targets-val :lambda-list '(m))
(cl:defmethod no_id_targets-val ((m <FusionTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:no_id_targets-val is deprecated.  Use roborts_msgs-msg:no_id_targets instead.")
  (no_id_targets m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FusionTarget>) ostream)
  "Serializes a message object of type '<FusionTarget>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_id_target)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_no_id_target)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'id_targets))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'id_targets))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'no_id_targets))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'no_id_targets))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FusionTarget>) istream)
  "Deserializes a message object of type '<FusionTarget>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_id_target)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_no_id_target)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'id_targets) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'id_targets)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'roborts_msgs-msg:Target))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'no_id_targets) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'no_id_targets)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'roborts_msgs-msg:Target))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FusionTarget>)))
  "Returns string type for a message object of type '<FusionTarget>"
  "roborts_msgs/FusionTarget")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FusionTarget)))
  "Returns string type for a message object of type 'FusionTarget"
  "roborts_msgs/FusionTarget")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FusionTarget>)))
  "Returns md5sum for a message object of type '<FusionTarget>"
  "4b446fdc6c26040d3eceffafbf5e0975")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FusionTarget)))
  "Returns md5sum for a message object of type 'FusionTarget"
  "4b446fdc6c26040d3eceffafbf5e0975")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FusionTarget>)))
  "Returns full string definition for message of type '<FusionTarget>"
  (cl:format cl:nil "uint8 num_id_target~%uint8 num_no_id_target~%Target[] id_targets~%Target[] no_id_targets~%~%================================================================================~%MSG: roborts_msgs/Target~%uint8 id~%uint8 state~%uint8 sensor~%float32 x~%float32 y~%float32 confidence~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FusionTarget)))
  "Returns full string definition for message of type 'FusionTarget"
  (cl:format cl:nil "uint8 num_id_target~%uint8 num_no_id_target~%Target[] id_targets~%Target[] no_id_targets~%~%================================================================================~%MSG: roborts_msgs/Target~%uint8 id~%uint8 state~%uint8 sensor~%float32 x~%float32 y~%float32 confidence~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FusionTarget>))
  (cl:+ 0
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'id_targets) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'no_id_targets) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FusionTarget>))
  "Converts a ROS message object to a list"
  (cl:list 'FusionTarget
    (cl:cons ':num_id_target (num_id_target msg))
    (cl:cons ':num_no_id_target (num_no_id_target msg))
    (cl:cons ':id_targets (id_targets msg))
    (cl:cons ':no_id_targets (no_id_targets msg))
))
