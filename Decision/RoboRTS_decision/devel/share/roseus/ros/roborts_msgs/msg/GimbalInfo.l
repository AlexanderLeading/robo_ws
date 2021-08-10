;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::GimbalInfo)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'GimbalInfo (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::GIMBALINFO")
  (make-package "ROBORTS_MSGS::GIMBALINFO"))

(in-package "ROS")
;;//! \htmlinclude GimbalInfo.msg.html


(defclass roborts_msgs::GimbalInfo
  :super ros::object
  :slots (_ecd_yaw _ecd_pitch _gyro_yaw _gyro_pitch _yaw_rate _pitch_rate ))

(defmethod roborts_msgs::GimbalInfo
  (:init
   (&key
    ((:ecd_yaw __ecd_yaw) 0.0)
    ((:ecd_pitch __ecd_pitch) 0.0)
    ((:gyro_yaw __gyro_yaw) 0.0)
    ((:gyro_pitch __gyro_pitch) 0.0)
    ((:yaw_rate __yaw_rate) 0.0)
    ((:pitch_rate __pitch_rate) 0.0)
    )
   (send-super :init)
   (setq _ecd_yaw (float __ecd_yaw))
   (setq _ecd_pitch (float __ecd_pitch))
   (setq _gyro_yaw (float __gyro_yaw))
   (setq _gyro_pitch (float __gyro_pitch))
   (setq _yaw_rate (float __yaw_rate))
   (setq _pitch_rate (float __pitch_rate))
   self)
  (:ecd_yaw
   (&optional __ecd_yaw)
   (if __ecd_yaw (setq _ecd_yaw __ecd_yaw)) _ecd_yaw)
  (:ecd_pitch
   (&optional __ecd_pitch)
   (if __ecd_pitch (setq _ecd_pitch __ecd_pitch)) _ecd_pitch)
  (:gyro_yaw
   (&optional __gyro_yaw)
   (if __gyro_yaw (setq _gyro_yaw __gyro_yaw)) _gyro_yaw)
  (:gyro_pitch
   (&optional __gyro_pitch)
   (if __gyro_pitch (setq _gyro_pitch __gyro_pitch)) _gyro_pitch)
  (:yaw_rate
   (&optional __yaw_rate)
   (if __yaw_rate (setq _yaw_rate __yaw_rate)) _yaw_rate)
  (:pitch_rate
   (&optional __pitch_rate)
   (if __pitch_rate (setq _pitch_rate __pitch_rate)) _pitch_rate)
  (:serialization-length
   ()
   (+
    ;; float64 _ecd_yaw
    8
    ;; float64 _ecd_pitch
    8
    ;; float64 _gyro_yaw
    8
    ;; float64 _gyro_pitch
    8
    ;; float64 _yaw_rate
    8
    ;; float64 _pitch_rate
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _ecd_yaw
       (sys::poke _ecd_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ecd_pitch
       (sys::poke _ecd_pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _gyro_yaw
       (sys::poke _gyro_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _gyro_pitch
       (sys::poke _gyro_pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw_rate
       (sys::poke _yaw_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch_rate
       (sys::poke _pitch_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _ecd_yaw
     (setq _ecd_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ecd_pitch
     (setq _ecd_pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _gyro_yaw
     (setq _gyro_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _gyro_pitch
     (setq _gyro_pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw_rate
     (setq _yaw_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch_rate
     (setq _pitch_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get roborts_msgs::GimbalInfo :md5sum-) "de1cd11d7e2cb10eb47cdbc531727f86")
(setf (get roborts_msgs::GimbalInfo :datatype-) "roborts_msgs/GimbalInfo")
(setf (get roborts_msgs::GimbalInfo :definition-)
      "float64 ecd_yaw
float64 ecd_pitch
float64 gyro_yaw
float64 gyro_pitch
float64 yaw_rate
float64 pitch_rate

")



(provide :roborts_msgs/GimbalInfo "de1cd11d7e2cb10eb47cdbc531727f86")


