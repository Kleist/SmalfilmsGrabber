#ifndef SMALFILMSGRABBER_H
#define SMALFILMSGRABBER_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

#include "cv.h"
#include "highgui.h"

void onMouseClick(int event, int x, int y, int flags, void* param);

class SmalfilmsGrabber {
   cv::VideoCapture capturer_;
   cv::VideoWriter writer_;
   std::vector<cv::Mat> frames_;
public:
   SmalfilmsGrabber() 
      : capturer_(0)
      , writer_("out.mov", CV_FOURCC('P','I','M','1'), capturer_.get(CV_CAP_PROP_FPS), cv::Size(capturer_.get(CV_CAP_PROP_FRAME_WIDTH), capturer_.get(CV_CAP_PROP_FRAME_WIDTH)) )  
      //, writer_("out.avi", -1, 25, cv::Size(640, 480) )  
   {
      if(!capturer_.isOpened())
         throw std::runtime_error("Couldn't open default camera device!");

      if (!writer_.isOpened())
         throw std::runtime_error("Couldn't open video writer");

      //cv::namedWindow("SmalfilmsGrabber",CV_WINDOW_AUTOSIZE);
      //cv::setMouseCallback("SmalfilmsGrabber", onMouseClick, this);
      frames_.resize(100);
      std::cout << "Camera FPS: " << capturer_.get(CV_CAP_PROP_FPS) << std::endl;
      std::cout << "Resolution: " << capturer_.get(CV_CAP_PROP_FRAME_WIDTH) << "x" << capturer_.get(CV_CAP_PROP_FRAME_WIDTH) << std::endl;
   }

   void grabImage() {
      cv::Mat frame;
      capturer_ >> frame;
      //std::cout << "Caught frame" << std::endl;
      //imshow("SmalfilmsGrabber", frame);
      writer_ << frame;
   }

   void main() {
      for (int i=0; i<50; ++i) {
         grabImage();
      }
      std::cout << "Done grabbing" << std::endl;

      // while (cv::waitKey() < 0) {
      //    if (i<frames_.size()) {
      //       //capturer_ >> frames_[i];
      //    }
      // }
   }
};



#endif // SMALFILMSGRABBER_H
