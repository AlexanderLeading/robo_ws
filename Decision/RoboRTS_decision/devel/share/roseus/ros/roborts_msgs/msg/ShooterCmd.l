;; Auto-generated. Do not edit!


(when (boundp 'roborts_msgs::ShooterCmd)
  (if (not (find-package "ROBORTS_MSGS"))
    (make-package "ROBORTS_MSGS"))
  (shadow 'ShooterCmd (find-package "ROBORTS_MSGS")))
(unless (find-package "ROBORTS_MSGS::SHOOTERCMD")
  (make-package "ROBORTS_MSGS::SHOOTERCMD"))

(in-package "ROS")
;;//! \htmlinclude ShooterCmd.msg.html


(defclass roborts_msgs::ShooterCmd
  :super ros::object
  :slots (_is_shoot _shoot_cmd _c_shoot_cmd _fric_wheel_run _shoot_freq ))

(defmethod roborts_msgs::ShooterCmd
  (:init
   (&key
    ((:is_shoot __is_shoot) nil)
    ((:shoot_cmd __shoot_cmd) 0)
    ((:c_shoot_cmd __c_shoot_cmd) 0)
    ((:fric_wheel_run __fric_wheel_run) 0)
    ((:shoot_freq __shoot_freq) 0)
    )
   (send-super :init)
   (setq _is_shoot __is_shoot)
   (setq _shoot_cmd (round __shoot_cmd))
   (setq _c_shoot_cmd (round __c_shoot_cmd))
   (setq _fric_wheel_run (round __fric_wheel_run))
   (setq _shoot_freq (round __shoot_freq))
   self)
  (:is_shoot
   (&optional __is_shoot)
   (if __is_shoot (setq _is_shoot __is_shoot)) _is_shoot)
  (:shoot_cmd
   (&optional __shoot_cmd)
   (if __shoot_cmd (setq _shoot_cmd __shoot_cmd)) _shoot_cmd)
  (:c_shoot_cmd
   (&optional __c_shoot_cmd)
   (if __c_shoot_cmd (setq _c_shoot_cmd __c_shoot_cmd)) _c_shoot_cmd)
  (:fric_wheel_run
   (&optional __fric_wheel_run)
   (if __fric_wheel_run (setq _fric_wheel_run __fric_wheel_run)) _fric_wheel_run)
  (:shoot_freq
   (&optional __shoot_freq)
   (if __shoot_freq (setq _shoot_freq __shoot_freq)) _shoot_freq)
  (:serialization-length
   ()
   (+
    ;; bool _is_shoot
    1
    ;; uint8 _shoot_cmd
    1
    ;; uint8 _c_shoot_cmd
    1
    ;; uint8 _fric_wheel_run
    1
    ;; uint16 _shoot_freq
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_shoot
       (if _is_shoot (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _shoot_cmd
       (write-byte _shoot_cmd s)
     ;; uint8 _c_shoot_cmd
       (write-byte _c_shoot_cmd s)
     ;; uint8 _fric_wheel_run
       (write-byte _fric_wheel_run s)
     ;; uint16 _shoot_freq
       (write-word _shoot_freq s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_shoot
     (setq _is_shoot (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _shoot_cmd
     (setq _shoot_cmd (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _c_shoot_cmd
     (setq _c_shoot_cmd (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _fric_wheel_run
     (setq _fric_wheel_run (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _shoot_freq
     (setq _shoot_freq (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get roborts_msgs::ShooterCmd :md5sum-) "1ce874438e33b75dd468a5f9109af925")
(setf (get roborts_msgs::ShooterCmd :datatype-) "roborts_msgs/ShooterCmd")
(setf (get roborts_msgs::ShooterCmd :definition-)
      "bool is_shoot
uint8 shoot_cmd
uint8 c_shoot_cmd
uint8 fric_wheel_run
uint16 shoot_freq

")



(provide :roborts_msgs/ShooterCmd "1ce874438e33b75dd468a5f9109af925")


