/*****************************************************************************
 * Qwt Examples - Copyright (C) 2002 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#include "MainWindow.h"
#include "qwt_command.h"
#include <QApplication>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );
    app.setStyle( "Windows" );

    MainWindow window;
    // window.resize( 700, 500 );

        int width,height,x,y;
    QwtCommand::parseCommandLine(app, width, height, x, y);

    // 设置窗口大小和位置
    if (width > 0 && height > 0) {
        window.resize(width, height);
    }
    
    if (x >= 0 && y >= 0) {
        window.move(x, y);
    }
    window.show();

    return app.exec();
}
