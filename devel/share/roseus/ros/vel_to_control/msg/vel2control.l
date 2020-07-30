;; Auto-generated. Do not edit!


(when (boundp 'vel_to_control::vel2control)
  (if (not (find-package "VEL_TO_CONTROL"))
    (make-package "VEL_TO_CONTROL"))
  (shadow 'vel2control (find-package "VEL_TO_CONTROL")))
(unless (find-package "VEL_TO_CONTROL::VEL2CONTROL")
  (make-package "VEL_TO_CONTROL::VEL2CONTROL"))

(in-package "ROS")
;;//! \htmlinclude vel2control.msg.html


(defclass vel_to_control::vel2control
  :super ros::object
  :slots ())

(defmethod vel_to_control::vel2control
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get vel_to_control::vel2control :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get vel_to_control::vel2control :datatype-) "vel_to_control/vel2control")
(setf (get vel_to_control::vel2control :definition-)
      "
")



(provide :vel_to_control/vel2control "d41d8cd98f00b204e9800998ecf8427e")


