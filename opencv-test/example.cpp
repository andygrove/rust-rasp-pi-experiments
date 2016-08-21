#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

VideoCapture inputVideo;
VideoWriter outputVideo;

Mat frame;

extern "C" int32_t video_init() {
  if (!inputVideo.open(0)) {
    return -1;
  }

//  int fourcc = static_cast<int>(inputVideo.get(CV_CAP_PROP_FOURCC)); 
 // cout << "fourcc = " << fourcc << endl;

  Size S = Size((int) inputVideo.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
                  (int) inputVideo.get(CV_CAP_PROP_FRAME_HEIGHT));

  //outputVideo.open("out.avi", VideoWriter::fourcc('M','J','P','G'), inputVideo.get(CV_CAP_PROP_FPS), S, true);
  outputVideo.open("out.mp4", VideoWriter::fourcc('M','P','4','V'), inputVideo.get(CV_CAP_PROP_FPS), S, true);
  if (!outputVideo.isOpened()) {
    cerr << "failed to open video output file" << endl;
    return -2;
  }

  return 0;
}

extern "C" int32_t video_grab(const char *data) {

  inputVideo >> frame;

  if (frame.empty()) {
    return -1;
  }

  putText(frame, data, cvPoint(30,30), 
    FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);

  outputVideo << frame;

  return 0;
}

extern "C" int32_t video_close() {
  outputVideo.release();
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
