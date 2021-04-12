//===============================================
#include "GTableWidget.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//==============================================
const QString G_DAYS_OF_WEEK[] = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"};
const QString G_MONTHS_OF_YEAR[] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
//===============================================
GTableWidget::GTableWidget(QWidget* parent) : GWidget(parent) {
    setObjectName("GTableWidget");
    
    sGApp* lApp = GManager::Instance()->getData()->app;

    int lRowCount = 5;
    int lColCount = 7;
    
    m_rowCount = lRowCount;
    m_colCount = lColCount;
    
    QDate lCurrentDate = QDate::currentDate();
    int lCurrentMonth = lCurrentDate.month();
    int lCurrentYear = lCurrentDate.year();
    QDate lDate = QDate(lCurrentYear, lCurrentMonth, 1);
    m_currentDate = lDate;
    QString lMonthName = G_MONTHS_OF_YEAR[lCurrentMonth - 1];
    QString lMonthText = QString("%1 %2").arg(lMonthName).arg(lCurrentYear);
    int lWeekNumber = lDate.weekNumber();

    QPushButton* lPreviousMonth = new QPushButton;
    lPreviousMonth->setObjectName("arrow");
    lPreviousMonth->setIcon(GManager::Instance()->loadPicto(fa::chevronleft, lApp->picto_color));
    lPreviousMonth->setCursor(Qt::PointingHandCursor);
    m_widgetId[lPreviousMonth] = "previous_month";
    
    QPushButton* lNextMonth = new QPushButton;
    lNextMonth->setObjectName("arrow");
    lNextMonth->setIcon(GManager::Instance()->loadPicto(fa::chevronright, lApp->picto_color));
    lNextMonth->setCursor(Qt::PointingHandCursor);
    m_widgetId[lNextMonth] = "next_month";
    
    QLabel* lMonthLabel = new QLabel;
    m_monthLabel = lMonthLabel;
    lMonthLabel->setObjectName("month");
    lMonthLabel->setText(lMonthText);
    lMonthLabel->setAlignment(Qt::AlignCenter);
    
    QHBoxLayout* lMonthLayout = new QHBoxLayout;
    lMonthLayout->addWidget(lPreviousMonth);
    lMonthLayout->addWidget(lMonthLabel, 1);
    lMonthLayout->addWidget(lNextMonth);
    lMonthLayout->setMargin(0);
    lMonthLayout->setSpacing(0);
    
    QFrame* lMonthFrame = new QFrame;
    lMonthFrame->setObjectName("title");
    lMonthFrame->setLayout(lMonthLayout);
    
    QTableWidget* lTableWidget = new QTableWidget;
    m_tableWidget = lTableWidget;
    lTableWidget->setObjectName("table");
    QLabel* lCorner = new QLabel("Sem", lTableWidget);
    lCorner->setObjectName("corner");
    lCorner->move(5, 5);
    lTableWidget->setRowCount(lRowCount);
    lTableWidget->setColumnCount(lColCount);
    lTableWidget->setAlternatingRowColors(true);
    
    QStringList lHorizontalLabels;
    for(int i = 0; i < 7; i++) {
        lHorizontalLabels << G_DAYS_OF_WEEK[i];
    }
    
    QStringList lVerticalLabels;
    int lWeekCount = lWeekNumber;
    for(int i = 0; i < 5; i++) {
        if(lWeekCount > 53) {lWeekCount = 1;}
        lVerticalLabels << QString("%1").arg(lWeekCount);
        lWeekCount++;
    }
    
    lTableWidget->setHorizontalHeaderLabels(lHorizontalLabels);
    lTableWidget->setVerticalHeaderLabels(lVerticalLabels);
    lTableWidget->resizeColumnsToContents();
    lTableWidget->resizeRowsToContents();
    lTableWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    lTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    lTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    lTableWidget->setCursor(Qt::PointingHandCursor);
    
    int lWidth = lTableWidget->verticalHeader()->sizeHint().width();
    for(int i = 0; i < lTableWidget->columnCount(); i++) {
        lWidth += lTableWidget->horizontalHeader()->sectionSize(i);
    }
    lTableWidget->setMinimumWidth(lWidth);

    int lHeight = lTableWidget->verticalHeader()->sizeHint().height();
    for(int i = 0; i < lTableWidget->rowCount(); i++) {
        lHeight += lTableWidget->verticalHeader()->sectionSize(i);
    }
    lTableWidget->setMinimumHeight(lHeight);

    int lDayOfWeek = lDate.dayOfWeek();
    int lDaysInMonth = lDate.daysInMonth();
        
    int lDayCount = 1;
    int lLastDay = lDaysInMonth;
    int lFirstDay = lDayOfWeek - 1;
    
    lDayCount = lDayCount - lFirstDay;
    
    for(int i = 0; i < lRowCount; i++) {
        for(int j = 0; j < lColCount; j++) {
            QTableWidgetItem* lItem = new QTableWidgetItem();
            if(lDayCount >= 1 && lDayCount <= lLastDay) {
                QString lData = QString("%1").arg(lDayCount);
                lItem->setData(Qt::DisplayRole, lData);
            }
            lItem->setFlags(lItem->flags() ^ Qt::ItemIsEditable);
            lTableWidget->setItem(i, j, lItem);
            lDayCount++;
        }
    }
    
    lMonthFrame->setMaximumWidth(lWidth);

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lMonthFrame);
    lMainLayout->addWidget(lTableWidget);
    lMainLayout->setAlignment(Qt::AlignCenter);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
        
    setLayout(lMainLayout);
    
    connect(lPreviousMonth, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lNextMonth, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GTableWidget::~GTableWidget() {
    
}
//===============================================
// method
//===============================================
void GTableWidget::setOption(QString key, QVariant data) {
    if(key == "RowCount") m_tableWidget->setRowCount(data.toInt());
    else if(key == "ColumnCount") m_tableWidget->setColumnCount(data.toInt());
    else if(key == "AlternatingRowColors") m_tableWidget->setAlternatingRowColors(data.toBool());
    else if(key == "HorizontalHeaderLabels") m_tableWidget->setHorizontalHeaderLabels(data.toStringList());
    else if(key == "VerticalHeaderLabels") m_tableWidget->setVerticalHeaderLabels(data.toStringList());
    else if(key == "HorizontalStretchLastSection") m_tableWidget->horizontalHeader()->setStretchLastSection(data.toInt());
    else if(key == "VerticalStretchLastSection") m_tableWidget->verticalHeader()->setStretchLastSection(data.toInt());
}
//===============================================
void GTableWidget::setOption(QString key) {
    if(key == "header_h_on") m_tableWidget->horizontalHeader()->show();
    else if(key == "header_h_off") m_tableWidget->horizontalHeader()->hide();
    else if(key == "header_v_on") m_tableWidget->verticalHeader()->show();
    else if(key == "header_v_off") m_tableWidget->verticalHeader()->hide();
}
//===============================================
void GTableWidget::addItem(int row, int col, QString text) {
    QTableWidgetItem* lItem = new QTableWidgetItem(text);
    lItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    m_tableWidget->setItem(row, col, lItem);
}
//===============================================
void GTableWidget::addItem(QString key, QString text, int icon) {

}
//===============================================
void GTableWidget::addItem(QLayout* layout) {

}
//===============================================
void GTableWidget::removeItem(int index) {

}
//===============================================
// slot
//===============================================
void GTableWidget::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "previous_month") {
        m_currentDate = m_currentDate.addMonths(-1);
        int lCurrentMonth = m_currentDate.month();
        int lCurrentYear = m_currentDate.year();
        QString lMonthName = G_MONTHS_OF_YEAR[lCurrentMonth - 1];
        QString lMonthText = QString("%1 %2").arg(lMonthName).arg(lCurrentYear);
        m_monthLabel->setText(lMonthText);

        int lDayOfWeek = m_currentDate.dayOfWeek();
        int lDaysInMonth = m_currentDate.daysInMonth();
            
        int lDayCount = 1;
        int lLastDay = lDaysInMonth;
        int lFirstDay = lDayOfWeek - 1;
        
        lDayCount = lDayCount - lFirstDay;
        
        for(int i = 0; i < m_rowCount; i++) {
            for(int j = 0; j < m_colCount; j++) {
                QString lData = "";
                if(lDayCount >= 1 && lDayCount <= lLastDay) {
                    lData = QString("%1").arg(lDayCount);
                }
                m_tableWidget->item(i, j)->setText(lData);
                lDayCount++;
            }
        }
    }
    else if(lApp->widget_id == "next_month") {
        m_currentDate = m_currentDate.addMonths(1);
        int lCurrentMonth = m_currentDate.month();
        int lCurrentYear = m_currentDate.year();
        QString lMonthName = G_MONTHS_OF_YEAR[lCurrentMonth - 1];
        QString lMonthText = QString("%1 %2").arg(lMonthName).arg(lCurrentYear);
        m_monthLabel->setText(lMonthText);
        
        int lDayOfWeek = m_currentDate.dayOfWeek();
        int lDaysInMonth = m_currentDate.daysInMonth();
            
        int lDayCount = 1;
        int lLastDay = lDaysInMonth;
        int lFirstDay = lDayOfWeek - 1;
        
        lDayCount = lDayCount - lFirstDay;
        
        for(int i = 0; i < m_rowCount; i++) {
            for(int j = 0; j < m_colCount; j++) {
                QString lData = "";
                if(lDayCount >= 1 && lDayCount <= lLastDay) {
                    lData = QString("%1").arg(lDayCount);
                }
                m_tableWidget->item(i, j)->setText(lData);
                lDayCount++;
            }
        }
    }
}
//===============================================