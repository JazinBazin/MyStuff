#include "translatorwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "morsetranslator.h"

void TranslatorWidget::btnLoadFromFileClicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл для загрузки",
                                                    QDir::homePath(),
                                                    "Text file (*.txt)");
    if(fileName.isNull())
        return;

    QFile sourceFile(fileName);
    if(!sourceFile.open(QIODevice::ReadOnly))
        QMessageBox::critical(this, this->windowTitle(),
                              "Не удалось открыть файл для чтения " + fileName);

    txtEditSourseText->setPlainText(QString::fromLocal8Bit(sourceFile.readAll()));
    sourceFile.close();
}

void TranslatorWidget::btnTranslateClicked() {
    QString sourceText = txtEditSourseText->toPlainText();
    if(sourceText.isEmpty()) {
        QMessageBox::information(this, this->windowTitle(),
                                 "Введите текст для перевода");
        return;
    }

    if(cmbBoxTranslationType->currentIndex() == 0)
        txtEditResultText->setPlainText(MorseTranslator::translateToMorse(sourceText));
    else
        txtEditResultText->setPlainText(MorseTranslator::translateFromMorse(sourceText));
}

void TranslatorWidget::btnSaveToFileClicked() {
    QString resultText = txtEditResultText->toPlainText();
    if(resultText.isEmpty()) {
        QMessageBox::information(this, this->windowTitle(),
                                 "Нет данных для сохранения. " \
                                 "Выполните перевод.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Выберите файл для сохранения",
                                                    QDir::homePath(),
                                                    "Text file (*.txt)");
    if(fileName.isNull())
        return;

    QFile resultFile(fileName);
    if(!resultFile.open(QIODevice::WriteOnly))
        QMessageBox::critical(this, this->windowTitle(),
                              "Не удалось открыть файл для записи " + fileName);

    resultFile.write(resultText.toLocal8Bit());
    resultFile.close();
}

TranslatorWidget::TranslatorWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Переводчик азбуки Морзе");

    QLabel *lblSourseText = new QLabel("Исходный текст:");
    QLabel *lblResultText = new QLabel("Результат перевода:");
    QLabel *lblTranslationType = new QLabel("Перевод");

    QPushButton *btnLoadFromFile = new QPushButton("Загрузить из файла");
    QPushButton *btnTranslate = new QPushButton("Перевести");
    QPushButton *btnSaveToFile = new QPushButton("Сохранить в файл");

    QObject::connect(btnLoadFromFile, &QPushButton::clicked,
                     this, &TranslatorWidget::btnLoadFromFileClicked);
    QObject::connect(btnTranslate, &QPushButton::clicked,
                     this, &TranslatorWidget::btnTranslateClicked);
    QObject::connect(btnSaveToFile, &QPushButton::clicked,
                     this, &TranslatorWidget::btnSaveToFileClicked);

    txtEditSourseText = new QTextEdit;
    txtEditResultText = new QTextEdit;
    txtEditSourseText->setFontPointSize(14);
    txtEditResultText->setFontPointSize(14);

    cmbBoxTranslationType = new QComboBox;
    cmbBoxTranslationType->addItems(QStringList() << "на Морзе" << "с Морзе");
    cmbBoxTranslationType->setCurrentIndex(0);

    QHBoxLayout *layoutForSourceTextHeader = new QHBoxLayout;
    layoutForSourceTextHeader->setAlignment(Qt::AlignLeft);
    layoutForSourceTextHeader->addWidget(lblSourseText);
    layoutForSourceTextHeader->addWidget(btnLoadFromFile);
    layoutForSourceTextHeader->addWidget(lblTranslationType);
    layoutForSourceTextHeader->addWidget(cmbBoxTranslationType);
    layoutForSourceTextHeader->addWidget(btnTranslate);

    QVBoxLayout *layoutForSourceTextColumn = new QVBoxLayout;
    layoutForSourceTextColumn->addLayout(layoutForSourceTextHeader);
    layoutForSourceTextColumn->addWidget(txtEditSourseText);

    QHBoxLayout *layoutForResultTextHeader = new QHBoxLayout;
    layoutForResultTextHeader->setAlignment(Qt::AlignLeft);
    layoutForResultTextHeader->addWidget(lblResultText);
    layoutForResultTextHeader->addWidget(btnSaveToFile);

    QVBoxLayout *layoutForResultTextColumn = new QVBoxLayout;
    layoutForResultTextColumn->addLayout(layoutForResultTextHeader);
    layoutForResultTextColumn->addWidget(txtEditResultText);

    QHBoxLayout *layoutForTranslatorWidget = new QHBoxLayout;
    layoutForTranslatorWidget->addLayout(layoutForSourceTextColumn);
    layoutForTranslatorWidget->addLayout(layoutForResultTextColumn);

    this->setLayout(layoutForTranslatorWidget);
}

TranslatorWidget::~TranslatorWidget() {}
