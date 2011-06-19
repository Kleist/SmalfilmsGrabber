#include "smalfilmsgrabber.h"

const int ENTER_KEYCODE = 13;

int main(int, char**)
{
   SmalfilmsGrabber grabber;
   grabber.grabImage();
   grabber.main();
}

