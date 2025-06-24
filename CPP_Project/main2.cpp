/*________________Stable__________________*/

#include <opencv2/imgcodecs.hpp> // For image reading and writing
#include <opencv2/highgui.hpp>   // For GUI windows (imshow, waitKey)
#include <opencv2/imgproc.hpp>   // For image processing operations (rectangle, putText, etc.)
#include <opencv2/objdetect.hpp> // For object detection (CascadeClassifier)
#include <iostream>
#include <vector>

// Function prototypes for different processing scenarios.
void main0_picture(); // main0_picture: Process a still image.
void main1_webcam();  // main1_webcam : Process input from a webcam.
void main2_video();   // main2_video  : Process a video file.

int main()
{
    // Select the scenario to use:
    // 0 => process a picture file.
    // 1 => capture and process a webcam stream.
    // 2 => process a video file.
    int scenario = 2; // Change to 0, 1 or 2 based on what you want to test.

    switch (scenario)
    {
    case 0: // Picture scenario
        main0_picture();
        break;
    case 1: // Webcam scenario
        main1_webcam();
        break;
    case 2: // Video file scenario
        main2_video();
        break;
    default:
        std::cout << "Invalid scenario selected." << std::endl;
        return -1;
    }
    return 0; // Exit successfully.
}

void main0_picture()
{
    // Define the relative path to the image file.
    std::string path_img1 = "opencv_pool_img\\img_girl_side_redhead.jpg";
    // Load the image from disk into a matrix (Mat). imread returns an empty Mat if the file is not found.
    cv::Mat img = cv::imread(path_img1);

    // Check if the image was loaded successfully.
    if (img.empty())
    {
        std::cerr << "Error: Could not load image from " << path_img1 << std::endl;
        return;
    }

    // Create a CascadeClassifier for face detection.
    cv::CascadeClassifier faceDetect;
    // Load the Haar Cascade XML file. Adjust the path if necessary.
    if (!faceDetect.load("haarcascade_frontalface_default.xml"))
    {
        std::cerr << "Error: Could not load Haar Cascade classifier XML file." << std::endl;
        return;
    }

    // Detect faces in the image.
    // faces will contain rectangles (cv::Rect) for each detected area.
    std::vector<cv::Rect> faces;
    faceDetect.detectMultiScale(img, faces, 1.3, 5);

    // Draw a rectangle around each face detected.
    for (size_t i = 0; i < faces.size(); i++)
    {
        // faces[i].tl() gives the top-left point
        // faces[i].br() gives the bottom-right point
        cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
    }

    // Prepare a label showing the number of faces found.
    std::string label = std::to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found");
    // Draw a filled rectangle at the top-left to serve as a background for the text label.
    cv::rectangle(img, cv::Point(0, 0), cv::Point(250, 50), cv::Scalar(50, 50, 255), cv::FILLED);
    // Overlay the text label onto the image.
    cv::putText(img, label, cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);

    // Display the processed image in a window titled "Frame".
    cv::imshow("Frame", img);
    // Wait indefinitely until a key is pressed.
    cv::waitKey(0);
}

void main1_webcam()
{
    // Open the default webcam by passing index 0.
    cv::VideoCapture video(0);
    // Confirm that the webcam is opened successfully.
    if (!video.isOpened())
    {
        std::cerr << "Error: Could not open the webcam." << std::endl;
        return;
    }

    // Create a CascadeClassifier to detect faces.
    cv::CascadeClassifier faceDetect;
    if (!faceDetect.load("haarcascade_frontalface_default.xml"))
    {
        std::cerr << "Error: Could not load Haar Cascade classifier XML file." << std::endl;
        return;
    }

    cv::Mat img; // Matrix to hold each captured frame.
    while (true)
    {
        // Capture a frame from the webcam.
        if (!video.read(img) || img.empty())
        {
            std::cerr << "Error: Unable to capture a frame from the webcam." << std::endl;
            break;
        }

        // Detect faces in the current frame.
        std::vector<cv::Rect> faces;
        faceDetect.detectMultiScale(img, faces, 1.3, 5);

        // Debug: print the number of detected faces.
        std::cout << "faces= " << faces.size() << std::endl;

        // If faces have been detected, draw rectangles around them.
        for (size_t i = 0; i < faces.size(); i++)
        {
            cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
        }
        // Optionally, overlay the count of detected faces on the image.
        cv::rectangle(img, cv::Point(0, 0), cv::Point(250, 50), cv::Scalar(50, 50, 255), cv::FILLED);
        cv::putText(img, std::to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found"),
                    cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);

        // Display the frame with the drawn rectangles and text.
        cv::imshow("Frame", img);
        // Wait for 30ms. If any key is pressed, break the loop to exit.
        if (cv::waitKey(30) >= 0)
            break;
    }
}

void main2_video()
{
    // Define the relative path to the video file.
    std::string videoPath = "opencv_pool_vid\\MyVideo.mp4";
    // Open the video file.
    cv::VideoCapture video(videoPath);
    // Check if the video file opened correctly.
    if (!video.isOpened())
    {
        std::cerr << "Error: Could not open video file from " << videoPath << std::endl;
        return;
    }

    // Create a CascadeClassifier object for detecting faces.
    cv::CascadeClassifier faceDetect;
    if (!faceDetect.load("haarcascade_frontalface_default.xml"))
    {
        std::cerr << "Error: Could not load Haar Cascade classifier XML file." << std::endl;
        return;
    }

    cv::Mat img; // Matrix to store each video frame.
    while (true)
    {
        // Read the next frame from the video.
        if (!video.read(img) || img.empty())
        {
            // When the video ends or a frame is not captured, exit the loop.
            std::cout << "End of video or unable to read the frame." << std::endl;
            break;
        }

        // Detect faces in the current frame.
        std::vector<cv::Rect> faces;
        faceDetect.detectMultiScale(img, faces, 1.3, 5);

        // Draw a rectangle around each detected face.
        for (size_t i = 0; i < faces.size(); i++)
        {
            cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
        }
        // Display the number of detected faces on the top-left.
        cv::rectangle(img, cv::Point(0, 0), cv::Point(250, 50), cv::Scalar(50, 50, 255), cv::FILLED);
        cv::putText(img, std::to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found"),
                    cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);

        // Show the processed video frame.
        cv::imshow("Frame", img);
        // Wait 30ms before moving to the next frame; exit if a key is pressed.
        if (cv::waitKey(1) >= 0)
            break;
    }
}
