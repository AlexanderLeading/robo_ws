;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::GimbalPID)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'GimbalPID (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::GIMBALPID")
  (make-package "ROBORTS_MSGS::GIMBALPID"))

(in-package "ROS")
;;//! \htmlinclude GimbalPID.msg.html


(defclass roborts_msgs::GimbalPID
  :super ros::object
  :slots (_is_valid _yaw_mode _pitch_mode _x _y _z _undetected_count_ ))

(defmethod roborts_msgs::GimbalPID
  (:init
   (&key
    ((:is_valid __is_valid) nil)
    ((:yaw_mode __yaw_mode) nil)
    ((:pitch_mode __pitch_mode) nil)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:undetected_count_ __undetected_count_) 0)
    )
   (send-super :init)
   (setq _is_valid __is_valid)
   (setq _yaw_mode __yaw_mode)
   (setq _pitch_mode __pitch_mode)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _undetected_count_ (round __undetected_count_))
   self)
  (:is_valid
   (&optional __is_valid)
   (if __is_valid (setq _is_valid __is_valid)) _is_valid)
  (:yaw_mode
   (&optional __yaw_mode)
   (if __yaw_mode (setq _yaw_mode __yaw_mode)) _yaw_mode)
  (:pitch_mode
   (&optional __pitch_mode)
   (if __pitch_mode (setq _pitch_mode __pitch_mode)) _pitch_mode)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:undetected_count_
   (&optional __undetected_count_)
   (if __undetected_count_ (setq _undetected_count_ __undetected_count_)) _undetected_count_)
  (:serialization-length
   ()
   (+
    ;; bool _is_valid
    1
    ;; bool _yaw_mode
    1
    ;; bool _pitch_mode
    1
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; int32 _undetected_count_
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_valid
       (if _is_valid (write-byte -1 s) (write-byte 0 s))
     ;; bool _yaw_mode
       (if _yaw_mode (write-byte -1 s) (write-byte 0 s))
     ;; bool _pitch_mode
       (if _pitch_mode (write-byte -1 s) (write-byte 0 s))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _undetected_count_
       (write-long _undetected_count_ s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_valid
     (setq _is_valid (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _yaw_mode
     (setq _yaw_mode (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _pitch_mode
     (setq _pitch_mode (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _undetected_count_
     (setq _undetected_count_ (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get roborts_msgs::GimbalPID :md5sum-) "47363277c60e8bf4c4fc3528d560ba62")
(setf (get roborts_msgs::GimbalPID :datatype-) "roborts_msgs/GimbalPID")
(setf (get roborts_msgs::GimbalPID :definition-)
      "#detection to gimbal control
bool is_valid
bool yaw_mode
bool pitch_mode
float64 x
float64 y
float64 z
int32 undetected_count_

")



(provide :roborts_msgs/GimbalPID "47363277c60e8bf4c4fc3528d560ba62")


