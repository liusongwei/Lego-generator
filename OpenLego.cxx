#include "OpenLego.hpp"

#include<iostream>
using namespace cv;
using namespace std;


Mat Legofy::lego(Mat brick, Mat src){

    float overlay_ratio = 0.2;
        int stride = 15;

        cout<<"brick channels:"<<brick.channels()<<endl;

        cv::Size brickSize = cv::Size(stride, stride);
        Mat toBrick,toBrick2, toSub2;

        // Mat threeChannels = Mat::zeros(brick.rows, brick.cols, CV_8UC3);
        // vector<Mat> channels;
        // for(int i=0; i<2; i++){
        //     channels.push_back(brick);
        // }
        // merge(channels, threeChannels);

        cv::resize(brick, toBrick, brickSize);

        Mat toSub = Mat(stride, stride, CV_8UC3, cv::Scalar(133, 133, 133));
        toBrick.convertTo(toBrick2, CV_32FC3);
        toSub.convertTo(toSub2, CV_32FC3);

        Mat toProcess;
        int imgW = src.cols;
        int imgH = src.rows;
        cv::Size toProcessSize = cv::Size(ceil(imgW/stride) * stride, ceil(imgH/stride) * stride);

        cv::resize(src, toProcess, toProcessSize);
        int height = toProcess.rows;
        int width = toProcess.cols;
        int channel = toProcess.channels();

        auto blank_mat = cv::Mat(src.rows, src.cols, CV_32FC3);

        for(int i = 0; i < width/stride; i++){
            for(int j = 0; j < height/stride; j++){

                cv::Rect rect = cv::Rect(i*stride, j*stride, stride, stride);
                Mat partial_image = toProcess(rect);

                auto avg_color = cv::mean(partial_image);
                cout<<"avg_color:"<<avg_color<<endl;

                auto blank_rect = cv::Rect(i*stride, j*stride, stride, stride);

                auto brickRect = cv::Rect(0,0, stride, stride);
            
                auto colored = avg_color + toBrick2 - toSub2;
              
                blank_mat(blank_rect) = colored(brickRect);
            
            }
        }

        return blank_mat;
}
