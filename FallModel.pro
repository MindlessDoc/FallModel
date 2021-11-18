QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CalculationMethods/ClassicFourthRKMethod/classicfourthrkmethod.cpp \
    CalculationMethods\MidPointMethod\midpointmethod.cpp \
    CalculationMethods/EulerMethod/eulermethod.cpp \
    CalculationMethods/func.cpp \
    CalculationMethods/method.cpp \
    Functions/function.cpp \
    main.cpp \
    Graphic/mainwindow.cpp \
    Model/model.cpp \
    Graphic/graphicrect.cpp \
    PhysicalBody/physicalbody.cpp

HEADERS += \
    CalculationMethods/ClassicFourthRKMethod/classicfourthrkmethod.h \
    CalculationMethods\MidPointMethod\midpointmethod.h \
    CalculationMethods/EulerMethod/eulermethod.h \
    CalculationMethods/func.h \
    CalculationMethods/method.h \
    Functions/function.h \
    Graphic/mainwindow.h \
    Model/model.h \
    Graphic/graphicrect.h \
    PhysicalBody/physicalbody.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
