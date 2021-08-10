;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::FusionTarget)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'FusionTarget (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::FUSIONTARGET")
  (make-package "ROBORTS_MSGS::FUSIONTARGET"))

(in-package "ROS")
;;//! \htmlinclude FusionTarget.msg.html


(defclass roborts_msgs::FusionTarget
  :super ros::object
  :slots (_num_id_target _num_no_id_target _id_targets _no_id_targets ))

(defmethod roborts_msgs::FusionTarget
  (:init
   (&key
    ((:num_id_target __num_id_target) 0)
    ((:num_no_id_target __num_no_id_target) 0)
    ((:id_targets __id_targets) (let (r) (dotimes (i 0) (push (instance roborts_msgs::Target :init) r)) r))
    ((:no_id_targets __no_id_targets) (let (r) (dotimes (i 0) (push (instance roborts_msgs::Target :init) r)) r))
    )
   (send-super :init)
   (setq _num_id_target (round __num_id_target))
   (setq _num_no_id_target (round __num_no_id_target))
   (setq _id_targets __id_targets)
   (setq _no_id_targets __no_id_targets)
   self)
  (:num_id_target
   (&optional __num_id_target)
   (if __num_id_target (setq _num_id_target __num_id_target)) _num_id_target)
  (:num_no_id_target
   (&optional __num_no_id_target)
   (if __num_no_id_target (setq _num_no_id_target __num_no_id_target)) _num_no_id_target)
  (:id_targets
   (&rest __id_targets)
   (if (keywordp (car __id_targets))
       (send* _id_targets __id_targets)
     (progn
       (if __id_targets (setq _id_targets (car __id_targets)))
       _id_targets)))
  (:no_id_targets
   (&rest __no_id_targets)
   (if (keywordp (car __no_id_targets))
       (send* _no_id_targets __no_id_targets)
     (progn
       (if __no_id_targets (setq _no_id_targets (car __no_id_targets)))
       _no_id_targets)))
  (:serialization-length
   ()
   (+
    ;; uint8 _num_id_target
    1
    ;; uint8 _num_no_id_target
    1
    ;; roborts_msgs/Target[] _id_targets
    (apply #'+ (send-all _id_targets :serialization-length)) 4
    ;; roborts_msgs/Target[] _no_id_targets
    (apply #'+ (send-all _no_id_targets :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _num_id_target
       (write-byte _num_id_target s)
     ;; uint8 _num_no_id_target
       (write-byte _num_no_id_target s)
     ;; roborts_msgs/Target[] _id_targets
     (write-long (length _id_targets) s)
     (dolist (elem _id_targets)
       (send elem :serialize s)
       )
     ;; roborts_msgs/Target[] _no_id_targets
     (write-long (length _no_id_targets) s)
     (dolist (elem _no_id_targets)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _num_id_target
     (setq _num_id_target (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _num_no_id_target
     (setq _num_no_id_target (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; roborts_msgs/Target[] _id_targets
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _id_targets (let (r) (dotimes (i n) (push (instance roborts_msgs::Target :init) r)) r))
     (dolist (elem- _id_targets)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; roborts_msgs/Target[] _no_id_targets
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _no_id_targets (let (r) (dotimes (i n) (push (instance roborts_msgs::Target :init) r)) r))
     (dolist (elem- _no_id_targets)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::FusionTarget :md5sum-) "4b446fdc6c26040d3eceffafbf5e0975")
(setf (get roborts_msgs::FusionTarget :datatype-) "roborts_msgs/FusionTarget")
(setf (get roborts_msgs::FusionTarget :definition-)
      "uint8 num_id_target
uint8 num_no_id_target
Target[] id_targets
Target[] no_id_targets

================================================================================
MSG: roborts_msgs/Target
uint8 id
uint8 state
uint8 sensor
float32 x
float32 y
float32 confidence

")



(provide :roborts_msgs/FusionTarget "4b446fdc6c26040d3eceffafbf5e0975")


