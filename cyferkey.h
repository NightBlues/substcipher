#ifndef CYFERKEY_H
#define CYFERKEY_H
#include <QString>

class cyferkey
{
private:

    QString a[32];
    QString b[32];

    int count;

public:
    void loadKeys(QString);
    QString getReplacement(QString);
    QString getReplacementB(QString);
    QString replaceAll(QString);
    QString replaceBack(QString);
    cyferkey();
};

#endif // CYFERKEY_H
