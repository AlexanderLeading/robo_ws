;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::LaserTarget)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'LaserTarget (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::LASERTARGET")
  (make-package "ROBORTS_MSGS::LASERTARGET"))

(in-package "ROS")
;;//! \htmlinclude LaserTarget.msg.html


(defclass roborts_msgs::LaserTarget
  :super ros::object
  :slots (_num_target _num_points _pose _confidence ))

(defmethod roborts_msgs::LaserTarget
  (:init
   (&key
    ((:num_target __num_target) 0)
    ((:num_points __num_points) (make-array 0 :initial-element 0 :element-type :char))
    ((:pose __pose) (let (r) (dotimes (i 0) (push (instance roborts_msgs::FVector :init) r)) r))
    ((:confidence __confidence) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _num_target (round __num_target))
   (setq _num_points __num_points)
   (setq _pose __pose)
   (setq _confidence __confidence)
   self)
  (:num_target
   (&optional __num_target)
   (if __num_target (setq _num_target __num_target)) _num_target)
  (:num_points
   (&optional __num_points)
   (if __num_points (setq _num_points __num_points)) _num_points)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:serialization-length
   ()
   (+
    ;; uint8 _num_target
    1
    ;; uint8[] _num_points
    (* 1    (length _num_points)) 4
    ;; roborts_msgs/FVector[] _pose
    (apply #'+ (send-all _pose :serialization-length)) 4
    ;; float32[] _confidence
    (* 4    (length _confidence)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _num_target
       (write-byte _num_target s)
     ;; uint8[] _num_points
     (write-long (length _num_points) s)
     (princ _num_points s)
     ;; roborts_msgs/FVector[] _pose
     (write-long (length _pose) s)
     (dolist (elem _pose)
       (send elem :serialize s)
       )
     ;; float32[] _confidence
     (write-long (length _confidence) s)
     (dotimes (i (length _confidence))
       (sys::poke (elt _confidence i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _num_target
     (setq _num_target (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _num_points
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _num_points (make-array n :element-type :char))
     (replace _num_points buf :start2 ptr-) (incf ptr- n))
   ;; roborts_msgs/FVector[] _pose
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pose (let (r) (dotimes (i n) (push (instance roborts_msgs::FVector :init) r)) r))
     (dolist (elem- _pose)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; float32[] _confidence
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _confidence (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _confidence i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::LaserTarget :md5sum-) "b7a891f119d989835596adf70e8ef67b")
(setf (get roborts_msgs::LaserTarget :datatype-) "roborts_msgs/LaserTarget")
(setf (get roborts_msgs::LaserTarget :definition-)
      "uint8 num_target
uint8[] num_points
FVector[] pose
float32[] confidence

================================================================================
MSG: roborts_msgs/FVector
float32[] vector

")



(provide :roborts_msgs/LaserTarget "b7a891f119d989835596adf70e8ef67b")


