#include "syment.h"


SymEnt::SymEnt()
{
    this->count=0;
    this->sym_count_all=0;
    for(int i=0;i<32;i++)
        this->prob[i]=0;
}

SymEnt::SymEnt(QString t)
{
    this->count=0;
    this->sym_count_all=0;
    for(int i=0;i<32;i++)
        this->prob[i]=0;
    this->loadText(t);
}


SymEnt::~SymEnt(){

}

void SymEnt::setProb(QString sym, int prob)
{
    this->addSym(sym);
    this->prob[this->findSym(sym)]=prob;
}

void SymEnt::incProb(QString sym)
{
    int sym_i = this->findSym(sym);
    if(sym_i != -1)
        this->setProb(sym, this->prob[sym_i]+1);
    else
        this->setProb(sym, 1);
}

float SymEnt::getProb(QString sym)
{
    int sym_i = this->findSym(sym);
    if(sym_i > -1)
        return this->getProb(sym_i);
    return 0;
}

float SymEnt::getProb(int sym_i)
{
    if(sym_i < count)
        return (float)this->prob[sym_i]/(float)(this->sym_count_all-1);
    return 0;
}

bool SymEnt::addSym(QString sym)
{
    this->sym_count_all++;
    if(this->findSym(sym) == -1) {
        this->sym[this->count]=sym;
        this->prob[this->count]=0;
        this->count++;
        return true;
    } // if
    return false;
}

int SymEnt::findSym(QString sym)
{
    for(int i=0;i<count;i++){
        if(this->sym[i]==sym)
            return i;
    } // for

    return -1;
}

int SymEnt::getCount()
{
    return this->count;
}
void SymEnt::setCount(int c)
{
    if(c>0)
        this->count=c;
}

QString SymEnt::print_dbg()
{
    QString res = QString::fromLocal8Bit("Всего символов: ")+QString::number(this->sym_count_all-1)+QString::fromLocal8Bit("\nУникальных: ")+QString::number(this->count)+"\n";
//    for(int i=0;i<this->count;i++) {
//        //res += this->sym[i] + " - " + QString::number(this->getProb(i)) + "\n";
//        res += QString::number(i)+") "+this->sym[i]+" - "+QString::number(this->prob[i])+" - "+QString::number(this->getProb(i))+"\n";
//    } // for
    // Сортировка подсчетом по количеству появления (вероятностям).
    int count_t=0; // сколько элементов мы уже рассмотрели.
    int i=0;

    // Ищем максимальную вероятность.
    for(int m = 0; m < this->count; m++) {
        if(this->prob[m] > i)
            i = this->prob[m];
    }

    while(count_t < this->count && i > 0) { // Считаем пока не выведем все элементы.
        // Находим букву количество появлений которой равно итерации цикла
        int t=0;
        for(t=0; t < this->count; t++) {
            if(this->prob[t]==i) {
                res += this->sym[t]+" - "+QString::number(this->prob[t])+" - "+QString::number(this->getProb(t), 'g', 2)+"\n";
                count_t++;
            } // if
        } // for
        i--;
    } // while


    return res;
}

void SymEnt::loadText(QString text)
{
    int text_len = text.length();
    for(int i=0;i<text_len;i++) {
        this->incProb(text.mid(i, 1));
    } // for
}

QString SymEnt::findProb(float p)
{
    int sym_i=0;
    float prob_dif=1.0, prob_dif_t;

    for(int i=0;i<this->count;i++) {
        //prob_dif_t = this->getProb(i) - this->getProb(sym_i);
        prob_dif_t = this->getProb(i) - p;
        // abs :-/
        prob_dif_t = (prob_dif_t<0) ? prob_dif_t*(-1) : prob_dif_t;

        if(prob_dif_t < prob_dif) {
            prob_dif = prob_dif_t;
            sym_i = i;
        } // if
    } // for

    return this->sym[sym_i];
}
void SymEnt::flush()
{
    this->count=0;
    this->sym_count_all=0;
    for(int i=0;i<32;i++){
        this->prob[i] = 0;
        this->sym[i] = "";
    }
}

QString SymEnt::getSym(int i)
{
    if(i<this->count)
        return this->sym[i];
    return "";
}
