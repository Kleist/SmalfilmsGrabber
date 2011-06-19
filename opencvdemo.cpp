#include <iostream>
#include <string>

#include "cv.h"
#include "highgui.h"

using namespace cv;

const int ENTER_KEYCODE = 13;

Mat frame;
int i=0;

void onMouseClick(int event, int x, int y, int flags, void* param) {
   if (event == CV_EVENT_LBUTTONDOWN) {
      std::stringstream out;
      out << "grab" << i++ << ".jpg";
      imwrite(out.str(), frame);
   }
}

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    cvSetMouseCallback("edges", onMouseClick);
    int i=0;
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);

        int keyCode = waitKey(30);
        if (keyCode == ENTER_KEYCODE) {
        }
        else if (keyCode>=0) {
           break;
        }
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

