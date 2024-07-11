/*****************************************************************************
 * Qwt Examples - Copyright (C) 2002 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#include "CompassGrid.h"
#include "CockpitGrid.h"
#include "qwt_command.h"
#include <QApplication>
#include <QTabWidget>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    QTabWidget tabWidget;
    tabWidget.addTab( new CompassGrid, "Compass" );
    tabWidget.addTab( new CockpitGrid, "Cockpit" );
    int width,height,x,y;
    QwtCommand::parseCommandLine(app, width, height, x, y);

    // 设置窗口大小和位置
    if (width > 0 && height > 0) {
        tabWidget.resize(width, height);
    }
    
    if (x >= 0 && y >= 0) {
        tabWidget.move(x, y);
    }
    tabWidget.show();

    return app.exec();
}

