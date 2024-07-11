/*****************************************************************************
 * Qwt Examples - Copyright (C) 2002 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#include <QwtPlot>
#include <QwtPlotCurve>
#include <QwtPlotGrid>
#include <QwtSymbol>
#include <QwtLegend>
#include <QApplication>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    QwtPlot plot;
    plot.setTitle( "Plot Demo" );
    plot.setCanvasBackground( Qt::white );
    plot.setAxisScale( QwtAxis::YLeft, 0.0, 10.0 );
    plot.insertLegend( new QwtLegend() );

    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( &plot );

    QwtPlotCurve* curve = new QwtPlotCurve();
    curve->setTitle( "Some Points" );
    curve->setPen( Qt::blue, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol* symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
    curve->setSymbol( symbol );

    QPolygonF points;
    points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 )
           << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
           << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 );
    curve->setSamples( points );

    curve->attach( &plot );

    // plot.resize( 600, 400 );
        int width,height,x,y;
    QwtCommand::parseCommandLine(app, width, height, x, y);

    // 设置窗口大小和位置
    if (width > 0 && height > 0) {
        plot.resize(width, height);
    }
    
    if (x >= 0 && y >= 0) {
        plot.move(x, y);
    }
    plot.show();

    return app.exec();
}
