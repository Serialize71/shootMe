shootMe is a face-tracking robot project that combines computer vision vision and motor control.

Project Overview
The robot leverages YOLO (You Only Look Once) object detection model from Ultralytics to identify and track faces in real-time. The detected face's location is then sent to an ESP32 microcontroller, which controls the motors to follow the target dynamically.

Features
Real-time face detection: Powered by the YOLO model.

ESP32 integration: Face location data is transmitted to the ESP32 for motor control.

Dynamic tracking: Motors adjust to keep the face in view.
