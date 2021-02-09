//===============================================
#include "GSelectFile.h"
#include "GManager.h"
//===============================================
GSelectFile::GSelectFile() {
    m_files = GManager::Instance()->getFileList("img");
    m_path = GManager::Instance()->getFilePath("img");
    m_total = m_files.size();
    m_page = 1;
    m_colMax = 32;
}
//===============================================
GSelectFile::~GSelectFile() {
    
}
//===============================================
// method
//===============================================
void GSelectFile::print() {
    request();
    int lPageMax = (int)ceil((double)m_total/m_colMax);
    printf("<div class='body2 center'>\n");
    printf("<div class='header2'>\n");
    //
    printf("<div class='item4'>\n");
    printf("<label class=''>Total : </label>\n");
    printf("<label class='' >%d</label>\n", m_total);
    printf("</div>\n");
    //
    printf("<form id='select_file_page_form' class='item4' action='' method='post'>\n");
    printf("<label class='' for='number'>Page : </label>\n");
    printf("<input type='hidden' id='req' name='req' value='open_image'/>\n");
    printf("<input type='hidden' id='action' name='action' value='send_page'/>\n");
    printf("<input class='' type='number' id='page' name='page' min='1' max='%d' value='%d' size='3' \
    onchange='onItemClick(this, \"select_file_page_change\")'/>\n", lPageMax, m_page);
    printf("<label class=''> / </label>\n");
    printf("<label class=''>%d</label>\n", lPageMax);
    printf("</form>\n");
    //
    printf("</div>\n");
    printf("<div class=''>\n");
    for(int i = 0; i < m_colMax; i++) {
        int lIndex = (m_page - 1)*m_colMax + i;
        if(lIndex >= m_total) {break;}
        QString lFilename = m_files[i];
        QString lFilePath = m_path + "/" + lFilename;
        QString lFullname = m_path + "/" + lFilename;
        lFilePath.remove(0, 1);
        printf("<form action='' method='post'>\n");
        printf("<input type='hidden' id='filename' name='filename' value='%s'/>\n",
        lFullname.toStdString().c_str());
        printf("<input type='hidden' id='req' name='req' value='open_image'/>\n");
        printf("<button type='submit' id='action' name='action' value='select_file'>\
        <img class='img' src='%s' title='%s'/></button>\n", 
        lFilePath.toStdString().c_str(), lFilename.toStdString().c_str());
        printf("</form>\n");
    }
    printf("</div>\n");
    printf("</div>\n");
}
//===============================================
void GSelectFile::setCookies() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->action == "select_file") {
        QString lFilename = GManager::Instance()->getPost("filename");
        GManager::Instance()->setCookie("image_file", lFilename);
        GManager::Instance()->setCookie("opencv_state", "open_image");
    }    
}
//===============================================
void GSelectFile::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->action == "send_page") {
        m_page = GManager::Instance()->getPost("page").toInt();
    }
    else if(lApp->action == "select_file") {
        GManager::Instance()->redirect("/home/opencv");
    }
}
//===============================================
