#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <NumCpp.hpp>
#include "OpenLego.hpp"


int main()
{

    std::cout<<"Lego Generator in C++"<<std::endl;

    std::cout<<"=======BEGIN======="<<std::endl;

    auto brick = cv::imread("data/1x1.png", cv::IMREAD_COLOR);
    if(brick.empty()){
        std::cout<<"read element file failed"<<std::endl;
        return -1;
    }
    
    auto src = cv::imread("data/input.jpg", cv::IMREAD_COLOR);
    if(src.empty()){
        std::cout<<"read data file failed"<<std::endl;
        return -1;
    }

    std::cout<<"=======image readed======="<<std::endl;

    Legofy lego = Legofy();
    cv::Mat legofied = lego.lego(brick, src);

    std::cout<<"=======LEGOFY FINISHED======="<<std::endl;


    cv::imwrite("data/output.jpg", legofied);

    std::cout<<"=======FINISHED======="<<std::endl;

    return 0;
}