
![](https://img.shields.io/badge/9randeza-%F000000.svg?style=for-the-badge&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)

# Primitive Calculator

This program will help you calculate the simplest operations (+, -, /,*).Calculate operations with integers, as well as with floating point numbers.
Do not try to put strings in it, the handling of such errors is not considered in it.

____


## The repository has:

1. **main.cpp**
   >
   ```cpp
    newFile window;
    window.resize(300,190);
    window.setWindowTitle("IbragimCoder");
    window.show();
   ```
   This main file uses this code to create a window ***window*** sets the size and displays an intuitive interface with name ©"IbragimCoder".
 

  ![](https://imgbly.com/ib/rV3YIyKxrD.jpg) 
____
2. **projectCalc.pro**
	>  A ***qmake*** project file (.pro file) for a ***C++*** application. It is used to configure the build process for the project.
```cpp
  TEMPLATE = app
  TARGET = APP
  QT = core gui
  greaterThan(QT_MAJOR_VERSION, 4):
  QT += widgets
  SOURCES += main.cpp \
     calc.cpp
  HEADERS += \
      calc.h
 ```
+ Here are some key points:
  - TEMPLATE = app: Specifies that this project is an application.
  - TARGET = APP: Sets the target name for the compiled executable (in this case, it’s named “APP”).
  - QT = core gui: Indicates that the project uses the Qt framework with core and GUI modules.
  - The SOURCES variable lists the source files (e.g., main.cpp and calc.cpp).
  - The HEADERS variable includes the header file calc.h.
____
3. **calc.h**
   >  This file is the header file for *calc.cpp*. Here we connect libraries initialize functions and global variables for further work.
  #### Connected libraries:
   + `#include <QWidget>` : `QWidget` it is the base class of all user interface objects in **Qt**. It provides basic functions and properties that are common to all widgets
   + `#include <QApplication>` : `QApplication` manages the main event cycle and global application settings. It should be created before any other widgets.
   + `#include <QPushButton>` : `QPushButton` 

#### Created variables: 
+ *bool variables:*
```cpp
    bool checkplus = false;
    bool checkminus = false;
    bool checkdev = false;
    bool checkmult = false;
```
 > Required to check the activity of buttons with logical operations (+, -, /, *).

```cpp
bool d = true;
 ```
 > A variable for checking a point in a number.
+ *doble type variable:*
  
```cpp
   double tempval;
 ```
> It is necessary to save the number entered on the screen for further operations.
____


4. **calc.cpp**
  > The file with the `class`. All logical operations are spelled out here and their display on the screen. Buttons for GUI are also created.
 + Сreating buttons with numbers:
```cpp
    QPushButton *num0 = new QPushButton("0", this);
    QPushButton *num1 = new QPushButton("1", this);
    QPushButton *num2 = new QPushButton("2", this);
    QPushButton *num3 = new QPushButton("3", this);
    QPushButton *num4 = new QPushButton("4", this);
    ...
```
+ Сreating buttons with logical operations:
```cpp
    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *mnsBtn = new QPushButton("-", this);
    QPushButton *mult = new QPushButton("x", this);
    QPushButton *iqvl = new QPushButton("=", this);
    ...
```
+ Сreating **widgets** and determining their location
```cpp
    grid->addWidget(plsBtn,4,0);
    grid->addWidget(mnsBtn,5,0);
    grid->addWidget(mult,6,0);
    grid->addWidget(dev,7,0);
    ...
```
+ Сreating a connection between **widgets** on the screen with the corresponding functions:
```cpp
    connect(plsBtn,&QPushButton::clicked, this, &newFile::OnPlus);
    connect(mnsBtn, &QPushButton::clicked, this, &newFile::OnMinus);
    connect(mult, &QPushButton::clicked, this, &newFile::OnMult);
    connect(dev, &QPushButton::clicked, this, &newFile::OnDev);
    connect(num0, &QPushButton::clicked, this, &newFile::Set0);
    connect(num1, &QPushButton::clicked, this, &newFile::Set1);
    connect(num2, &QPushButton::clicked, this, &newFile::Set2);
    ...
```
+ Functions defining operations with their subsequent use:
```cpp
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
...and the like...
}
```
> Here we consider the various cases in which the function was called (the "-" button is pressed). 
 For example, if a number is entered or another operation is performed.

+ Functions that are called when numbers are pressed

```cpp
void newFile::Set1(){
    QString num = lbl->text(); // Получаем текущее число
    if (num == "0" || num == "x" || num == "/" || num == "+" || num == "-") {
        num = "1"; // Если текущее число равно 0, заменяем его на 1
    } else {
        num += "1"; // Иначе добавляем 1 в конец числа
    }
    lbl->setText(num);
...and the like...

}

```
+ The function of adding a point (creating a floating point number). 
Under what conditions is it possible to remove a point, and under what conditions it is not (for example, the number **8...5** impossible).

```cpp
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
```
+ The **Ikvl** function is used to output the final value after a chain of operations.
```cpp
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
``` 
> All operations are performed here based on data received from previous user actions.

+ A function that clears all entered data and brings the calculator to its starting position.

```cpp
void newFile::CE(){
    tempval = 0;
    checkdev = 0;
    checkminus = 0;
    checkmult = 0;
    checkplus = 0;
    d = 1;
    lbl->setText(QString::number(0));
}

```

+ The function deletes one entered number or operation.

```cpp
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
```
