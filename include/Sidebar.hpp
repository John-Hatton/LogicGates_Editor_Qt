//
// Created by John on 5/26/2024.
//

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#ifndef LOGICGATES_EDITOR_QT_SIDEBAR_HPP
#define LOGICGATES_EDITOR_QT_SIDEBAR_HPP


class Sidebar : public QWidget {
    Q_OBJECT

public:
    Sidebar(QWidget *parent = nullptr);

    signals:
    void node1Clicked();
    void node2Clicked();
    void node3Clicked();

private slots:
    void handleNode1Clicked();
    void handleNode2Clicked();
    void handleNode3Clicked();
};


#endif //LOGICGATES_EDITOR_QT_SIDEBAR_HPP
