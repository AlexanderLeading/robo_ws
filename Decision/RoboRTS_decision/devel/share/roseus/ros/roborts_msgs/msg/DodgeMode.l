;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::DodgeMode)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'DodgeMode (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::DODGEMODE")
  (make-package "ROBORTS_MSGS::DODGEMODE"))

(in-package "ROS")
;;//! \htmlinclude DodgeMode.msg.html


(defclass roborts_msgs::DodgeMode
  :super ros::object
  :slots (_is_dodge ))

(defmethod roborts_msgs::DodgeMode
  (:init
   (&key
    ((:is_dodge __is_dodge) nil)
    )
   (send-super :init)
   (setq _is_dodge __is_dodge)
   self)
  (:is_dodge
   (&optional __is_dodge)
   (if __is_dodge (setq _is_dodge __is_dodge)) _is_dodge)
  (:serialization-length
   ()
   (+
    ;; bool _is_dodge
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_dodge
       (if _is_dodge (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_dodge
     (setq _is_dodge (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get roborts_msgs::DodgeMode :md5sum-) "e86a3c0123103abb455aca69f2a22f53")
(setf (get roborts_msgs::DodgeMode :datatype-) "roborts_msgs/DodgeMode")
(setf (get roborts_msgs::DodgeMode :definition-)
      "bool is_dodge

")



(provide :roborts_msgs/DodgeMode "e86a3c0123103abb455aca69f2a22f53")


