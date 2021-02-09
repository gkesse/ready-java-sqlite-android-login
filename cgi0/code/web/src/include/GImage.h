//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
//===============================================
class GImage {
private:
    GImage();
    
public:
    virtual ~GImage();
    static GImage* Instance();
    void run(int argc, char** argv);
    void run(QString action);
    void printImg(const cv::Mat& img);
    void saveImg(const cv::Mat& img);
    void printSave(const cv::Mat& img);
    
private:
    static GImage* m_instance;
    QString m_tmpImgFile;
};
//===============================================
#endif
//===============================================
