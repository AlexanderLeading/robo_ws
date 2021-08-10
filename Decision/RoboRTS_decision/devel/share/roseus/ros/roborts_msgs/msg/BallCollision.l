;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::BallCollision)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'BallCollision (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::BALLCOLLISION")
  (make-package "ROBORTS_MSGS::BALLCOLLISION"))

(in-package "ROS")
;;//! \htmlinclude BallCollision.msg.html


(defclass roborts_msgs::BallCollision
  :super ros::object
  :slots (_collision_time _collision_1 _collision_2 _x _y _z ))

(defmethod roborts_msgs::BallCollision
  (:init
   (&key
    ((:collision_time __collision_time) 0.0)
    ((:collision_1 __collision_1) "")
    ((:collision_2 __collision_2) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _collision_time (float __collision_time))
   (setq _collision_1 (string __collision_1))
   (setq _collision_2 (string __collision_2))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   self)
  (:collision_time
   (&optional __collision_time)
   (if __collision_time (setq _collision_time __collision_time)) _collision_time)
  (:collision_1
   (&optional __collision_1)
   (if __collision_1 (setq _collision_1 __collision_1)) _collision_1)
  (:collision_2
   (&optional __collision_2)
   (if __collision_2 (setq _collision_2 __collision_2)) _collision_2)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; float64 _collision_time
    8
    ;; string _collision_1
    4 (length _collision_1)
    ;; string _collision_2
    4 (length _collision_2)
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _collision_time
       (sys::poke _collision_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; string _collision_1
       (write-long (length _collision_1) s) (princ _collision_1 s)
     ;; string _collision_2
       (write-long (length _collision_2) s) (princ _collision_2 s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _collision_time
     (setq _collision_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; string _collision_1
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _collision_1 (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _collision_2
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _collision_2 (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get roborts_msgs::BallCollision :md5sum-) "b3495fecab5c6286c1b0aa9239dbe76b")
(setf (get roborts_msgs::BallCollision :datatype-) "roborts_msgs/BallCollision")
(setf (get roborts_msgs::BallCollision :definition-)
      "float64 collision_time
string collision_1
string collision_2
float32 x
float32 y
float32 z


")



(provide :roborts_msgs/BallCollision "b3495fecab5c6286c1b0aa9239dbe76b")


