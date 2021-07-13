#ifndef __OPENLEGO_HPP__
#define __OPENLEGO_HPP__

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>


class Legofy{

public:
    Legofy(){};
    ~Legofy(){};

    cv::Mat lego(cv::Mat brick, cv::Mat src);
};

#endif