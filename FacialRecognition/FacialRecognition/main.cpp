#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <chrono>
#include <fstream>


using namespace std;
using namespace cv;

void Shoot();

char PORT[] = "COM3";

int main() {


	VideoCapture Video(0);
	CascadeClassifier faceDetect;
	faceDetect.load("haarcascade_frontalface_default.xml");

	Mat img;

	while (true) {
		Video.read(img);

		vector<Rect> faces;

		faceDetect.detectMultiScale(img, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);

			cout << "Coords of face: " << i << "(x: " << faces[i].x << " y: " << faces[i].y << ")" << endl;
		}

		imshow("Video Output", img);
		waitKey(1);
	}
}


void Shoot() {

}