#include <calc.h>

int main(int argc,char*argv[]){
    QApplication app(argc,argv);
    newFile window;

    window.resize(300,190);
    window.setWindowTitle("IbragimCoder");
    window.show();

    return app.exec();
}
