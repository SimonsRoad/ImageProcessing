//
// Created by smher on 18-1-11.
//

#ifndef RDLW_SAL_FUSION_FUSION_H
#define RDLW_SAL_FUSION_FUSION_H

#include "headers.h"
#include "RDL_Wavelet.h"
#include "WeightedMap.h"

class Fusion
{
public:
    Fusion() = default;
    Fusion(int r, int c);
    // delete the copy construct function
    Fusion(Fusion& a) = delete;
    // delete the copy function
    Fusion& operator= (const Fusion& f) = delete;
    ~Fusion();

    void imageFusion(cv::Mat& imgOut, const cv::Mat& imgInA, const cv::Mat& imgInB);
    void imageFusionColor(cv::Mat& imgOut, const cv::Mat& imgInA, const cv::Mat& imgInB);
private:
    std::shared_ptr<RDLWavelet> rdlPimpl;
    std::shared_ptr<WeightedMap> wmPimpl;
};

#endif //RDLW_SAL_FUSION_FUSION_H
