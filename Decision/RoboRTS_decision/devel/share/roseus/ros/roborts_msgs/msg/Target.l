;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::Target)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'Target (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::TARGET")
  (make-package "ROBORTS_MSGS::TARGET"))

(in-package "ROS")
;;//! \htmlinclude Target.msg.html


(defclass roborts_msgs::Target
  :super ros::object
  :slots (_id _state _sensor _x _y _confidence ))

(defmethod roborts_msgs::Target
  (:init
   (&key
    ((:id __id) 0)
    ((:state __state) 0)
    ((:sensor __sensor) 0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:confidence __confidence) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _state (round __state))
   (setq _sensor (round __sensor))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _confidence (float __confidence))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:sensor
   (&optional __sensor)
   (if __sensor (setq _sensor __sensor)) _sensor)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; uint8 _state
    1
    ;; uint8 _sensor
    1
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _confidence
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; uint8 _state
       (write-byte _state s)
     ;; uint8 _sensor
       (write-byte _sensor s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sensor
     (setq _sensor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get roborts_msgs::Target :md5sum-) "efa7f772ad165e48d9a6bd49c109d98a")
(setf (get roborts_msgs::Target :datatype-) "roborts_msgs/Target")
(setf (get roborts_msgs::Target :definition-)
      "uint8 id
uint8 state
uint8 sensor
float32 x
float32 y
float32 confidence

")



(provide :roborts_msgs/Target "efa7f772ad165e48d9a6bd49c109d98a")


