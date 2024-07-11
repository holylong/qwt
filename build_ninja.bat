
set QT_DIR=D:\Qt\5.15.2\msvc2019_64
set Qt5_DIR=D:\Qt\5.15.2\msvc2019_64
set PATH=D:\Qt\5.15.2\msvc2019_64\bin;%PATH%
cmake -GNinja -Bbuild_ninja -DQt5_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5 -DQt5Widgets_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5Widgets ^
-DQt5Core_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5Core ^
-DQt5Gui_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5Gui ^
-DQt5Network_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5Network -DQT_DEBUG_FIND_PACKAGE=ON ^
-DQt5Test_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5Test -DQt5OpenGLWidgets_DIR=D:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5OpenGLWidgets
cmake --build build_ninja 