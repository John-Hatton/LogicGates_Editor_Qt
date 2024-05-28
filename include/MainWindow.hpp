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


    QString const POWER_SOURCE = "Power Source";
    QString const DISPLAY_OUTPUT = "Display Output";
    QString const XOR_GATE = "Xor Gate";
    QString const AND_GATE = "And Gate";
    QString const OR_GATE = "Or Gate";

};

#endif //LOGICGATES_EDITOR_QT_MAINWINDOW_HPP
