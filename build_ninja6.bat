
set QT_DIR=D:\Qt\6.6.3\msvc2019_64
set Qt6_DIR=D:\Qt\6.6.3\msvc2019_64
set PATH=D:\Qt\6.6.3\msvc2019_64\bin;%PATH%

cmake -GNinja -Bbuild_ninja6 -DQt6_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6 -DQt6Widgets_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6Widgets ^
-DQt6Core_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6Core ^
-DQt6Gui_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6Gui ^
-DQt6Network_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6Network -DQT_DEBUG_FIND_PACKAGE=ON ^
-DQt6Test_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6Test -DQt6OpenGLWidgets_DIR=D:\Qt\6.6.3\msvc2019_64\lib\cmake\Qt6OpenGLWidgets

cmake --build build_ninja6