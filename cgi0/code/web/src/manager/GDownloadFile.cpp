//===============================================
#include "GDownloadFile.h"
#include "GManager.h"
//===============================================
GDownloadFile::GDownloadFile() {
    m_tmpImgFile = GManager::Instance()->getFilePath("tmp", "tmp_img_file.jpg");
    m_tmpImgFile.remove(0, 1);
}
//===============================================
GDownloadFile::~GDownloadFile() {
    
}
//===============================================
// method
//===============================================
void GDownloadFile::print() {
    const char* lUrl = "/index.cgi?page_id=image&image_run=download_image";
    printf("<div class='body'>\n");
    printf("<div class='box center'>\n");
    printf("<div><img class='img2 bottom' src='%s'/></div>\n", lUrl);
    printf("<div><a class='button3'href='%s' download='readycgi_opencv_image.jpg'><i class='fa fa-download'></i> Télécharger</a><div>\n", lUrl);
    printf("</div>\n");
    printf("</div>\n");
}
//===============================================
