#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
cv::VideoCapture g_cap;
void onTrackbarSlide(int pos, void*) {
g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
if (!g_dontset)
g_run = 1;
g_dontset = 0;
}
int main() {
std::string file = "C:/Users/ahoiz/Videos/Loki-TVA.mp4";
cv::namedWindow("Loki", cv::WINDOW_AUTOSIZE);
g_cap.open(file);
int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
std::cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << std::endl;
cv::createTrackbar("Position", "Loki", &g_slider_position, frames, onTrackbarSlide);
cv::Mat frame;
int frameCount = 0;
std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
for (;;) {
if (g_run != 0) {
g_cap >> frame; if (frame.empty()) break;
int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
g_dontset = 1;
cv::setTrackbarPos("Position", "Loki", current_pos);
// Calculate FPS
frameCount++;
std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
float elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(endTime - startTime).count();
float fps = frameCount / elapsedSeconds;
// Display FPS
std::stringstream ss;
ss << "FPS: " << std::fixed << std::setprecision(2) << fps;
cv::putText(frame, ss.str(), cv::Point(frame.cols - 230, 40), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
cv::imshow("Loki", frame);
g_run -= 1;
}
char c = (char)cv::waitKey(10);
if (c == 's') // single step
{
g_run = 1; std::cout << "Single step, run = " << g_run << std::endl;
}
if (c == 'r') // run mode
{
g_run = -1; std::cout << "Run mode, run = " << g_run << std::endl;
}
if (c == 27)
break;
}
return 0;
}