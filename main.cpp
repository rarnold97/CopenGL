//
// Created by ryanm on 1/28/2021.
//
#include "common/MeGlWindow.h"

int CreateAWindow();

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MeGlWindow window ;
    window.show();
    return app.exec();

    /*
    int flag = CreateAWindow();
    if (flag!=-1)
        return 0 ;
    else
        return -1 ;
    */
}