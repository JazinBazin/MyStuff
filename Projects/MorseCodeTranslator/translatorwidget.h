#pragma once
#include <QWidget>
#include <QTextEdit>
#include <QComboBox>

class TranslatorWidget : public QWidget
{
    Q_OBJECT
public:
    TranslatorWidget(QWidget *parent = nullptr);
    ~TranslatorWidget();

private:
    QTextEdit *txtEditSourseText;
    QTextEdit *txtEditResultText;
    QComboBox *cmbBoxTranslationType;

private slots:
    void btnLoadFromFileClicked();
    void btnTranslateClicked();
    void btnSaveToFileClicked();
};
