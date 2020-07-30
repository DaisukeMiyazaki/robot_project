;; Auto-generated. Do not edit!


(when (boundp 'arduino_pkg::Num)
  (if (not (find-package "ARDUINO_PKG"))
    (make-package "ARDUINO_PKG"))
  (shadow 'Num (find-package "ARDUINO_PKG")))
(unless (find-package "ARDUINO_PKG::NUM")
  (make-package "ARDUINO_PKG::NUM"))

(in-package "ROS")
;;//! \htmlinclude Num.msg.html


(defclass arduino_pkg::Num
  :super ros::object
  :slots (_Control _Duration ))

(defmethod arduino_pkg::Num
  (:init
   (&key
    ((:Control __Control) 0)
    ((:Duration __Duration) 0)
    )
   (send-super :init)
   (setq _Control (round __Control))
   (setq _Duration (round __Duration))
   self)
  (:Control
   (&optional __Control)
   (if __Control (setq _Control __Control)) _Control)
  (:Duration
   (&optional __Duration)
   (if __Duration (setq _Duration __Duration)) _Duration)
  (:serialization-length
   ()
   (+
    ;; int16 _Control
    2
    ;; uint16 _Duration
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _Control
       (write-word _Control s)
     ;; uint16 _Duration
       (write-word _Duration s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _Control
     (setq _Control (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _Duration
     (setq _Duration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get arduino_pkg::Num :md5sum-) "1a749a2ffb665f31b6ffb7a5a9db9bad")
(setf (get arduino_pkg::Num :datatype-) "arduino_pkg/Num")
(setf (get arduino_pkg::Num :definition-)
      "int16 Control
uint16 Duration 

")



(provide :arduino_pkg/Num "1a749a2ffb665f31b6ffb7a5a9db9bad")


