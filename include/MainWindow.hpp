//
// Created by John on 5/26/2024.
//
#include <QMainWindow>
#include <Editor.hpp>
#include <QVBoxLayout>

#ifndef LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
#define LOGICGATES_EDITOR_QT_MAINWINDOW_HPP

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void toggleDockWidget();

private:
    void setupMenuBar();
    void createNodeButton(const QString &label, QVBoxLayout *layout);

    QDockWidget *dockWidget;
    Editor *editor;
};

#endif //LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
