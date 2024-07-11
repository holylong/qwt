/*****************************************************************************
 * Qwt Examples
 * Copyright (C) 1997   Josef Wilgen
 * Copyright (C) 2002   Uwe Rathmann
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the Qwt License, Version 1.0
 *****************************************************************************/

#include "MainWindow.h"
#include "qwt_command.h"
#include <QApplication>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    MainWindow window;
    // window.resize( 540, 400 );

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
