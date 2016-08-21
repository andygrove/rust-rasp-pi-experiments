#!/bin/bash
gcc example.cpp -l opencv_core -l opencv_videoio -l opencv_highgui -l opencv_imgproc -l opencv_imgcodecs -shared -o libopencvexample.so

