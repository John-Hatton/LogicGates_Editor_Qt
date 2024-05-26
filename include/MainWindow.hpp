//
// Created by John on 5/26/2024.
//
#include <QMainWindow>
#include <Editor.hpp>

#ifndef LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
#define LOGICGATES_EDITOR_QT_MAINWINDOW_HPP

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void toggleDockWidget();

private:
    QDockWidget *dockWidget;
    Editor *editor;
};


#endif //LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
