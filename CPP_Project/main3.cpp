/************** YOLO NOT WORKING YET **************/



#include <opencv2/imgcodecs.hpp> // For image file reading and writing.
#include <opencv2/highgui.hpp>   // For displaying images/windows.
#include <opencv2/imgproc.hpp>   // For image transformations like resize(), rectangle(), putText(), etc.
#include <opencv2/objdetect.hpp> // For Haar Cascade detection.
#include <opencv2/dnn.hpp>       // For deep learning (DNN-based) detection.
#include <iostream>
#include <vector>
#include <chrono>    // For measuring inference time.
#include <algorithm> // For std::min.

using namespace std;
using namespace cv;
using namespace cv::dnn;

// -------------------------------------------------------------------------
// Helper Function: Resize an image to fit within a maximum screen size.
// -------------------------------------------------------------------------
void resizeToScreen(Mat &img, int maxWidth, int maxHeight)
{
    if (img.empty())
        return;
    int imgWidth = img.cols;
    int imgHeight = img.rows;
    // Calculate scaling factors (preserving aspect ratio).
    double scaleWidth = (double)maxWidth / imgWidth;
    double scaleHeight = (double)maxHeight / imgHeight;
    double scale = min(scaleWidth, scaleHeight);
    // Only resize if the scale is smaller than 1.
    if (scale < 1.0)
    {
        resize(img, img, Size(), scale, scale);
    }
}

// ---------------------- Haar Cascade Based Functions ----------------------

// 0. Process Picture using Haar Cascade (with resizing)
void main0_haarPicture()
{
    string imagePath = "opencv_pool_img\\img_girl_side_redhead.jpg";
    Mat img = imread(imagePath);
    if (img.empty())
    {
        cerr << "Error: Could not load image from " << imagePath << endl;
        return;
    }
    // Downsize image to fit on screen (e.g., maximum 1280x720).
    resizeToScreen(img, 1280, 720);

    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml"))
    {
        cerr << "Error: Could not load Haar Cascade classifier." << endl;
        return;
    }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.3, 5);

    // Draw a rectangle around each face.
    for (size_t i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
    }
    // Overlay text showing number of faces detected.
    string label = to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found");
    rectangle(img, Point(0, 0), Point(250, 50), Scalar(50, 50, 255), FILLED);
    putText(img, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);

    imshow("Haar Cascade Picture", img);
    waitKey(0);
}

// 1. Process Webcam stream using Haar Cascade.
void main1_haarWebcam()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open webcam." << endl;
        return;
    }

    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml"))
    {
        cerr << "Error: Could not load Haar Cascade classifier." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cerr << "Error: Could not read frame from webcam." << endl;
            break;
        }
        // Optionally downsize the frame for display.
        resizeToScreen(frame, 1280, 720);

        vector<Rect> faces;
        faceCascade.detectMultiScale(frame, faces, 1.3, 5);

        for (size_t i = 0; i < faces.size(); i++)
        {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
        }
        rectangle(frame, Point(0, 0), Point(250, 50), Scalar(50, 50, 255), FILLED);
        putText(frame, to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found"),
                Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);

        imshow("Haar Cascade Webcam", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// 2. Process Video File using Haar Cascade.
void main2_haarVideo()
{
    string videoPath = "opencv_pool_vid\\MyVideo.mp4";
    VideoCapture cap(videoPath);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open video file " << videoPath << endl;
        return;
    }

    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml"))
    {
        cerr << "Error: Could not load Haar Cascade classifier." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cout << "Finished processing video or cannot read frame." << endl;
            break;
        }
        resizeToScreen(frame, 1280, 720);

        vector<Rect> faces;
        faceCascade.detectMultiScale(frame, faces, 1.3, 5);

        for (size_t i = 0; i < faces.size(); i++)
        {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
        }
        rectangle(frame, Point(0, 0), Point(250, 50), Scalar(50, 50, 255), FILLED);
        putText(frame, to_string(faces.size()) + (faces.size() == 1 ? " Face Found" : " Faces Found"),
                Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);

        imshow("Haar Cascade Video", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// ------------------- Deep Learning (Caffe-based Face Detector) Functions -------------------

// 3. Process Picture using Deep Learning (Caffe) face detector.
void main3_deepFacePicture()
{
    string imagePath = "opencv_pool_img\\img_girl_side_redhead.jpg";
    Mat img = imread(imagePath);
    if (img.empty())
    {
        cerr << "Error: Could not load image from " << imagePath << endl;
        return;
    }
    resizeToScreen(img, 1280, 720);

    // Load the Caffe model: ensure that these two files are available.
    Net net = readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000_fp16.caffemodel");
    if (net.empty())
    {
        cerr << "Error: Could not load the deep learning model." << endl;
        return;
    }

    // Create a blob from the image – note the size (300x300) and mean subtraction.
    auto start = chrono::steady_clock::now();
    Mat blob = blobFromImage(img, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
    net.setInput(blob);
    Mat detections = net.forward();
    auto end = chrono::steady_clock::now();
    double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // The model returns a 4D matrix; extract the detections.
    Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());
    int faceCount = 0;
    float confidenceThreshold = 0.5f;
    for (int i = 0; i < detectionMat.rows; i++)
    {
        float confidence = detectionMat.at<float>(i, 2);
        if (confidence > confidenceThreshold)
        {
            int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * img.cols);
            int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * img.rows);
            int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * img.cols);
            int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * img.rows);
            rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 3);
            faceCount++;
        }
    }

    // Overlay detection info (face count and processing time).
    string label = to_string(faceCount) +
                   (faceCount == 1 ? " Face Found" : " Faces Found") +
                   " | " + to_string(detectionTime) + " ms";
    rectangle(img, Point(0, 0), Point(350, 50), Scalar(0, 255, 0), FILLED);
    putText(img, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(0, 0, 0), 1);

    imshow("Deep Learning Picture", img);
    waitKey(0);
}

// 4. Process Webcam using Deep Learning (Caffe) face detector.
void main4_deepFaceWebcam()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open webcam." << endl;
        return;
    }

    Net net = readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000_fp16.caffemodel");
    if (net.empty())
    {
        cerr << "Error: Could not load the deep learning model." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cerr << "Error: Could not capture frame from webcam." << endl;
            break;
        }
        resizeToScreen(frame, 1280, 720);

        Mat blob = blobFromImage(frame, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
        net.setInput(blob);
        auto start = chrono::steady_clock::now();
        Mat detections = net.forward();
        auto end = chrono::steady_clock::now();
        double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());
        int faceCount = 0;
        float confidenceThreshold = 0.5f;
        for (int i = 0; i < detectionMat.rows; i++)
        {
            float confidence = detectionMat.at<float>(i, 2);
            if (confidence > confidenceThreshold)
            {
                int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
                rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 3);
                faceCount++;
            }
        }
        string label = to_string(faceCount) +
                       (faceCount == 1 ? " Face Found" : " Faces Found") +
                       " | " + to_string(detectionTime) + " ms";
        rectangle(frame, Point(0, 0), Point(350, 50), Scalar(0, 255, 0), FILLED);
        putText(frame, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(0, 0, 0), 1);

        imshow("Deep Learning Webcam", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// 5. Process Video File using Deep Learning (Caffe) face detector.
void main5_deepFaceVideo()
{
    string videoPath = "opencv_pool_vid\\MyVideo.mp4";
    VideoCapture cap(videoPath);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open video file " << videoPath << endl;
        return;
    }

    Net net = readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000_fp16.caffemodel");
    if (net.empty())
    {
        cerr << "Error: Could not load the deep learning model." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cout << "Finished processing video or cannot read next frame." << endl;
            break;
        }
        resizeToScreen(frame, 1280, 720);

        Mat blob = blobFromImage(frame, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
        net.setInput(blob);
        auto start = chrono::steady_clock::now();
        Mat detections = net.forward();
        auto end = chrono::steady_clock::now();
        double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());
        int faceCount = 0;
        float confidenceThreshold = 0.5f;
        for (int i = 0; i < detectionMat.rows; i++)
        {
            float confidence = detectionMat.at<float>(i, 2);
            if (confidence > confidenceThreshold)
            {
                int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
                rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 3);
                faceCount++;
            }
        }
        string label = to_string(faceCount) +
                       (faceCount == 1 ? " Face Found" : " Faces Found") +
                       " | " + to_string(detectionTime) + " ms";
        rectangle(frame, Point(0, 0), Point(350, 50), Scalar(0, 255, 0), FILLED);
        putText(frame, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(0, 0, 0), 1);

        imshow("Deep Learning Video", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// ------------------- YOLO-based Face Detector Functions -------------------

// Helper function to get the names of the output layers from the YOLO network.
vector<string> getOutputsNames(const Net &net)
{
    vector<int> outLayers = net.getUnconnectedOutLayers();
    vector<String> layersNames = net.getLayerNames();
    vector<string> names;
    names.resize(outLayers.size());
    for (size_t i = 0; i < outLayers.size(); ++i)
        names[i] = layersNames[outLayers[i] - 1];
    return names;
}

// 6. Process Picture using YOLO for face detection.
void main6_yoloPicture()
{
    string imagePath = "opencv_pool_img\\img_girl_side_redhead.jpg";
    Mat img = imread(imagePath);
    if (img.empty())
    {
        cerr << "Error: Could not load image from " << imagePath << endl;
        return;
    }
    resizeToScreen(img, 1280, 720);

    // Load YOLO network. Make sure you have the appropriate files.
    // For example: "yolov3-face.cfg" and "yolov3-face.weights".
    Net net = readNetFromDarknet("yolov3-face.cfg", "yolov3-face.weights");
    if (net.empty())
    {
        cerr << "Error: Could not load YOLO network." << endl;
        return;
    }

    // YOLO typically resizes images to 416x416.
    Mat blob = blobFromImage(img, 1 / 255.0, Size(416, 416), Scalar(), true, false);
    net.setInput(blob);

    auto start = chrono::steady_clock::now();
    vector<Mat> outs;
    net.forward(outs, getOutputsNames(net));
    auto end = chrono::steady_clock::now();
    double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    float confThreshold = 0.5f;
    vector<Rect> boxes;
    vector<float> confidences;

    // Process each detection from each output layer.
    for (size_t i = 0; i < outs.size(); ++i)
    {
        float *data = (float *)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
        {
            // The first 4 elements: center_x, center_y, width, height; then objectness score and class scores.
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > confThreshold)
            {
                int centerX = (int)(data[0] * img.cols);
                int centerY = (int)(data[1] * img.rows);
                int width = (int)(data[2] * img.cols);
                int height = (int)(data[3] * img.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;
                boxes.push_back(Rect(left, top, width, height));
                confidences.push_back((float)confidence);
            }
        }
    }

    // (Optional) Apply Non-Maximum Suppression to remove overlapping boxes.
    vector<int> indices;
    NMSBoxes(boxes, confidences, confThreshold, 0.4, indices);

    int faceCount = 0;
    for (size_t i = 0; i < indices.size(); i++)
    {
        int idx = indices[i];
        rectangle(img, boxes[idx], Scalar(255, 0, 0), 3);
        faceCount++;
    }

    string label = to_string(faceCount) +
                   (faceCount == 1 ? " Face Detected" : " Faces Detected") +
                   " | " + to_string(detectionTime) + " ms";
    rectangle(img, Point(0, 0), Point(400, 50), Scalar(255, 0, 0), FILLED);
    putText(img, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 1);

    imshow("YOLO Picture", img);
    waitKey(0);
}

// 7. Process Webcam using YOLO for face detection.
void main7_yoloWebcam()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open webcam." << endl;
        return;
    }

    Net net = readNetFromDarknet("yolov3-face.cfg", "yolov3-face.weights");
    if (net.empty())
    {
        cerr << "Error: Could not load YOLO network." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cerr << "Error: Could not capture frame from webcam." << endl;
            break;
        }
        resizeToScreen(frame, 1280, 720);

        Mat blob = blobFromImage(frame, 1 / 255.0, Size(416, 416), Scalar(), true, false);
        net.setInput(blob);

        auto start = chrono::steady_clock::now();
        vector<Mat> outs;
        net.forward(outs, getOutputsNames(net));
        auto end = chrono::steady_clock::now();
        double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        float confThreshold = 0.5f;
        vector<Rect> boxes;
        vector<float> confidences;
        for (size_t i = 0; i < outs.size(); ++i)
        {
            float *data = (float *)outs[i].data;
            for (int j = 0; j < outs[i].rows; j++, data += outs[i].cols)
            {
                Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
                if (confidence > confThreshold)
                {
                    int centerX = (int)(data[0] * frame.cols);
                    int centerY = (int)(data[1] * frame.rows);
                    int width = (int)(data[2] * frame.cols);
                    int height = (int)(data[3] * frame.rows);
                    int left = centerX - width / 2;
                    int top = centerY - height / 2;
                    boxes.push_back(Rect(left, top, width, height));
                    confidences.push_back((float)confidence);
                }
            }
        }
        vector<int> indices;
        NMSBoxes(boxes, confidences, confThreshold, 0.4, indices);
        int faceCount = 0;
        for (size_t i = 0; i < indices.size(); i++)
        {
            int idx = indices[i];
            rectangle(frame, boxes[idx], Scalar(255, 0, 0), 3);
            faceCount++;
        }
        string label = to_string(faceCount) +
                       (faceCount == 1 ? " Face Detected" : " Faces Detected") +
                       " | " + to_string(detectionTime) + " ms";
        rectangle(frame, Point(0, 0), Point(400, 50), Scalar(255, 0, 0), FILLED);
        putText(frame, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 1);

        imshow("YOLO Webcam", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// 8. Process Video File using YOLO for face detection.
void main8_yoloVideo()
{
    string videoPath = "opencv_pool_vid\\MyVideo.mp4";
    VideoCapture cap(videoPath);
    if (!cap.isOpened())
    {
        cerr << "Error: Could not open video file " << videoPath << endl;
        return;
    }

    Net net = readNetFromDarknet("yolov3-face.cfg", "yolov3-face.weights");
    if (net.empty())
    {
        cerr << "Error: Could not load YOLO network." << endl;
        return;
    }

    Mat frame;
    while (true)
    {
        if (!cap.read(frame) || frame.empty())
        {
            cout << "Finished processing video or cannot read frame." << endl;
            break;
        }
        resizeToScreen(frame, 1280, 720);

        Mat blob = blobFromImage(frame, 1 / 255.0, Size(416, 416), Scalar(), true, false);
        net.setInput(blob);

        auto start = chrono::steady_clock::now();
        vector<Mat> outs;
        net.forward(outs, getOutputsNames(net));
        auto end = chrono::steady_clock::now();
        double detectionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        float confThreshold = 0.5f;
        vector<Rect> boxes;
        vector<float> confidences;
        for (size_t i = 0; i < outs.size(); ++i)
        {
            float *data = (float *)outs[i].data;
            for (int j = 0; j < outs[i].rows; j++, data += outs[i].cols)
            {
                Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
                if (confidence > confThreshold)
                {
                    int centerX = (int)(data[0] * frame.cols);
                    int centerY = (int)(data[1] * frame.rows);
                    int width = (int)(data[2] * frame.cols);
                    int height = (int)(data[3] * frame.rows);
                    int left = centerX - width / 2;
                    int top = centerY - height / 2;
                    boxes.push_back(Rect(left, top, width, height));
                    confidences.push_back((float)confidence);
                }
            }
        }
        vector<int> indices;
        NMSBoxes(boxes, confidences, confThreshold, 0.4, indices);
        int faceCount = 0;
        for (size_t i = 0; i < indices.size(); i++)
        {
            int idx = indices[i];
            rectangle(frame, boxes[idx], Scalar(255, 0, 0), 3);
            faceCount++;
        }
        string label = to_string(faceCount) +
                       (faceCount == 1 ? " Face Detected" : " Faces Detected") +
                       " | " + to_string(detectionTime) + " ms";
        rectangle(frame, Point(0, 0), Point(400, 50), Scalar(255, 0, 0), FILLED);
        putText(frame, label, Point(10, 40), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 1);

        imshow("YOLO Video", frame);
        if (waitKey(30) >= 0)
            break;
    }
}

// -------------------------------------------------------------------------
// Main Function: Select and run the desired scenario.
// -------------------------------------------------------------------------
int main()
{
    /*
    Choose the detection scenario by setting the 'scenario' variable:
      0 - Picture using Haar Cascade.
      1 - Webcam using Haar Cascade.
      2 - Video file using Haar Cascade.
      3 - Picture using Deep Learning (Caffe) face detector.
      4 - Webcam using Deep Learning.
      5 - Video file using Deep Learning.
      6 - Picture using YOLO.
      7 - Webcam using YOLO.
      8 - Video file using YOLO.
    */
    int scenario = 8; // Change this value (from 0 to 8) to test different detectors.

    switch (scenario)
    {
    case 0:
        main0_haarPicture();
        break;
    case 1:
        main1_haarWebcam();
        break;
    case 2:
        main2_haarVideo();
        break;
    case 3:
        main3_deepFacePicture();
        break;
    case 4:
        main4_deepFaceWebcam();
        break;
    case 5:
        main5_deepFaceVideo();
        break;
    case 6:
        main6_yoloPicture();
        break;
    case 7:
        main7_yoloWebcam();
        break;
    case 8:
        main8_yoloVideo();
        break;
    default:
        cout << "Invalid scenario selected." << endl;
        return -1;
    }

    return 0;
}
