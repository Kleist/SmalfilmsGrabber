#include "smalfilmsgrabber.h"

void onMouseClick(int event, int x, int y, int flags, void* param) {
   if (event == CV_EVENT_LBUTTONDOWN) {
      static_cast<SmalfilmsGrabber*>(param)->grabImage();
   }
}
