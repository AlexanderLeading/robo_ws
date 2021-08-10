;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::ArmorPos)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'ArmorPos (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::ARMORPOS")
  (make-package "ROBORTS_MSGS::ARMORPOS"))

(in-package "ROS")
;;//! \htmlinclude ArmorPos.msg.html


(defclass roborts_msgs::ArmorPos
  :super ros::object
  :slots (_is_valid _x _y _z _distance _pose_in_gimbal _vertex _motion_vec ))

(defmethod roborts_msgs::ArmorPos
  (:init
   (&key
    ((:is_valid __is_valid) nil)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:distance __distance) 0.0)
    ((:pose_in_gimbal __pose_in_gimbal) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:vertex __vertex) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:motion_vec __motion_vec) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _is_valid __is_valid)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _distance (float __distance))
   (setq _pose_in_gimbal __pose_in_gimbal)
   (setq _vertex __vertex)
   (setq _motion_vec __motion_vec)
   self)
  (:is_valid
   (&optional __is_valid)
   (if __is_valid (setq _is_valid __is_valid)) _is_valid)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:pose_in_gimbal
   (&optional __pose_in_gimbal)
   (if __pose_in_gimbal (setq _pose_in_gimbal __pose_in_gimbal)) _pose_in_gimbal)
  (:vertex
   (&optional __vertex)
   (if __vertex (setq _vertex __vertex)) _vertex)
  (:motion_vec
   (&optional __motion_vec)
   (if __motion_vec (setq _motion_vec __motion_vec)) _motion_vec)
  (:serialization-length
   ()
   (+
    ;; bool _is_valid
    1
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; float64 _distance
    8
    ;; float64[] _pose_in_gimbal
    (* 8    (length _pose_in_gimbal)) 4
    ;; float64[] _vertex
    (* 8    (length _vertex)) 4
    ;; float64[] _motion_vec
    (* 8    (length _motion_vec)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_valid
       (if _is_valid (write-byte -1 s) (write-byte 0 s))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64[] _pose_in_gimbal
     (write-long (length _pose_in_gimbal) s)
     (dotimes (i (length _pose_in_gimbal))
       (sys::poke (elt _pose_in_gimbal i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _vertex
     (write-long (length _vertex) s)
     (dotimes (i (length _vertex))
       (sys::poke (elt _vertex i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _motion_vec
     (write-long (length _motion_vec) s)
     (dotimes (i (length _motion_vec))
       (sys::poke (elt _motion_vec i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_valid
     (setq _is_valid (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64[] _pose_in_gimbal
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pose_in_gimbal (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pose_in_gimbal i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _vertex
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vertex (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _vertex i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _motion_vec
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motion_vec (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _motion_vec i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::ArmorPos :md5sum-) "7c1653860dd6778fef70d70be834958c")
(setf (get roborts_msgs::ArmorPos :datatype-) "roborts_msgs/ArmorPos")
(setf (get roborts_msgs::ArmorPos :definition-)
      "bool is_valid
float64 x
float64 y
float64 z
float64 distance
float64[] pose_in_gimbal
float64[] vertex
float64[] motion_vec

")



(provide :roborts_msgs/ArmorPos "7c1653860dd6778fef70d70be834958c")


