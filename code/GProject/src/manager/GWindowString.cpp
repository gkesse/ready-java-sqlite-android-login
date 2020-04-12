//===============================================
#include "GWindowString.h"
#include "GWidget.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWindowString::GWindowString(QWidget* parent) :
GWindow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindowString");
	m_tileBar = GWidget::Create("title_bar");
	m_string = GWidget::Create("line_edit");
	m_replace = GWidget::Create("line_edit_run");
	m_regExp = GWidget::Create("line_edit_run");
	m_toUpper = GWidget::Create("push_button");
	m_textEdit = GWidget::Create("text_edit");

	m_string->setLabel("String");
	m_replace->setLabel("Replace");
	m_regExp->setLabel("RegExp");
	m_toUpper->setLabel("ToUpper");

	QVBoxLayout* lBodyLayout = new QVBoxLayout;
	lBodyLayout->setMargin(10);
	lBodyLayout->setSpacing(10);
	lBodyLayout->setAlignment(Qt::AlignTop);
	lBodyLayout->addWidget(m_string);
	lBodyLayout->addWidget(m_replace);
	lBodyLayout->addWidget(m_regExp);
	lBodyLayout->addWidget(m_toUpper);
	lBodyLayout->addWidget(m_textEdit, 1);

	QVBoxLayout* lMainLayout = new QVBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(m_tileBar);
	lMainLayout->addLayout(lBodyLayout, 1);

	setLayout(lMainLayout);

	connect(m_replace, SIGNAL(emitRun()), this, SLOT(slotReplace()));
	connect(m_regExp, SIGNAL(emitRun()), this, SLOT(slotRegExp()));
	connect(m_toUpper, SIGNAL(emitRun()), this, SLOT(slotToUpper()));

	initTileBar("String | ReadyDev", fa::snowflakeo, "orange");
}
//===============================================
GWindowString::~GWindowString() {

}
//===============================================
void GWindowString::slotReplace() {
	QString lString = m_string->getText();
	QString lDataExp = m_replace->getText();

	if(lString == "") return;
	if(lDataExp == "") return;

	lString.replace(QRegExp("\\s"), "");
	lDataExp.replace(QRegExp("\\s"), "");

	QStringList lMapExp = lDataExp.split(";");

	QString lResultExp = lString;
	lResultExp.replace(lMapExp[0], lMapExp[1]);

	m_textEdit->textEdit()->append(QString("> %1").arg(lString));
	m_textEdit->textEdit()->append(QString("= %1").arg(lResultExp));
	m_textEdit->textEdit()->append("");
}
//===============================================
void GWindowString::slotRegExp() {
	QString lString = m_string->getText();
	QString lDataExp = m_regExp->getText();

	if(lString == "") return;
	if(lDataExp == "") return;

	lString.replace(QRegExp("\\s"), "");
	lDataExp.replace(QRegExp("\\s"), "");

	QStringList lMapExp = lDataExp.split(";");

	QRegularExpression lRegExp(lMapExp[0]);
	QRegularExpressionMatch lMatchExp = lRegExp.match(lString);

	m_textEdit->textEdit()->append(QString("> %1").arg(lString));

	QString lResultExp;
	if(lMatchExp.hasMatch()) {
		int lSizeExp = 0;
		if(lMapExp[1] != "") lSizeExp = lMapExp[1].toInt();
		for(int i = 0; i <= lSizeExp; i++) {
			lResultExp = lMatchExp.captured(i);
			m_textEdit->textEdit()->append(QString("= %1 : %2").arg(i).arg(lResultExp));
		}
	}

	m_textEdit->textEdit()->append("");
}
//===============================================
void GWindowString::slotToUpper() {
	QString lString = m_string->getText();

	if(lString == "") return;

	lString.replace(QRegExp("\\s"), "");
	QString lResult = lString.toUpper();

	m_textEdit->textEdit()->append(QString("> %1").arg(lString));
	m_textEdit->textEdit()->append(QString("= %1").arg(lResult));
	m_textEdit->textEdit()->append("");
}
//================================================
#endif
//===============================================
