
(cl:in-package :asdf)

(defsystem "count_to_odom-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :nav_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "count2odom" :depends-on ("_package_count2odom"))
    (:file "_package_count2odom" :depends-on ("_package"))
  ))