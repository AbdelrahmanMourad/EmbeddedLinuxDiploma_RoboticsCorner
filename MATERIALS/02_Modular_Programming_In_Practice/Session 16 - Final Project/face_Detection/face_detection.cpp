/*
First Node is Color classifier.
Second Node is Robot Arm
Operation:
classify the color and if it's Green : Pick
____________________________________________________________
Color classifier node which publishes to topic /color
if color is green Color classifier sends 1 otherwise 0.

and robot_arm node subscribes to /color topic and then
take an action if the specified color is found.

*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Load pre-trained face detection classifier (Haar Cascade)
    CascadeClassifier faceCascade;
    if (!faceCascade.load("/usr/share/opencv4/lbpcascades/lbpcascade_frontalface_improved.xml")) {
        cout << "Error loading face cascade." << endl;
        return -1;
    }

    // Open the default camera
    VideoCapture cap(0); // You can replace '0' with the camera index

    if (!cap.isOpened()) {
        cout << "Error opening camera." << endl;
        return -1;
    }

    namedWindow("Face Detection", WINDOW_NORMAL);

    while (true) {
        Mat frame;
        cap >> frame;

        // Convert captured frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces
        vector<Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 4, 0, Size(30, 30));

        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); ++i) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
        }

        // Display the resulting frame
        imshow("Face Detection", frame);

        // Break the loop if 'q' is pressed
        if (waitKey(1) == 'q')
            break;
    }

    // Release the VideoCapture and close all windows
    cap.release();
    destroyAllWindows();

    return 0;
}
