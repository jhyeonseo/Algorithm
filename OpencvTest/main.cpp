#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;

const char* params
= "{ help h         |           | Print usage }"
"{ input          | video4.mp4 | Path to a video or a sequence of image }"
"{ algo           | MOG2      | Background subtraction method (KNN, MOG2) }";


int main(int argc, char* argv[])
{
    CommandLineParser parser(argc, argv, params);
    parser.about("This program shows how to use background subtraction methods provided by "
        " OpenCV. You can process both videos and images.\n");
    if (parser.has("help"))
    {
        parser.printMessage();
    }
    Ptr<BackgroundSubtractor> pBackSub;
    if (parser.get<String>("algo") == "MOG2")
        pBackSub = createBackgroundSubtractorMOG2();
    else
        pBackSub = createBackgroundSubtractorKNN();
    VideoCapture capture(samples::findFile(parser.get<String>("input")));
    if (!capture.isOpened())
    {
        cerr << "Unable to open: " << parser.get<String>("input") << endl;
        return 0;
    }

    int count = 0;
    Mat frame, fgMask;
    Mat wave, dst;
    while (true) 
    {
        capture >> frame;
        if (frame.empty())
            break;

        pBackSub->apply(frame, fgMask);
        rectangle(frame, cv::Point(10, 2), cv::Point(100, 20), cv::Scalar(255, 255, 255), -1);
        stringstream ss;
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

        ////////////////////////////// WAVE KILLING //////////////////////////////
        if (count++ == 0)
        {
            threshold(fgMask, dst, 0, 0, THRESH_BINARY);
            printf("ÃÊ±âÈ­!\n");
        }
        threshold(fgMask, wave, 200, 1, THRESH_BINARY);
        add(wave, dst, dst);
        if (count == 20)
        {
            threshold(dst, dst, 7, 255, THRESH_BINARY);
            imshow("WAVE_KILLNG", dst);
            count = 0;
        }
        ////////////////////////////// WAVE KILLING //////////////////////////////

        imshow("Frame", frame);
        imshow("FG Mask", fgMask);

        int keyboard = waitKey(10);
        if (keyboard == 'q' || keyboard == 27)
            break;
    }

    return 0;
}