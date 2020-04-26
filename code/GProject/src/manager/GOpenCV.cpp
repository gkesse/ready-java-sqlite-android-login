//===============================================
#include "GOpenCV.h"
#include "GDir.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_OPENCV_ON_)
//===============================================
GOpenCV* GOpenCV::m_instance = 0;
//===============================================
GOpenCV::GOpenCV() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GOpenCV::~GOpenCV() {

}
//===============================================
GOpenCV* GOpenCV::Instance() {
	if(m_instance == 0) {
		m_instance = new GOpenCV;
	}
	return m_instance;
}
//===============================================
void GOpenCV::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	string lDataPath = GDir::Instance()->dataPath();
	string lFilename = lDataPath + "/data/img/fruits.jpg";
	cout << lFilename;
	cv::Mat lImg = cv::imread(lFilename,-1);
	if(lImg.empty()) return;
	cv::namedWindow("OpenCV | ReadyDev", cv::WINDOW_AUTOSIZE);
	cv::imshow("OpenCV | ReadyDev", lImg);
	cv::waitKey(0);
	cv::destroyAllWindows();
}
//===============================================
#endif
//===============================================
