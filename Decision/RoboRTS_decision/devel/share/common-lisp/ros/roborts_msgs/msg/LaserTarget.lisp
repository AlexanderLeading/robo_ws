; Auto-generated. Do not edit!


(cl:in-package roborts_msgs-msg)


;//! \htmlinclude LaserTarget.msg.html

(cl:defclass <LaserTarget> (roslisp-msg-protocol:ros-message)
  ((num_target
    :reader num_target
    :initarg :num_target
    :type cl:fixnum
    :initform 0)
   (num_points
    :reader num_points
    :initarg :num_points
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (pose
    :reader pose
    :initarg :pose
    :type (cl:vector roborts_msgs-msg:FVector)
   :initform (cl:make-array 0 :element-type 'roborts_msgs-msg:FVector :initial-element (cl:make-instance 'roborts_msgs-msg:FVector)))
   (confidence
    :reader confidence
    :initarg :confidence
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass LaserTarget (<LaserTarget>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaserTarget>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaserTarget)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roborts_msgs-msg:<LaserTarget> is deprecated: use roborts_msgs-msg:LaserTarget instead.")))

(cl:ensure-generic-function 'num_target-val :lambda-list '(m))
(cl:defmethod num_target-val ((m <LaserTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:num_target-val is deprecated.  Use roborts_msgs-msg:num_target instead.")
  (num_target m))

(cl:ensure-generic-function 'num_points-val :lambda-list '(m))
(cl:defmethod num_points-val ((m <LaserTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:num_points-val is deprecated.  Use roborts_msgs-msg:num_points instead.")
  (num_points m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <LaserTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:pose-val is deprecated.  Use roborts_msgs-msg:pose instead.")
  (pose m))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <LaserTarget>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roborts_msgs-msg:confidence-val is deprecated.  Use roborts_msgs-msg:confidence instead.")
  (confidence m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaserTarget>) ostream)
  "Serializes a message object of type '<LaserTarget>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_target)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'num_points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'num_points))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pose))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'pose))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'confidence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'confidence))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaserTarget>) istream)
  "Deserializes a message object of type '<LaserTarget>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num_target)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'num_points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'num_points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pose) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pose)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'roborts_msgs-msg:FVector))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'confidence) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'confidence)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaserTarget>)))
  "Returns string type for a message object of type '<LaserTarget>"
  "roborts_msgs/LaserTarget")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaserTarget)))
  "Returns string type for a message object of type 'LaserTarget"
  "roborts_msgs/LaserTarget")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaserTarget>)))
  "Returns md5sum for a message object of type '<LaserTarget>"
  "b7a891f119d989835596adf70e8ef67b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaserTarget)))
  "Returns md5sum for a message object of type 'LaserTarget"
  "b7a891f119d989835596adf70e8ef67b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaserTarget>)))
  "Returns full string definition for message of type '<LaserTarget>"
  (cl:format cl:nil "uint8 num_target~%uint8[] num_points~%FVector[] pose~%float32[] confidence~%~%================================================================================~%MSG: roborts_msgs/FVector~%float32[] vector~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaserTarget)))
  "Returns full string definition for message of type 'LaserTarget"
  (cl:format cl:nil "uint8 num_target~%uint8[] num_points~%FVector[] pose~%float32[] confidence~%~%================================================================================~%MSG: roborts_msgs/FVector~%float32[] vector~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaserTarget>))
  (cl:+ 0
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'num_points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pose) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'confidence) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaserTarget>))
  "Converts a ROS message object to a list"
  (cl:list 'LaserTarget
    (cl:cons ':num_target (num_target msg))
    (cl:cons ':num_points (num_points msg))
    (cl:cons ':pose (pose msg))
    (cl:cons ':confidence (confidence msg))
))
