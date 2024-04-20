#ifndef NEWFILE_H
#define NEWFILE_H
#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class newFile : public QWidget{
    Q_OBJECT
public:
    bool checkplus = false;
    bool checkminus = false;
    bool checkdev = false;
    bool checkmult = false;
    double tempval;
    bool d = 1; //проверка точки
    newFile(QWidget *parent = nullptr);

private slots:
    void OnPlus();
    void OnMinus();
    void OnMult();
    void OnDev();
    void Set0();
    void Set1();
    void Set2();
    void Set3();
    void Set4();
    void Set5();
    void Set6();
    void Set7();
    void Set8();
    void Set9();
    void SetDot();
    void Ikvl();
    void CE();
    void Del();
private:
    QLineEdit *lbl;

signals:

};

#endif // NEWFILE_H
