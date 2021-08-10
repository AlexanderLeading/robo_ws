;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::TargetInfo)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'TargetInfo (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::TARGETINFO")
  (make-package "ROBORTS_MSGS::TARGETINFO"))

(in-package "ROS")
;;//! \htmlinclude TargetInfo.msg.html


(defclass roborts_msgs::TargetInfo
  :super ros::object
  :slots (_is_valid _id _bbox _pose _optical_flow ))

(defmethod roborts_msgs::TargetInfo
  (:init
   (&key
    ((:is_valid __is_valid) nil)
    ((:id __id) 0)
    ((:bbox __bbox) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pose __pose) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:optical_flow __optical_flow) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _is_valid __is_valid)
   (setq _id (round __id))
   (setq _bbox __bbox)
   (setq _pose __pose)
   (setq _optical_flow __optical_flow)
   self)
  (:is_valid
   (&optional __is_valid)
   (if __is_valid (setq _is_valid __is_valid)) _is_valid)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:bbox
   (&optional __bbox)
   (if __bbox (setq _bbox __bbox)) _bbox)
  (:pose
   (&optional __pose)
   (if __pose (setq _pose __pose)) _pose)
  (:optical_flow
   (&optional __optical_flow)
   (if __optical_flow (setq _optical_flow __optical_flow)) _optical_flow)
  (:serialization-length
   ()
   (+
    ;; bool _is_valid
    1
    ;; uint8 _id
    1
    ;; float32[] _bbox
    (* 4    (length _bbox)) 4
    ;; float32[] _pose
    (* 4    (length _pose)) 4
    ;; float32[] _optical_flow
    (* 4    (length _optical_flow)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_valid
       (if _is_valid (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _id
       (write-byte _id s)
     ;; float32[] _bbox
     (write-long (length _bbox) s)
     (dotimes (i (length _bbox))
       (sys::poke (elt _bbox i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _pose
     (write-long (length _pose) s)
     (dotimes (i (length _pose))
       (sys::poke (elt _pose i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _optical_flow
     (write-long (length _optical_flow) s)
     (dotimes (i (length _optical_flow))
       (sys::poke (elt _optical_flow i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_valid
     (setq _is_valid (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32[] _bbox
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _bbox (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _bbox i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _pose
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pose (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pose i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _optical_flow
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _optical_flow (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _optical_flow i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::TargetInfo :md5sum-) "332308c6498382ae0ac339a429da4973")
(setf (get roborts_msgs::TargetInfo :datatype-) "roborts_msgs/TargetInfo")
(setf (get roborts_msgs::TargetInfo :definition-)
      "bool is_valid
uint8 id
float32[] bbox
float32[] pose
float32[] optical_flow

")



(provide :roborts_msgs/TargetInfo "332308c6498382ae0ac339a429da4973")


