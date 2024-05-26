//
// Created by John on 5/26/2024.
//

#include <Sidebar.hpp>


Sidebar::Sidebar(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *node1Button = new QPushButton("Node 1", this);
    QPushButton *node2Button = new QPushButton("Node 2", this);
    QPushButton *node3Button = new QPushButton("Node 3", this);

    layout->addWidget(node1Button);
    layout->addWidget(node2Button);
    layout->addWidget(node3Button);
    layout->addStretch();

    connect(node1Button, &QPushButton::clicked, this, &Sidebar::handleNode1Clicked);
    connect(node2Button, &QPushButton::clicked, this, &Sidebar::handleNode2Clicked);
    connect(node3Button, &QPushButton::clicked, this, &Sidebar::handleNode3Clicked);
}

void Sidebar::handleNode1Clicked() {
    emit node1Clicked();
}

void Sidebar::handleNode2Clicked() {
    emit node2Clicked();
}

void Sidebar::handleNode3Clicked() {
    emit node3Clicked();
}
