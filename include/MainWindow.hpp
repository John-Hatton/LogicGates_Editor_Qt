//
// Created by John on 5/26/2024.
//
#include <QMainWindow>
#include "Editor.hpp"

#ifndef LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
#define LOGICGATES_EDITOR_QT_MAINWINDOW_HPP

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void newCanvas();
    void exitApp();
    void createNode1();
    void createNode2();
    void createNode3();

private:
    Editor *editor;
    QDockWidget *dockWidget;
};


#endif //LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
