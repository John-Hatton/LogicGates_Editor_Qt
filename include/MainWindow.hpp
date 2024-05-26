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

protected:
    Editor *editor;

private slots:
    void toggleDockWidget();

private:
    void setupMenuBar();
    QWidget* createNodeButtonWithImage(const QString& imagePath, const QString& buttonText);

    QDockWidget *dockWidget;

};

#endif //LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
