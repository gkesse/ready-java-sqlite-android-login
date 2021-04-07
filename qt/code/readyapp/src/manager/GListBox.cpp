//===============================================
#include "GListBox.h"
#include "GManager.h"
//===============================================
GListBox::GListBox(QWidget* parent) : GWidget(parent) {
    setObjectName("GListBox");
    
    QVBoxLayout* lScrollLayout = new QVBoxLayout;
    m_scrollLayout = lScrollLayout;
    lScrollLayout->setAlignment(Qt::AlignTop);
    lScrollLayout->setMargin(0);
    lScrollLayout->setSpacing(0);

    QFrame* lScrollWidget = new QFrame;
    lScrollWidget->setLayout(lScrollLayout);

    QScrollArea* lScrollArea = new QScrollArea;
    lScrollArea->setWidget(lScrollWidget);
    lScrollArea->setWidgetResizable(true);

    m_index = 0;

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lScrollArea);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
}
//===============================================
GListBox::~GListBox() {
    
}
//===============================================
// method
//===============================================
void GListBox::addItem(QString key, QString text) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QPushButton* lButton = new QPushButton;
    lApp->widget = lButton;
    lButton->setObjectName("item");
    lButton->setText(text);
    lButton->setCursor(Qt::PointingHandCursor);
    m_scrollLayout->addWidget(lButton);
    m_widgetId[lButton] = key;
    m_rowId[m_index++] = lButton;
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListBox::addItem(QString key, QString text, int icon) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QPushButton* lButton = new QPushButton;
    lApp->widget = lButton;
    lButton->setObjectName("item");
    lButton->setText(text);
    lButton->setIcon(GManager::Instance()->loadPicto(icon, lApp->picto_color));
    lButton->setCursor(Qt::PointingHandCursor);
    m_scrollLayout->addWidget(lButton);
    m_widgetId[lButton] = key;
    m_rowId[m_index++] = lButton;
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListBox::addItem(QLayout* layout) {
    QHBoxLayout* lRowLayout = new QHBoxLayout;
    lRowLayout->addLayout(layout);
    lRowLayout->setMargin(0);
    lRowLayout->setSpacing(0);

    QFrame* lRow = new QFrame;
    lRow->setObjectName("item");
    lRow->setLayout(lRowLayout);
    m_rowId[m_index++] = lRow;

    m_scrollLayout->addWidget(lRow);
}
//===============================================
void GListBox::removeItem(int index) {
    QWidget* lWidget = m_rowId[index];
    m_scrollLayout->removeWidget(lWidget);
    delete lWidget;
}
//===============================================
void GListBox::clearContent() {
    GManager::Instance()->clearLayout(m_scrollLayout);
}
//===============================================
// slot
//===============================================
void GListBox::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================