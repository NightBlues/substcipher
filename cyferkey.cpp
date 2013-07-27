#include "cyferkey.h"
#include <QStringList>


cyferkey::cyferkey()
{
    this->count=0;
}
void cyferkey::loadKeys(QString str)
{
    QStringList strings = str.split("\n");
    for (int i = 0; i < strings.size(); i++) {
        QStringList keyrep = strings.at(i).split("<->");
        this->a[i] = keyrep.at(0);
        this->b[i] = keyrep.at(1);
        this->count++;
    } // for
}

QString cyferkey::getReplacement(QString key)
{
    for(int i = 0; i < this->count;i++) {
        if(key==this->a[i])
            return this->b[i];
    } // for

    return key;
}

QString cyferkey::getReplacementB(QString key)
{
    for(int i = 0; i < this->count;i++) {
        if(key==this->b[i])
            return this->a[i];
    } // for

    return key;
}


QString cyferkey::replaceAll(QString str)
{
    for(int i=0; i < str.size(); i++) {
        str.replace(i, 1, this->getReplacement(str.at(i)));
    } // for

    return str;
}

QString cyferkey::replaceBack(QString str)
{
    for(int i=0; i < str.size(); i++) {
        str.replace(i, 1, this->getReplacementB(str.at(i)));
    } // for

    return str;
}
