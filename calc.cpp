#include "calc.h"
#include <QGridLayout>

newFile::newFile(QWidget *parent) : QWidget{parent}{

    QPushButton *num0 = new QPushButton("0", this);
    QPushButton *num1 = new QPushButton("1", this);
    QPushButton *num2 = new QPushButton("2", this);
    QPushButton *num3 = new QPushButton("3", this);
    QPushButton *num4 = new QPushButton("4", this);
    QPushButton *num5 = new QPushButton("5", this);
    QPushButton *num6 = new QPushButton("6", this);
    QPushButton *num7 = new QPushButton("7", this);
    QPushButton *num8 = new QPushButton("8", this);
    QPushButton *num9 = new QPushButton("9", this);

    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *mnsBtn = new QPushButton("-", this);
    QPushButton *mult = new QPushButton("x", this);
    QPushButton *iqvl = new QPushButton("=", this);
    QPushButton *dev = new QPushButton("/", this);
    QPushButton *del = new QPushButton("<-", this);
    QPushButton *dot = new QPushButton(".", this);
    QPushButton *CE = new QPushButton("CE", this);

    lbl = new QLineEdit("0",this);
    lbl -> setFixedHeight(60);
    QGridLayout *grid = new QGridLayout(this);

    grid->setSpacing(0); // Remove spacing between widgets
    grid->setContentsMargins(0, 0, 0, 0); // Remove margins around the layout


    grid->addWidget(plsBtn,4,0);
    grid->addWidget(mnsBtn,5,0);
    grid->addWidget(mult,6,0);
    grid->addWidget(dev,7,0);
    grid->addWidget(del,3, 2, 1, 2);
    grid->addWidget(iqvl,3,0, 1, 2);
    grid->addWidget(CE,7,3);


    grid->addWidget(num0,7,2);
    grid->addWidget(num1,4,1);
    grid->addWidget(num2,4,2);
    grid->addWidget(num3,4,3);
    grid->addWidget(num4,5,1);
    grid->addWidget(num5,5,2);
    grid->addWidget(num6,5,3);
    grid->addWidget(num7,6,1);
    grid->addWidget(num8,6,2);
    grid->addWidget(num9,6,3);


    grid->addWidget(dot,7,1);

    grid->addWidget(lbl,0,0,3,4);

    setLayout(grid);
    connect(plsBtn,&QPushButton::clicked, this, &newFile::OnPlus);
    connect(mnsBtn, &QPushButton::clicked, this, &newFile::OnMinus);
    connect(mult, &QPushButton::clicked, this, &newFile::OnMult);
    connect(dev, &QPushButton::clicked, this, &newFile::OnDev);
    connect(num0, &QPushButton::clicked, this, &newFile::Set0);
    connect(num1, &QPushButton::clicked, this, &newFile::Set1);
    connect(num2, &QPushButton::clicked, this, &newFile::Set2);
    connect(num3, &QPushButton::clicked, this, &newFile::Set3);
    connect(num4, &QPushButton::clicked, this, &newFile::Set4);
    connect(num5, &QPushButton::clicked, this, &newFile::Set5);
    connect(num6, &QPushButton::clicked, this, &newFile::Set6);
    connect(num7, &QPushButton::clicked, this, &newFile::Set7);
    connect(num8, &QPushButton::clicked, this, &newFile::Set8);
    connect(num9, &QPushButton::clicked, this, &newFile::Set9);
    connect(iqvl, &QPushButton::clicked, this, &newFile::Ikvl);
    connect(dot, &QPushButton::clicked, this, &newFile::SetDot);
    connect(CE, &QPushButton::clicked, this, &newFile::CE);
    connect(del, &QPushButton::clicked, this, &newFile::Del);
}
void newFile::OnMinus(){
     QString oper = lbl->text();
    if(oper == "+" || oper == "-" || oper == "x" || oper == "/"){
         Ikvl();
         checkdev = false;
         checkplus = false;
         checkmult = false;
         checkminus = true;
         lbl->setText(QString("-"));
         d = true;
     }else if(checkplus == true || checkdev == true || checkmult == true || checkminus == true){
        checkdev = false;
        checkplus = false;
        checkmult = false;
        checkminus = true;
        lbl->setText(QString("-"));
        d = true;
    }else{
    d = true;
    checkminus = true;
    tempval = lbl->text().toDouble();
    lbl->setText(QString("-"));
    }
}
void newFile::OnPlus(){
     QString oper = lbl->text();
    if(oper == "+" || oper == "-" || oper == "x" || oper == "/"){
        checkdev = false;
        checkminus = false;
        checkmult = false;
        checkplus = true;
        lbl->setText(QString("+"));
        d = true;
    }else if(checkminus == true || checkdev == true || checkmult == true || checkplus == true){
        Ikvl();
        lbl->setText(QString("+"));
        d = true;
        checkdev = false;
        checkminus = false;
        checkmult = false;
        checkplus = true;
    }else{
    d = true;
    checkplus = true;
    tempval = lbl->text().toDouble();
    lbl->setText(QString("+"));
    }
}

void newFile::OnMult(){
     QString oper = lbl->text();
    if(oper == "+" || oper == "-" || oper == "x" || oper == "/"){
        checkmult = true;
        checkminus = false;
        checkplus = false;
        checkdev = false;
        lbl->setText(QString("x"));
        d = true;
    }else if(checkminus == true || checkdev == true || checkplus == true || checkmult == true){
        d = true;
        Ikvl();
        lbl->setText(QString("x"));
        checkdev = false;
        checkmult = true;
        checkminus = false;
        checkplus = false;
    }else{
    d = true;
    checkmult = true;
    tempval = lbl->text().toDouble();
    lbl->setText(QString("x"));
    }
}

void newFile::OnDev(){
    QString oper = lbl->text();
    if(oper == "+" || oper == "-" || oper == "x" || oper == "/"){
        checkmult = false;
        checkminus = false;
        checkplus = false;
        checkdev = true;
        lbl->setText(QString("/"));
        d = true;
    } else if(checkminus == true || checkmult == true || checkplus == true || checkdev == true){
        d = true;
        Ikvl();
        lbl->setText(QString("/"));
        checkdev = true;
        checkmult = false;
        checkminus = false;
        checkplus = false;
    }else{
    d = true;
    checkdev = true;
    tempval = lbl->text().toDouble();
    lbl->setText(QString("/"));
    }

}

void newFile::Set0(){
    QString num = lbl->text(); // Получаем текущее число
    num += "0";
    lbl->setText(num);
}

void newFile::Set1(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "1"; // Если текущее число равно 0, заменяем его на 1
    } else {
        num += "1"; // Иначе добавляем 1 в конец числа
    }
    lbl->setText(num);
}

void newFile::Set2(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "2";
    } else {
        num += "2";
    }
    lbl->setText(num);

}

void newFile::Set3(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "3";
    } else {
        num += "3";
    }
    lbl->setText(num);

}

void newFile::Set4(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "4";
    } else {
        num += "4";
    }
    lbl->setText(num);

}

void newFile::Set5(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "5";
    } else {
        num += "5";
    }
    lbl->setText(num);
}

void newFile::Set6(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "6";
    } else {
        num += "6";
    }
    lbl->setText(num);
}

void newFile::Set7(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "7";
    } else {
        num += "7";
    }
    lbl->setText(num);
}

void newFile::Set8(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "9";
    } else {
        num += "8";
    }
    lbl->setText(num);

}

void newFile::Set9(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "9";
    } else {
        num += "9";
    }
    lbl->setText(num);

}

void newFile::SetDot(){
    QString dot = lbl->text();
    if(dot== "x" || dot == "/" || dot == "+" || dot == "-"){
        d = false;
    }else if(d == 1){
        dot += ".";
        d = false;
    }
    lbl->setText(dot);
}

void newFile::Ikvl(){
    if(checkminus == true){
        double num = lbl->text().toDouble(); // Получаем текущее число
        num -= tempval;
        num *= -1;
        tempval = num;
        lbl->setText(QString::number(num));
    }
    if(checkplus == true){
        double num = lbl->text().toDouble(); // Получаем текущее число
        num += tempval;
        tempval = num;
        lbl->setText(QString::number(num));
    }
    if(checkmult == true){
        double num = lbl->text().toDouble(); // Получаем текущее число
        num *= tempval;
        tempval = num;
        lbl->setText(QString::number(num));
    }
    if(checkdev == true){
        double temp = tempval;
        double num = lbl->text().toDouble(); // Получаем текущее число
        temp /= num;
        tempval = temp;
        lbl->setText(QString::number(temp));
    }
    checkdev = false;
    checkminus = false;
    checkmult = false;
    checkplus = false;

}
void newFile::CE(){
    tempval = 0;
    checkdev = 0;
    checkminus = 0;
    checkmult = 0;
    checkplus = 0;
    d = 1;
    lbl->setText(QString::number(0));
}

void newFile::Del(){
    QString num = lbl->text();
    QString num1 = num;
    QChar lastChar = num.at(num.length() - 1);
    if(lastChar == '.'){
        d = 1;
    }
    num1.chop(1);
    if(num == "x" || num == "/" || num == "+" || num == "-" || num.isEmpty()){
        lbl->setText(num1);
    }else if(num1.isEmpty()){
        num1 = "0";
    }
     lbl->setText(num1);
}
