//
// Created by John on 5/26/2024.
//

#include "MainWindow.hpp"
#include <QDockWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    editor = new Editor(this);
    setCentralWidget(editor);

    // Create the menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *newAction = new QAction("New", this);
    connect(newAction, &QAction::triggered, this, &MainWindow::newCanvas);
    fileMenu->addAction(newAction);

    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
    fileMenu->addAction(exitAction);

    QMenu *editMenu = menuBar->addMenu("Edit");
    QAction *undoAction = new QAction("Undo", this);
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction("Redo", this);
    editMenu->addAction(redoAction);

    // Create a dock widget for the side bar
    dockWidget = new QDockWidget("Nodes", this);
    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dockWidget->setFixedWidth(100); // Adjust the width as needed
    dockWidget->setStyleSheet("background-color: #303030;");

    QWidget *dockContent = new QWidget(dockWidget);
    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);

    QPushButton *toggleButton = new QPushButton(dockContent);
    toggleButton->setFixedSize(80, 80); // Adjust size as needed
    toggleButton->setStyleSheet("background-color: #0078D4; border: none;");
    dockLayout->addWidget(toggleButton);

    QPushButton *nodeButton1 = new QPushButton("Node 1", dockContent);
    nodeButton1->setFixedSize(80, 40);
    nodeButton1->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton1);
    connect(nodeButton1, &QPushButton::clicked, this, &MainWindow::createNode1);

    QPushButton *nodeButton2 = new QPushButton("Node 2", dockContent);
    nodeButton2->setFixedSize(80, 40);
    nodeButton2->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton2);
    connect(nodeButton2, &QPushButton::clicked, this, &MainWindow::createNode2);

    QPushButton *nodeButton3 = new QPushButton("Node 3", dockContent);
    nodeButton3->setFixedSize(80, 40);
    nodeButton3->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton3);
    connect(nodeButton3, &QPushButton::clicked, this, &MainWindow::createNode3);

    dockContent->setLayout(dockLayout);
    dockWidget->setWidget(dockContent);

    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    connect(toggleButton, &QPushButton::clicked, [this]() {
        dockWidget->setVisible(!dockWidget->isVisible());
    });
}

void MainWindow::newCanvas() {
    editor->newCanvas();
}

void MainWindow::exitApp() {
    QApplication::quit();
}

void MainWindow::createNode1() {
    editor->createNode();
}

void MainWindow::createNode2() {
    editor->createNode();
}

void MainWindow::createNode3() {
    editor->createNode();
}
