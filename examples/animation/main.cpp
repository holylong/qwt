/*****************************************************************************
 * Qwt Examples
 * Copyright (C) 1997   Josef Wilgen
 * Copyright (C) 2002   Uwe Rathmann
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the Qwt License, Version 1.0
 *****************************************************************************/

#include "Plot.h"
#include "qwt_command.h"
#include <QApplication>

#ifndef QWT_NO_OPENGL
    #if QT_VERSION < 0x050000
        #include <qgl.h>
    #endif

    #if QT_VERSION >= 0x050400
        #include <QwtPlotOpenGLCanvas>
        typedef QwtPlotOpenGLCanvas Canvas;
    #else
        #include <QwtPlotGLCanvas>
        typedef QwtPlotGLCanvas Canvas;
    #endif
#else
    #include <QwtPlotCanvas>
    typedef QwtPlotCanvas Canvas;
#endif

namespace
{
    class AminatedPlot : public Plot
    {
      public:
        AminatedPlot()
        {
            Canvas* canvas = new Canvas();
            canvas->setPaintAttribute( Canvas::BackingStore, false );
            canvas->setFrameStyle( QFrame::NoFrame );

            setCanvas( canvas );
            setCanvasBackground( QColor( 30, 30, 50 ) );
        }
    };
}

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    AminatedPlot plot;

    int width,height,x,y;
    QwtCommand::parseCommandLine(app, width, height, x, y);

    // 设置窗口大小和位置
    if (width > 0 && height > 0) {
        plot.resize(width, height);
    }
    
    if (x >= 0 && y >= 0) {
        plot.move(x, y);
    }
    // plot.resize( 400, 400 );
    plot.show();

    return app.exec();
}
