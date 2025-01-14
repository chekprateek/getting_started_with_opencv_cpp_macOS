#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
    // Step 1: Open the webcam (use 0 for the default webcam)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open webcam!" << std::endl;
        return -1;
    }

    // Step 2: Set up the window name for the combined image
    const std::string combined_window = "Webcam Stream: Y, Cb, Cr Channels";

    // Step 3: Start streaming the webcam
    while (true) {
        cv::Mat frame;
        cap >> frame; // Capture a frame from the webcam

        if (frame.empty()) {
            std::cerr << "Error: Could not grab frame!" << std::endl;
            break;
        }

        // Step 4: Convert the frame to YCbCr color space
        cv::Mat ycbcr_frame;
        cv::cvtColor(frame, ycbcr_frame, cv::COLOR_BGR2YCrCb);

        // Step 5: Split the Y, Cb, Cr channels
        std::vector<cv::Mat> channels(3);
        cv::split(ycbcr_frame, channels); // Split into Y, Cb, Cr channels

        // Step 6: Resize each image to ensure they're the same size (optional)
        cv::Mat resized_frame, resized_y, resized_cb, resized_cr;
        
        cv::resize(frame, resized_frame, cv::Size(320, 240)); // Resize original frame
        cv::resize(channels[0], resized_y, cv::Size(320, 240));  // Y channel
        cv::resize(channels[1], resized_cb, cv::Size(320, 240)); // Cb channel
        cv::resize(channels[2], resized_cr, cv::Size(320, 240)); // Cr channel

        // Step 7: Convert single-channel images to 3 channels for better visualization
        cv::Mat y_color, cb_color, cr_color;
        cv::cvtColor(resized_y, y_color, cv::COLOR_GRAY2BGR);
        cv::cvtColor(resized_cb, cb_color, cv::COLOR_GRAY2BGR);
        cv::cvtColor(resized_cr, cr_color, cv::COLOR_GRAY2BGR);

        // Step 8: Add text overlays for each section
        cv::putText(resized_frame, "RGB", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
        cv::putText(y_color, "Y-Channel", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
        cv::putText(cb_color, "Cb-Channel", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
        cv::putText(cr_color, "Cr-Channel", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);

        // Step 9: Concatenate images horizontally
        cv::Mat top_row, bottom_row, combined_image;
        
        // Concatenate original frame and Y, Cb channels horizontally
        cv::hconcat(resized_frame, y_color, top_row); // Original + Y
        cv::hconcat(cb_color, cr_color, bottom_row); // Cb + Cr

        // Concatenate top and bottom rows vertically
        cv::vconcat(top_row, bottom_row, combined_image);

        // Step 10: Display the combined image in a single window
        cv::imshow(combined_window, combined_image);

        // Step 11: Check if 'q' is pressed to exit
        char key = cv::waitKey(1);
        if (key == 'q' || key == 27) { // 'q' or 'ESC' to exit
            break;
        }
    }

    // Step 12: Release the webcam and close the window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
