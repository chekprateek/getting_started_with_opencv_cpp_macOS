#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default webcam (ID 0)
    cv::VideoCapture cap(0);
    
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open webcam!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    
    while (true) {
        // Capture frame-by-frame
        cap >> frame;
        
        // If the frame is empty, break the loop
        if (frame.empty()) {
            std::cerr << "Error: Blank frame received!" << std::endl;
            break;
        }

        // Display the resulting frame in a window
        cv::imshow("Webcam Stream", frame);

        // Wait for 1ms and check if the 'Q' key was pressed to close the window
        char key = cv::waitKey(1);
        if (key == 'q' || key == 'Q') {
            break;
        }
    }

    // Release the video capture object and close all windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
