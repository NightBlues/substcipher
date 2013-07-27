#ifndef SYMENT_H
#define SYMENT_H
#include <QString>

class SymEnt // Символ и его вероятность появления.
{
private:
    QString sym[32];
    int prob[32];
    int count;
    int sym_count_all;
public:
    int getCount();
    void setCount(int);
    void loadText(QString);
    int findSym(QString);
    QString getSym(int);
    float getProb(QString);
    float getProb(int);
    void setProb(QString, int);
    bool addSym(QString);
    void incProb(QString);
    void flush();
    QString findProb(float);
    QString print_dbg();
    SymEnt();
    SymEnt(QString);
    ~SymEnt();
};

#endif // SYMENT_H
