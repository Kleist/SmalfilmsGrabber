#ifndef SMALFILMSGRABBER_H
#define SMALFILMSGRABBER_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iomanip>

#include "cv.h"
#include "highgui.h"

void onMouseClick(int event, int x, int y, int flags, void* param);

class SmalfilmsGrabber {
   cv::Mat frame_;
   cv::VideoCapture capturer_;
   int imageId_;
public:
   SmalfilmsGrabber() : 
      capturer_(0),
      imageId_(0)
      
   {
      if(!capturer_.isOpened())
         throw std::runtime_error("Couldn't open default camera device!");

      cv::namedWindow("SmalfilmsGrabber",CV_WINDOW_AUTOSIZE);
      cv::setMouseCallback("SmalfilmsGrabber", onMouseClick, this);
   }

   void grabImage(bool show = false) {
      using namespace std;
      capturer_ >> frame_;
      stringstream ss;
      ss << "capture_" << setw(6) << setfill('0') << imageId_++ << ".jpg";
      imwrite(ss.str(), frame_);
      if (show) {
         cout << "Caught frame" << endl;
         imshow("SmalfilmsGrabber", frame_);
      }
   }

   void main() {
      // Grab image to init "UI".
      grabImage(1);
      while (cv::waitKey() < 0) { }
   }
};



#endif // SMALFILMSGRABBER_H
