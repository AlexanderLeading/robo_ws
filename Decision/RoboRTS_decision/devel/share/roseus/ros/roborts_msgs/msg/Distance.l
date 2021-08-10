;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::Distance)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'Distance (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::DISTANCE")
  (make-package "ROBORTS_MSGS::DISTANCE"))

(in-package "ROS")
;;//! \htmlinclude Distance.msg.html


(defclass roborts_msgs::Distance
  :super ros::object
  :slots (_distance ))

(defmethod roborts_msgs::Distance
  (:init
   (&key
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _distance (float __distance))
   self)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; float64 _distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get roborts_msgs::Distance :md5sum-) "acff7fda0c683c872875f5c4b069f124")
(setf (get roborts_msgs::Distance :datatype-) "roborts_msgs/Distance")
(setf (get roborts_msgs::Distance :definition-)
      "float64 distance

")



(provide :roborts_msgs/Distance "acff7fda0c683c872875f5c4b069f124")


