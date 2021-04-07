//===============================================
#include "GPdf.h"
#include "GManager.h"
//===============================================
GPdf* GPdf::m_instance = 0;
//===============================================
GPdf::GPdf() {

}
//===============================================
GPdf::~GPdf() {
    
}
//===============================================
GPdf* GPdf::Instance() {
    if(m_instance == 0) {
        m_instance = new GPdf;
    }
    return m_instance;
}
//===============================================
void GPdf::generate() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString html = 
    "<div align=right>" 
        "City, 11/11/2015" 
    "</div>" 
    "<div align=left>" 
        "Sender Name<br>" 
        "street 34/56A<br>" 
        "121-43 city" 
    "</div>" 
    "<h1 align=center>DOCUMENT TITLE</h1>" 
    "<p align=justify>" 
        "document content document content document content document content document content document content document content document content document content document content " 
        "document content document content document content document content document content document content document content document content document content document content " 
    "</p>" 
    "<div align=right>sincerly</div>"; 

QTextBrowser *tb = new QTextBrowser;
tb->setOpenExternalLinks(true);
tb->setHtml(html);
tb->show();

    QTextDocument document; 
    document.setHtml(html); 

    QPrinter printer(QPrinter::PrinterResolution); 
    printer.setOutputFormat(QPrinter::PdfFormat); 
    printer.setPaperSize(QPrinter::A4); 
    printer.setOutputFileName(lApp->pdf_path); 
    printer.setPageMargins(QMarginsF(15, 15, 15, 15)); 

    document.print(&printer);
}
//===============================================
