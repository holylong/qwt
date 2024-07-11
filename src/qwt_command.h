#ifndef _QWT_COMMAND_H_
#define _QWT_COMMAND_H_

#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QStringList>
#include <QCommandLineOption>

class QwtCommand{
public:

  static void parseCommandLine(const QApplication &app, int &width, int &height, int &x, int &y){
      // 创建命令行解析器
      QCommandLineParser parser;
      parser.setApplicationDescription("Qt Command Line Example");
      parser.addHelpOption();

      // 添加命令行选项
      QCommandLineOption widthOption(QStringList() << "width", "Window width", "width");
      QCommandLineOption heightOption(QStringList() << "height", "Window height", "height");
      QCommandLineOption xPosOption(QStringList() << "x", "X position", "x");
      QCommandLineOption yPosOption(QStringList() << "y", "Y position", "y");

      parser.addOption(widthOption);
      parser.addOption(heightOption);
      parser.addOption(xPosOption);
      parser.addOption(yPosOption);

      // 解析命令行参数
      parser.process(app);

      // 获取命令行参数值
      width = parser.value(widthOption).toInt();
      height = parser.value(heightOption).toInt();
      x = parser.value(xPosOption).toInt();
      y = parser.value(yPosOption).toInt();
  }

};

#endif