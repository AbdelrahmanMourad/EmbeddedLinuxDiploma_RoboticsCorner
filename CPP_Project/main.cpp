#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>

// using namespace std;
// using namespace cv;

void main0_picture(); // Function prototype for picture main function.
void main1_webcam();  // Function prototype for webcam main function.

int main()
{
    /* Scenario:
        0 for picture,
        1 for webcam,
        2 for video file.
    */
    int scenario = 2;

    switch (scenario)
    {
    case 0: // Picture
        main0_picture();
        break;
    case 1: // Webcam
        main1_webcam();
        break;
    case 2: // Video file
        break;
    default:
        std::cout << "Invalid scenario selected." << std::endl;
        return -1;
    }

    return 0; // Return success.
}

void main0_picture() /*___Main Function for pictures___*/
{
    // img1 relative path from the project
    std::string path_img1 = "opencv_pool_img\\img_girl_side_redhead.jpg"; // using escape operator "//" or use "/" forward slash.
    cv::Mat img = cv::imread(path_img1);                                  // load img1 - image read()
    cv::imshow("Frame", img);                                             // view img - image show()
    cv::waitKey(0);                                                       // Delay
}

void main1_webcam() /*___Main Function for Webcam___*/
{
    cv::VideoCapture video(0); // Index 0 in cpp and python. // Video is series of images
    cv::CascadeClassifier facedetect;
    cv::Mat img;
    facedetect.load("haarcascade_frontalface_default.xml");

    while (true)
    {
        video.read(img);
        std::vector<cv::Rect> faces;
        facedetect.detectMultiScale(img, faces, 1.3, 5);
        std::cout << "faces= " << faces.size() << std::endl; // for Debugging.

        for (int i = 0; i < faces.size(); i++)
        {
            cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
            cv::rectangle(img, cv::Point(0, 0), cv::Point(250, 50), cv::Scalar(50, 50, 255), cv::FILLED);
            cv::putText(img, std::to_string(faces.size()) + " Face Found", cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
        }

        cv::imshow("Frame", img);
        cv::waitKey(1); // minimum delay to avoid freezing in milliseconds.
    }
}

void main2_video() /*___Main Function for video___*/
{
    cv::VideoCapture video("opencv_pool_vid\\MyVideo.mp4"); // Index 0 in cpp and python. // Video is series of images
    cv::CascadeClassifier facedetect;
    cv::Mat img;
    facedetect.load("haarcascade_frontalface_default.xml");

    while (true)
    {
        video.read(img);
        std::vector<cv::Rect> faces;
        facedetect.detectMultiScale(img, faces, 1.3, 5);
        // std::cout << "faces= " << faces.size() << std::endl; // for Debugging.

        for (int i = 0; i < faces.size(); i++)
        {
            cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
            cv::rectangle(img, cv::Point(0, 0), cv::Point(250, 50), cv::Scalar(50, 50, 255), cv::FILLED);
            cv::putText(img, std::to_string(faces.size()) + " Face Found", cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
        }

        cv::imshow("Frame", img);
        cv::waitKey(1); // minimum delay to avoid freezing in milliseconds.
    }
}