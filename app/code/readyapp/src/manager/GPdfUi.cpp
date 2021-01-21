//===============================================
#include "GPdfUi.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GPdfUi::GPdfUi(QWidget* parent) : GWidget(parent) {
    setObjectName("GPdfUi");
    
    QPushButton* lEdit = new QPushButton;
    lEdit->setObjectName("edit");
    lEdit->setText("Editer");
    lEdit->setCursor(Qt::PointingHandCursor);
    m_widgetId[lEdit] = "edit";
    
    QPushButton* lPreview = new QPushButton;
    lPreview->setObjectName("preview");
    lPreview->setText("Visualiser");
    lPreview->setCursor(Qt::PointingHandCursor);
    m_widgetId[lPreview] = "preview";
    
    QPushButton* lTitle = new QPushButton;
    m_title = lTitle;
    lTitle->setObjectName("title");
    m_widgetId[lTitle] = "title";
    
    QHBoxLayout* lActionLatout = new QHBoxLayout;
    lActionLatout->addWidget(lEdit);
    lActionLatout->addWidget(lPreview);
    lActionLatout->addWidget(lTitle, 1);
    lActionLatout->setAlignment(Qt::AlignLeft);
    lActionLatout->setMargin(0);
    lActionLatout->setSpacing(10);

    QTextEdit* lTextEdit = new QTextEdit;
    m_textEdit = lTextEdit;
    
    QTextBrowser* lTextBrowser = new QTextBrowser;
    m_textBrowser = lTextBrowser;
    lTextBrowser->setOpenExternalLinks(true);

    QStackedWidget* lPageMap = new QStackedWidget;
    m_pageMap = lPageMap;
    
    addPage("edit", "Editeur", lTextEdit, 1);
    addPage("preview", "Aperçu", lTextBrowser);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addLayout(lActionLatout);
    lMainLatout->addWidget(lPageMap, 1);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(10);
    
    setLayout(lMainLatout);
    
    lTextEdit->setPlainText(GManager::Instance()->loadData("pdf_text"));
    
    connect(lEdit, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lPreview, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GPdfUi::~GPdfUi() {
    
}
//===============================================
// methods
//===============================================
void GPdfUi::addPage(QString key, QString title, QWidget* widget, bool isDefault) {
    int lWidgetId = m_pageMap->count();
    m_pageId[key] = lWidgetId;
    m_titleMap[key] = title;
    m_pageMap->addWidget(widget);
    if(isDefault == 1) {
        m_pageMap->setCurrentIndex(lWidgetId);
        m_title->setText(title);
    }
}
//===============================================
// slot
//===============================================
void GPdfUi::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    int lPageId = m_pageId[lWidgetId];
    QString lTitle = m_titleMap[lWidgetId];
    m_pageMap->setCurrentIndex(lPageId);
    m_title->setText(lTitle);
    
    if(lWidgetId == "preview") {
        QString lText = m_textEdit->toPlainText();
        if(lText != "") {
            m_textBrowser->setHtml(lText);
            GManager::Instance()->saveData("pdf_text", lText);
        }
    }
}
//===============================================
