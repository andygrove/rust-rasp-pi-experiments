#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

VideoCapture capture;
Mat frame;

extern int video_init() {
  if (!capture.open(0)) {
    return -1;
  }
  return 0;
}

extern int video_grab() {
  capture >> frame;
  if (frame.empty()) {
    return -1;
  }
  imshow("test", frame);
  return 0;
}




/*

int main( int argc, const char** argv )
{

            Mat frame1 = frame.clone();
            detectAndDraw( frame1, scale, tryflip );

            int c = waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }

    return 0;
}

void detectAndDraw( Mat& img, 
                    double scale, bool tryflip )
{
    double t = 0;
    vector<Rect> faces, faces2;
    const static Scalar colors[] =
    {
        Scalar(255,0,0),
        Scalar(255,128,0),
        Scalar(255,255,0),
        Scalar(0,255,0),
        Scalar(0,128,255),
        Scalar(0,255,255),
        Scalar(0,0,255),
        Scalar(255,0,255)
    };
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    imshow( "result", img );
}

*/
