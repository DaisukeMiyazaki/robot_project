
(cl:in-package :asdf)

(defsystem "vel_to_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "vel2control" :depends-on ("_package_vel2control"))
    (:file "_package_vel2control" :depends-on ("_package"))
  ))