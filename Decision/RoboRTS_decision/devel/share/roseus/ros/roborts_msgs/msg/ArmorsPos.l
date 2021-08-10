;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::ArmorsPos)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'ArmorsPos (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::ARMORSPOS")
  (make-package "ROBORTS_MSGS::ARMORSPOS"))

(in-package "ROS")
;;//! \htmlinclude ArmorsPos.msg.html


(defclass roborts_msgs::ArmorsPos
  :super ros::object
  :slots (_num_armor _armor_0 _armor_1 _id _state _robot_A _robot_B _pose_A _pose_B ))

(defmethod roborts_msgs::ArmorsPos
  (:init
   (&key
    ((:num_armor __num_armor) 0)
    ((:armor_0 __armor_0) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:armor_1 __armor_1) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:id __id) (make-array 0 :initial-element 0 :element-type :char))
    ((:state __state) (make-array 0 :initial-element 0 :element-type :char))
    ((:robot_A __robot_A) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:robot_B __robot_B) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pose_A __pose_A) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pose_B __pose_B) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _num_armor (round __num_armor))
   (setq _armor_0 __armor_0)
   (setq _armor_1 __armor_1)
   (setq _id __id)
   (setq _state __state)
   (setq _robot_A __robot_A)
   (setq _robot_B __robot_B)
   (setq _pose_A __pose_A)
   (setq _pose_B __pose_B)
   self)
  (:num_armor
   (&optional __num_armor)
   (if __num_armor (setq _num_armor __num_armor)) _num_armor)
  (:armor_0
   (&optional __armor_0)
   (if __armor_0 (setq _armor_0 __armor_0)) _armor_0)
  (:armor_1
   (&optional __armor_1)
   (if __armor_1 (setq _armor_1 __armor_1)) _armor_1)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:robot_A
   (&optional __robot_A)
   (if __robot_A (setq _robot_A __robot_A)) _robot_A)
  (:robot_B
   (&optional __robot_B)
   (if __robot_B (setq _robot_B __robot_B)) _robot_B)
  (:pose_A
   (&optional __pose_A)
   (if __pose_A (setq _pose_A __pose_A)) _pose_A)
  (:pose_B
   (&optional __pose_B)
   (if __pose_B (setq _pose_B __pose_B)) _pose_B)
  (:serialization-length
   ()
   (+
    ;; uint8 _num_armor
    1
    ;; float32[] _armor_0
    (* 4    (length _armor_0)) 4
    ;; float32[] _armor_1
    (* 4    (length _armor_1)) 4
    ;; uint8[] _id
    (* 1    (length _id)) 4
    ;; uint8[] _state
    (* 1    (length _state)) 4
    ;; float32[] _robot_A
    (* 4    (length _robot_A)) 4
    ;; float32[] _robot_B
    (* 4    (length _robot_B)) 4
    ;; float32[] _pose_A
    (* 4    (length _pose_A)) 4
    ;; float32[] _pose_B
    (* 4    (length _pose_B)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _num_armor
       (write-byte _num_armor s)
     ;; float32[] _armor_0
     (write-long (length _armor_0) s)
     (dotimes (i (length _armor_0))
       (sys::poke (elt _armor_0 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _armor_1
     (write-long (length _armor_1) s)
     (dotimes (i (length _armor_1))
       (sys::poke (elt _armor_1 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; uint8[] _id
     (write-long (length _id) s)
     (princ _id s)
     ;; uint8[] _state
     (write-long (length _state) s)
     (princ _state s)
     ;; float32[] _robot_A
     (write-long (length _robot_A) s)
     (dotimes (i (length _robot_A))
       (sys::poke (elt _robot_A i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _robot_B
     (write-long (length _robot_B) s)
     (dotimes (i (length _robot_B))
       (sys::poke (elt _robot_B i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _pose_A
     (write-long (length _pose_A) s)
     (dotimes (i (length _pose_A))
       (sys::poke (elt _pose_A i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _pose_B
     (write-long (length _pose_B) s)
     (dotimes (i (length _pose_B))
       (sys::poke (elt _pose_B i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _num_armor
     (setq _num_armor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32[] _armor_0
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _armor_0 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _armor_0 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _armor_1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _armor_1 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _armor_1 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; uint8[] _id
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _id (make-array n :element-type :char))
     (replace _id buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _state
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _state (make-array n :element-type :char))
     (replace _state buf :start2 ptr-) (incf ptr- n))
   ;; float32[] _robot_A
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _robot_A (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _robot_A i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _robot_B
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _robot_B (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _robot_B i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _pose_A
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pose_A (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pose_A i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _pose_B
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pose_B (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pose_B i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::ArmorsPos :md5sum-) "d88b6c677bb940ddc0838672e90bcca6")
(setf (get roborts_msgs::ArmorsPos :datatype-) "roborts_msgs/ArmorsPos")
(setf (get roborts_msgs::ArmorsPos :definition-)
      "uint8 num_armor
float32[] armor_0
float32[] armor_1
uint8[] id
uint8[] state
float32[] robot_A
float32[] robot_B
float32[] pose_A
float32[] pose_B

")



(provide :roborts_msgs/ArmorsPos "d88b6c677bb940ddc0838672e90bcca6")


