#pragma once
#include <QString>
#include <QHash>

class MorseTranslator
{
public:
    static QString translateFromMorse(const QString &sourceText);
    static QString translateToMorse(const QString &sourceText);
private:
    const static QHash<QString, QChar> codeTableFromMorse;
    const static QHash<QChar, QString> codeTableToMorse;
};
