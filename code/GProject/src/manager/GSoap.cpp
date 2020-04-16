//===============================================
#include "GSoap.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_GSOAP_ON_)
//===============================================
GSoap* GSoap::m_instance = 0;
//===============================================
GSoap::GSoap() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GSoap::~GSoap() {

}
//===============================================
GSoap* GSoap::Instance() {
	if(m_instance == 0) {
		m_instance = new GSoap;
	}
	return m_instance;
}
//===============================================
void GSoap::test(int argc, char** argv) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
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
//================================================
#endif
//===============================================
