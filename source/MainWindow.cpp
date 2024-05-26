//
// Created by John on 5/26/2024.
//

#include "MainWindow.hpp"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the editor
    editor = new Editor(this);
    setCentralWidget(editor);

    // Create the menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    menuBar->setStyleSheet("QMenuBar { background-color: rgb(30, 30, 30); color: white; }"
                           "QMenuBar::item { background-color: rgb(30, 30, 30); color: white; }"
                           "QMenuBar::item:selected { background-color: rgb(0, 120, 212); color: white; }"
                           "QMenu { background-color: rgb(30, 30, 30); color: white; }"
                           "QMenu::item:selected { background-color: rgb(0, 120, 212); color: white; }");
    setMenuBar(menuBar);

    // Create the file menu
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = new QAction("New", this);
    connect(newAction, &QAction::triggered, editor, &Editor::newCanvas);
    fileMenu->addAction(newAction);

    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    fileMenu->addAction(exitAction);

    // Create the edit menu
    QMenu *editMenu = menuBar->addMenu("Edit");

    QAction *undoAction = new QAction("Undo", this);
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction("Redo", this);
    editMenu->addAction(redoAction);

    // Create the dock widget for the side bar
    dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dockWidget->setFixedWidth(80); // Adjust the width as needed
    dockWidget->setStyleSheet("background-color: #303030;");

    QWidget *dockContent = new QWidget(dockWidget);
    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);

    QPushButton *nodeButton1 = new QPushButton("Node 1", dockContent);
    nodeButton1->setFixedSize(60, 30);
    nodeButton1->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton1);
    connect(nodeButton1, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot

    QPushButton *nodeButton2 = new QPushButton("Node 2", dockContent);
    nodeButton2->setFixedSize(60, 30);
    nodeButton2->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton2);
    connect(nodeButton2, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot

    QPushButton *nodeButton3 = new QPushButton("Node 3", dockContent);
    nodeButton3->setFixedSize(60, 30);
    nodeButton3->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    dockLayout->addWidget(nodeButton3);
    connect(nodeButton3, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot

    dockContent->setLayout(dockLayout);
    dockWidget->setWidget(dockContent);

    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    // Create a toolbar for the hamburger button
    QToolBar *toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    toolbar->setStyleSheet("QToolBar { background-color: rgb(30, 30, 30); }");

    QPushButton *toggleButton = new QPushButton(toolbar);
    toggleButton->setFixedSize(30, 30);
    toggleButton->setStyleSheet("background-color: #0078D4; border: none;");
    toolbar->addWidget(toggleButton);

    addToolBar(Qt::TopToolBarArea, toolbar);

    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleDockWidget);
}

void MainWindow::toggleDockWidget() {
    dockWidget->setVisible(!dockWidget->isVisible());
}