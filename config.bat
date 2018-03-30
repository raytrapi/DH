@echo off
del /S /Q ..\build\*.*

@set QT5_PATH=E:\Program Files\QT\5.7\msvc2015_64
@set QT5_BIN_DIR=%QT5_PATH%\bin

set PATH=%QT5_BIN_DIR%;%PATH%

cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release 	-DCMAKE_INSTALL_PREFIX=../install ..