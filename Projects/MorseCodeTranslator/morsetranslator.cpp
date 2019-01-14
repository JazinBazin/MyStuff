#include "morsetranslator.h"
#include <QStringList>

QString MorseTranslator::translateFromMorse(const QString &sourceText) {
    QString translationResult;
    for(const QString &code : sourceText.split(QChar::Space)) {
        if(code.isEmpty())
            translationResult += ' ';
        else {
            QHash<QString, QChar>::const_iterator keyValueIter = codeTableFromMorse.constFind(code);
            if(keyValueIter != codeTableFromMorse.end())
                translationResult += keyValueIter.value();
        }
    }

    return translationResult;
}

QString MorseTranslator::translateToMorse(const QString &sourceText) {
    QString translationResult;
    for(QChar ch : sourceText) {
        QHash<QChar, QString>::const_iterator keyValueIter = codeTableToMorse.constFind(ch.toLower());
        if(keyValueIter != codeTableToMorse.end())
            translationResult += keyValueIter.value() + ' ';
    }

    if(!translationResult.isEmpty())
        translationResult.chop(1);

    return translationResult;
}

const QHash<QString, QChar> MorseTranslator::codeTableFromMorse
{
    {".-", 'a'},        {"-...", 'b'},      {"-.-.", 'c'},      {"-..", 'd'},
    {".", 'e'},         {"..-.", 'f'},      {"--.", 'g'},       {"....", 'h'},
    {"..", 'i'},        {".---", 'j'},      {"-.-", 'k'},       {".-..", 'l'},
    {"--", 'm'},        {"-.", 'n'},        {"---", 'o'},       {".--.", 'p'},
    {"--.-", 'q'},      {".-.", 'r'},       {"...", 's'},       {"-", 't'},
    {"..-", 'u'},       {"...-",'v'},       {".--", 'w'},       {"-..-", 'x'},
    {"-.--", 'y'},      {"--..", 'z'},      {".-...", '&'},     {".----.", '\''},
    {".--.-.", '@'},    {"-.--.-", ')'},    {"-.--.", '('},     {"---...", ':'},
    {"--..--", ','},    {"-.-.--", '!'},    {".-.-.-", '.'},    {"-....-", '-'},
    {".-.-.", '+'},     {".-..-.", '\"'},   {"..--..", '?'},    {"-..-.", '/'},
    {"-----", '0'},     {".----", '1'},     {"..---", '2'},     {"...--", '3'},
    {"....-", '4'},     {".....", '5'},     {"-....", '6'},     {"--...", '7'},
    {"---..", '8'},     {"----.", '9'},     {".-.-", '\n'}
};

const QHash<QChar, QString> MorseTranslator::codeTableToMorse
{
    {'a', ".-"},        {'b', "-..."},      {'c', "-.-."},      {'d', "-.."},
    {'e', "."},         {'f', "..-."},      {'g', "--."},       {'h', "...."},
    {'i', ".."},        {'j', ".---"},      {'k', "-.-"},       {'l', ".-.."},
    {'m', "--"},        {'n', "-."},        {'o', "---"},       {'p', ".--."},
    {'q', "--.-"},      {'r', ".-."},       {'s', "..."},       {'t', "-"},
    {'u', "..-"},       {'v', "...-"},      {'w', ".--"},       {'x', "-..-"},
    {'y', "-.--"},      {'z', "--.."},      {'&', ".-..."},     {'\'', ".----."},
    {'@', ".--.-."},    {')', "-.--.-"},    {'(', "-.--."},     {':', "---..."},
    {',', "--..--"},    {'!', "-.-.--"},    {'.', ".-.-.-"},    {'-', "-....-"},
    {'+', ".-.-."},     {'\"', ".-..-."},   {'?', "..--.."},    {'/', "-..-."},
    {'0', "-----"},     {'1', ".----"},     {'2', "..---"},     {'3', "...--"},
    {'4', "....-"},     {'5', "....."},     {'6', "-...."},     {'7', "--..."},
    {'8', "---.."},     {'9', "----."},     {'\n', ".-.-"},     {' ', ""}
};
