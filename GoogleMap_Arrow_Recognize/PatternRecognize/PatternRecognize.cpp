// PatternRecognize.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include <bitset>
#include <windows.h>
#include <iostream>
#include <limits>

std::vector<std::string>  getAllFilesNamesWithinFolder(std::string folder)
{
	std::vector<std::string> names;
	std::string search_path = folder + "/*.*";
	WIN32_FIND_DATAA fd;

	HANDLE hFind = ::FindFirstFileA(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFileA(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}

std::string lowerCase(std::string input) {
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
		*it = tolower(*it);
	return input;
}

std::vector<std::string> getAllImageFileNamesWithinFolder(std::string folder)
{
	using namespace std;
	auto files = getAllFilesNamesWithinFolder(folder);
	vector<std::string> result;

	for (auto file : files)
	{
		auto lower = lowerCase(file);

		if (string::npos != lower.rfind(".bmp") || string::npos != lower.rfind(".png") || string::npos != lower.rfind(".jpg") || string::npos != lower.rfind(".jpeg"))
		{
			//cout << file << endl;
			result.push_back(file);
		}

	}
	return result;
}

#define IMAGE_LENGTH 8 //比5小, 這個方法就分不出來了
class Image {
public:
	bool left_up_content[IMAGE_LENGTH*IMAGE_LENGTH];
	bool right_dw_content[IMAGE_LENGTH*IMAGE_LENGTH];
	unsigned long long  left_up_mask = 0;
	unsigned long long  right_dw_mask = 0;
	cv::Mat binary_image;
	cv::Mat resized_image;
	Image() {

	}
};

unsigned long get_SAD(Image img0, Image img1) {
	unsigned long sad = 0;
	for (int x = 0; x < IMAGE_LENGTH*IMAGE_LENGTH; x++) {
		sad += (img0.left_up_content[x] != img1.left_up_content[x]) ? 1 : 0;
	}
	return sad;
}

void to_binary_image(cv::Mat image) {
	int height = image.rows;
	int width = image.cols;

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			auto& pixel = image.at<cv::Vec3b>(w, h);
			if (pixel[1] == 255) {
				pixel[2] = pixel[1] = pixel[0] = 255;
			}
			else {
				pixel[2] = pixel[1] = pixel[0] = 0;
			}

			int a = 1;
		}
	}

}

cv::Mat resizeWithNN(cv::Mat source, cv::Size new_size) {
	if (new_size.height == source.rows && new_size.width == source.cols) {
		return source;
	}
	cv::Mat resized(new_size, CV_8UC3);
	float ratio = source.rows / (new_size.height*1.0f);

	for (int h = 0; h < resized.rows; h++) {
		int h0 = (int)round(h * ratio);
		h0 = (h0 >= source.rows) ? source.rows - 1 : h0;
		for (int w = 0; w < resized.cols; w++) {
			int w0 = (int)round(w * ratio);
			w0 = (w0 >= source.cols) ? source.cols - 1 : w0;
			auto &resized_pixel = resized.at<cv::Vec3b>(h, w);
			auto &source_pixel = source.at<cv::Vec3b>(h0, w0);
			for (int ch = 0; ch < 3; ch++) {
				resized_pixel[ch] = source_pixel[ch];
			}
		}
	}
	return resized;
}

Image to_Image(cv::Mat cv_image) {

	Image image;
	if (cv_image.rows != cv_image.cols) {
		return image;
	}
	
	//1. to binary image
	to_binary_image(cv_image);

	//2. resize to 132x132
	cv::Size new_size(132, 132);
	cv::Mat resized_image = resizeWithNN(cv_image, new_size);

	const int img_size = resized_image.rows;
	int interval = resized_image.rows / IMAGE_LENGTH;

	//3. resize to 8x8
	unsigned long long  mask_lu = 0;
	unsigned long long  mask_rd = 0;
	int index = 0;
	int total_length = IMAGE_LENGTH * IMAGE_LENGTH;

	for (int h0 = 0; h0 < IMAGE_LENGTH; h0++) {
		const int h_lu = h0 * interval;
		const int h_rd = img_size - 1 - h_lu;
		for (int w0 = 0; w0 < IMAGE_LENGTH; w0++) {
			const int w_lu = w0 * interval;
			const int w_rd = img_size - 1 - w_lu;

			auto&  pixel_lu = resized_image.at<cv::Vec3b>(h_lu, w_lu);
			const bool bool_lu = 255 == pixel_lu[1];
			image.left_up_content[h0*IMAGE_LENGTH + w0] = bool_lu;
			unsigned long long shift_lu = ((unsigned long long)(bool_lu ? 1L : 0L)) << index;
			if ((index + 1) == total_length) {
				shift_lu = 0;
			}
			mask_lu += shift_lu;

			auto&  pixel_rd = resized_image.at<cv::Vec3b>(h_rd, w_rd);
			const bool bool_rd = 255 == pixel_rd[1];
			image.right_dw_content[h0*IMAGE_LENGTH + w0] = bool_rd;
			unsigned long long shift_rd = ((unsigned long long)(bool_rd ? 1L : 0L)) << index;
			if ((index + 1) == total_length) {
				shift_rd = 0;
			}
			mask_rd += shift_rd;

			index++;

		}
	}
	image.left_up_mask = mask_lu;
	image.right_dw_mask = mask_rd;
	image.binary_image = cv_image;
	image.resized_image = resized_image;
	return image;

}

cv::Mat to_cv_image(Image image) {
	cv::Mat cv_image(IMAGE_LENGTH, IMAGE_LENGTH, CV_8UC3);

	auto content = image.left_up_content;
	for (int h = 0; h < IMAGE_LENGTH; h++) {
		for (int w = 0; w < IMAGE_LENGTH; w++) {
			int index = h * IMAGE_LENGTH + w;
			auto b = content[index];
			auto& pixel = cv_image.at<cv::Vec3b>(h, w);
			pixel[2] = pixel[1] = pixel[0] = (b ? 255 : 0);
		}
	}
		return cv_image;
}


int recognize()
{
	using namespace cv;
	using namespace std;
	vector<Mat> image_vec;
	string dir = "./Google_Arrow2/";

	vector<Image> image_vector;
	//int bit_of_image = IMAGE_LENGTH * IMAGE_LENGTH;


	for (auto& filename : getAllImageFileNamesWithinFolder(dir)) {
		auto cv_img = cv::imread(dir + filename);
		Image img = to_Image(cv_img);
		auto small_img = to_cv_image(img);
		cv::imwrite(filename, small_img);

		unsigned long long mask = img.left_up_mask;
		//std::bitset<64> binary_lu(img.left_up_mask);
		//cout << img.left_up_mask << " " << binary_lu << " " << filename << endl;
		cout << img.left_up_mask << " \t " << img.right_dw_mask << " \t " << filename << endl;
		image_vector.push_back(img);

	}
	cout << endl;

	for (auto img1 : image_vector) {
		int sad_zero_count = 0;
		for (auto img2 : image_vector) {
			unsigned long sad = get_SAD(img1, img2);
			cout << std::hex << sad << " ";
			if (0 == sad) {
				sad_zero_count++;
			}
		}
		if (sad_zero_count != 1) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}


int main() {

	if (false) {
		using namespace cv;
		using namespace std;
		vector<Mat> image_vec;
		string dir = "./Google_Arrow2/";


		Size size(IMAGE_LENGTH, IMAGE_LENGTH);
		Image img1 = to_Image(cv::imread(dir + "LeaveRoundaboutAsUturnCC.png"));

		for (auto& filename : getAllImageFileNamesWithinFolder(dir)) {
			//cout << filename << endl;
			auto& cv_img = cv::imread(dir + filename);
			Image img2 = to_Image(cv_img);
			unsigned long sad = get_SAD(img1, img2);
			cout << filename << " sad: " << sad << endl;
		}
	}

	if (true) {
		recognize();
	}
}