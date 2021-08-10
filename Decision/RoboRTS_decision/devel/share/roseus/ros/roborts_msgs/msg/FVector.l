;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::FVector)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'FVector (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::FVECTOR")
  (make-package "ROBORTS_MSGS::FVECTOR"))

(in-package "ROS")
;;//! \htmlinclude FVector.msg.html


(defclass roborts_msgs::FVector
  :super ros::object
  :slots (_vector ))

(defmethod roborts_msgs::FVector
  (:init
   (&key
    ((:vector __vector) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _vector __vector)
   self)
  (:vector
   (&optional __vector)
   (if __vector (setq _vector __vector)) _vector)
  (:serialization-length
   ()
   (+
    ;; float32[] _vector
    (* 4    (length _vector)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _vector
     (write-long (length _vector) s)
     (dotimes (i (length _vector))
       (sys::poke (elt _vector i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _vector
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vector (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _vector i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get roborts_msgs::FVector :md5sum-) "ce95c8b6ee55a22d6d20b2422ec7f431")
(setf (get roborts_msgs::FVector :datatype-) "roborts_msgs/FVector")
(setf (get roborts_msgs::FVector :definition-)
      "float32[] vector

")



(provide :roborts_msgs/FVector "ce95c8b6ee55a22d6d20b2422ec7f431")


