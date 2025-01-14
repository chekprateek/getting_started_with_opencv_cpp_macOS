#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the pre-trained Haar Cascade for face detection
    CascadeClassifier face_cascade;
    if (!face_cascade.load("/opt/homebrew/opt/opencv/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")) {
        cerr << "Error loading face cascade" << endl;
        return -1;
    }

    // Open webcam
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error opening video stream" << endl;
        return -1;
    }

    Mat frame, gray;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // Convert to grayscale for face detection
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));

        // Draw green rectangles around faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);  // Green color (0, 255, 0) for bounding box
        }

        // Show the processed frame
        imshow("Face Detection", frame);

        // Exit on 'q' key press
        if (waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
