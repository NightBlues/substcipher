#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "syment.h"
#include "cyferkey.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_3->setText(QString::fromLocal8Bit("ÔÔ          ÝÝÝ          ÙÙÙ          ÖÖÖÖ          ØØØØØØ          ÞÞÞÞÞÞ          ÆÆÆÆÆÆÆ          ÕÕÕÕÕÕÕÕÕ          ÉÉÉÉÉÉÉÉÉÉ          ××××××××××××          ÃÃÃÃÃÃÃÃÃÃÃÃÃ          ÁÁÁÁÁÁÁÁÁÁÁÁÁÁ          ÚÚÚÚÚÚÚÚÚÚÚÚÚÚ          ÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇ          ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ          ßßßßßßßßßßßßßßßßßß          ÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓÓ          ÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏ     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÌÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊÊËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËËÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎÎ"));
    ui->textEdit->setText(QString::fromLocal8Bit("ÒÜÀÙÛÝÞÉÌÙÒÞÜÒÙÎÛÁ¨ÚÝÓÄÐÎÚÈÒ¨ÈÛÍÐÎÂÂÀÙÚÞÒÈÚÝÞÉÏÊÙÎÛÁÜÙÒÎÂÞÌÒÝÂÎÞÀÂÇÙÚ¨ÅÐÙÒÈÞÌÂÎÀÚßÄÐÙÑÚÈÎÒÓÒÞÐÄÚÝÂÕÚÀÚ¨ÚÝÚÞ×ÄÒÎÐÝ×¨ÉÎÐßÄÒÔÎÒÁÂ¨ÞÒÜÐÎÀÒÌÂÁÄÙÐÈÀÂÂÇÌÐÙÐÌÝÐÜÚÝÂÞ×ÜÒÏÎÒÓÂÔÀÚÉÝÒ¨ÚÇÐÄÂÎÙÚÈÎÒÄßÍÎÒÌÙÒÍÐÝÅÂÅÒÙÚÀÒÜßÇÅÛÝ×ÎßÈÍÂÞ×ÞÒÙÈÚÝÞÒÞÜÐÎÛÌÒÈÐÍÐÎÎÛÁÜÚÅÓÙÒÅÚÄÎÛÁÔÐÙÄÛÍÜÚÀÂÇÙÚ¨ÅÐÙÒÈÏÜÒÌÙÂÍÊÝÞÉÔÛÌÒÙßÀÐÝÂÍ×ÀÚÀÒÅßÎÂÔßÄ×ÈÐÝÂÀÚÎßÌÚÝ×ÖÛÔÛÈÍÐÓÒÈÝÚÄÛÀÂÜ×ÅÛÎÒÙÅÚÝ×ÎÛÐÌÚÝ×ÖÛÒÔÛÏÎÒÓÒÏÐÝÒÈÐÀÚÄÚÑÐÎÐÞÅÒÓÝÂÒÔÇÈÚÜÂÜ×ÜÒÝÞÜÐÎÎÒÐÜÒÌÒÙÂÕÐÒÄÎÚÀÒÏßÄÒÈÂÕÎÒÐÒÙßÑÂÐÝÐÑÚÝÒÈÐÓÒÙßÀÚÇÀÚÀÈÝÂÜÒÐ"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString enc_text = ui->textEdit->toPlainText().trimmed();
    QString ideal_text = ui->textEdit_3->toPlainText().trimmed();

    //SymEnt symbols = SymEnt(enc_text);
    this->symbols.flush();
    this->symbols_ideal.flush();
    this->symbols.loadText(enc_text);
    this->symbols_ideal.loadText(ideal_text);

    ui->textBrowser->setText(this->symbols.print_dbg());
    ui->textBrowser_2->setText(this->symbols_ideal.print_dbg());
}

void MainWindow::on_pushButton_3_clicked()
{
    QString key = "";
    for(int i=0;i<this->symbols.getCount();i++) {
        key += this->symbols.getSym(i) + "<->" + this->symbols_ideal.findProb(this->symbols.getProb(i)) + "\n";
    } // for

    ui->textEdit_2->setText(key);
}

void MainWindow::on_pushButton_4_clicked()
{
    cyferkey keys;
    keys.loadKeys(ui->textEdit_2->toPlainText().trimmed());
    //ui->textBrowser_3->setText(keys.getReplacement(QString::fromLocal8Bit("à")));
    ui->textBrowser_3->setText(keys.replaceAll(ui->textEdit->toPlainText().trimmed()));
}

void MainWindow::on_pushButton_2_clicked()
{
    cyferkey keys;
    keys.loadKeys(ui->textEdit_2->toPlainText().trimmed());
    ui->textBrowser_3->setText(keys.replaceBack(ui->textEdit->toPlainText().trimmed()));
}
