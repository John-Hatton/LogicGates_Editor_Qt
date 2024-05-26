//
// Created by John on 5/26/2024.
//

//#include "MainWindow.hpp"
//#include <QMenuBar>
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QApplication>
//#include <QToolBar>
//
//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create the editor
//    editor = new Editor(this);
//    setCentralWidget(editor);
//
//    // Setup the menu bar
//    setupMenuBar();
//
//    // Create the dock widget for the side bar
//    dockWidget = new QDockWidget(this);
//    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
//    dockWidget->setFixedWidth(80); // Adjust the width as needed
//    dockWidget->setStyleSheet("background-color: #303030;");
//
//    QWidget *dockContent = new QWidget(dockWidget);
//    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);
//
//    // Create node buttons
//    createNodeButton("Node 1", dockLayout);
//    createNodeButton("Node 2", dockLayout);
//    createNodeButton("Node 3", dockLayout);
//
//    dockContent->setLayout(dockLayout);
//    dockWidget->setWidget(dockContent);
//
//    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
//
//    // Create a toolbar for the hamburger button
//    QToolBar *toolbar = new QToolBar(this);
//    toolbar->setMovable(false);
//    toolbar->setStyleSheet("QToolBar { background-color: rgb(30, 30, 30); }");
//
//    QPushButton *toggleButton = new QPushButton(toolbar);
//    toggleButton->setFixedSize(30, 30);
//    toggleButton->setStyleSheet("background-color: #0078D4; border: none;");
//    toolbar->addWidget(toggleButton);
//
//    addToolBar(Qt::TopToolBarArea, toolbar);
//
//    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleDockWidget);
//}
//
//void MainWindow::setupMenuBar() {
//    // Create the menu bar
//    QMenuBar *menuBar = new QMenuBar(this);
//    menuBar->setStyleSheet("QMenuBar { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item:selected { background-color: rgb(0, 120, 212); color: white; }"
//                           "QMenu { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenu::item:selected { background-color: rgb(0, 120, 212); color: white; }");
//    setMenuBar(menuBar);
//
//    // Create the file menu
//    QMenu *fileMenu = menuBar->addMenu("File");
//
//    QAction *newAction = new QAction("New", this);
//    connect(newAction, &QAction::triggered, editor, &Editor::newCanvas);
//    fileMenu->addAction(newAction);
//
//    QAction *exitAction = new QAction("Exit", this);
//    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
//    fileMenu->addAction(exitAction);
//
//    // Create the edit menu
//    QMenu *editMenu = menuBar->addMenu("Edit");
//
//    QAction *undoAction = new QAction("Undo", this);
//    editMenu->addAction(undoAction);
//
//    QAction *redoAction = new QAction("Redo", this);
//    editMenu->addAction(redoAction);
//}
//
//void MainWindow::createNodeButton(const QString &label, QVBoxLayout *layout) {
//    QPushButton *nodeButton = new QPushButton(label, this);
//    nodeButton->setFixedSize(60, 30);
//    nodeButton->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
//    layout->addWidget(nodeButton);
//    connect(nodeButton, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot
//}
//
//void MainWindow::toggleDockWidget() {
//    dockWidget->setVisible(!dockWidget->isVisible());
//}

//#include "MainWindow.hpp"
//#include <QMenuBar>
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QApplication>
//#include <QToolBar>
//#include <QIcon>
//
//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create the editor
//    editor = new Editor(this);
//    setCentralWidget(editor);
//
//    // Setup the menu bar
//    setupMenuBar();
//
//    // Create the dock widget for the side bar
//    dockWidget = new QDockWidget(this);
//    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
//    dockWidget->setFixedWidth(80); // Adjust the width as needed
//    dockWidget->setStyleSheet("background-color: #303030;");
//
//    QWidget *dockContent = new QWidget(dockWidget);
//    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);
//
//    // Create node buttons
//    createNodeButton("Node 1", dockLayout);
//    createNodeButton("Node 2", dockLayout);
//    createNodeButton("Node 3", dockLayout);
//
//    dockContent->setLayout(dockLayout);
//    dockWidget->setWidget(dockContent);
//
//    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
//
//    // Create a toolbar for the hamburger button
//    QToolBar *toolbar = new QToolBar(this);
//    toolbar->setMovable(false);
//    toolbar->setStyleSheet("QToolBar { background-color: rgb(30, 30, 30); }");
//
//    QPushButton *toggleButton = new QPushButton(toolbar);
//    toggleButton->setFixedSize(30, 30);
//    toggleButton->setStyleSheet("background-color: #303030; border: none;");
//
//    // Set the icon for the button
//    QIcon icon(":./hamburger.png");
//    toggleButton->setIcon(icon);
//    toggleButton->setIconSize(QSize(30, 30)); // Adjust the size as needed
//
//    toolbar->addWidget(toggleButton);
//
//    addToolBar(Qt::TopToolBarArea, toolbar);
//
//    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleDockWidget);
//}
//
//void MainWindow::setupMenuBar() {
//    // Create the menu bar
//    QMenuBar *menuBar = new QMenuBar(this);
//    menuBar->setStyleSheet("QMenuBar { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item:selected { background-color: rgb(0, 120, 212); color: white; }"
//                           "QMenu { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenu::item:selected { background-color: rgb(0, 120, 212); color: white; }");
//    setMenuBar(menuBar);
//
//    // Create the file menu
//    QMenu *fileMenu = menuBar->addMenu("File");
//
//    QAction *newAction = new QAction("New", this);
//    connect(newAction, &QAction::triggered, editor, &Editor::newCanvas);
//    fileMenu->addAction(newAction);
//
//    QAction *exitAction = new QAction("Exit", this);
//    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
//    fileMenu->addAction(exitAction);
//
//    // Create the edit menu
//    QMenu *editMenu = menuBar->addMenu("Edit");
//
//    QAction *undoAction = new QAction("Undo", this);
//    editMenu->addAction(undoAction);
//
//    QAction *redoAction = new QAction("Redo", this);
//    editMenu->addAction(redoAction);
//}
//
//void MainWindow::createNodeButton(const QString &label, QVBoxLayout *layout) {
//    QPushButton *nodeButton = new QPushButton(label, this);
//    nodeButton->setFixedSize(60, 30);
//    nodeButton->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
//    layout->addWidget(nodeButton);
//    connect(nodeButton, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot
//}
//
//void MainWindow::toggleDockWidget() {
//    dockWidget->setVisible(!dockWidget->isVisible());
//}

//#include "MainWindow.hpp"
//#include <QMenuBar>
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QApplication>
//#include <QToolBar>
//#include <QIcon>
//
//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create the editor
//    editor = new Editor(this);
//    setCentralWidget(editor);
//
//    // Setup the menu bar
//    setupMenuBar();
//
//    // Create the dock widget for the side bar
//    dockWidget = new QDockWidget(this);
//    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
//    dockWidget->setFixedWidth(80); // Adjust the width as needed
//    dockWidget->setStyleSheet("background-color: #303030;");
//    dockWidget->setVisible(false); // Initially hidden
//
//    QWidget *dockContent = new QWidget(dockWidget);
//    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);
//
//    // Create node buttons
//    createNodeButton("Node 1", dockLayout);
//    createNodeButton("Node 2", dockLayout);
//    createNodeButton("Node 3", dockLayout);
//
//    dockContent->setLayout(dockLayout);
//    dockWidget->setWidget(dockContent);
//
//    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
//
//    // Create a toolbar for the hamburger button
//    QToolBar *toolbar = new QToolBar(this);
//    toolbar->setMovable(false);
//    toolbar->setStyleSheet("QToolBar { background-color: rgb(30, 30, 30); }");
//
//    QPushButton *toggleButton = new QPushButton(toolbar);
//    toggleButton->setFixedSize(30, 30);
//
//    // Set the icon for the button
//    QIcon icon(":/hamburger.png");
//    toggleButton->setIcon(icon);
//    toggleButton->setIconSize(QSize(30, 30)); // Adjust the size as needed
//
//    // Make the button transparent
//    toggleButton->setStyleSheet("background-color: transparent; border: none;");
//
//    toolbar->addWidget(toggleButton);
//
//    addToolBar(Qt::TopToolBarArea, toolbar);
//
//    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleDockWidget);
//}
//
//void MainWindow::setupMenuBar() {
//    // Create the menu bar
//    QMenuBar *menuBar = new QMenuBar(this);
//    menuBar->setStyleSheet("QMenuBar { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenuBar::item:selected { background-color: rgb(0, 120, 212); color: white; }"
//                           "QMenu { background-color: rgb(30, 30, 30); color: white; }"
//                           "QMenu::item:selected { background-color: rgb(0, 120, 212); color: white; }");
//    setMenuBar(menuBar);
//
//    // Create the file menu
//    QMenu *fileMenu = menuBar->addMenu("File");
//
//    QAction *newAction = new QAction("New", this);
//    connect(newAction, &QAction::triggered, editor, &Editor::newCanvas);
//    fileMenu->addAction(newAction);
//
//    QAction *exitAction = new QAction("Exit", this);
//    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
//    fileMenu->addAction(exitAction);
//
//    // Create the edit menu
//    QMenu *editMenu = menuBar->addMenu("Edit");
//
//    QAction *undoAction = new QAction("Undo", this);
//    editMenu->addAction(undoAction);
//
//    QAction *redoAction = new QAction("Redo", this);
//    editMenu->addAction(redoAction);
//}
//
//void MainWindow::createNodeButton(const QString &label, QVBoxLayout *layout) {
//    QPushButton *nodeButton = new QPushButton(label, this);
//    nodeButton->setFixedSize(60, 30);
//    nodeButton->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
//    layout->addWidget(nodeButton);
//    connect(nodeButton, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot
//}
//
//void MainWindow::toggleDockWidget() {
//    dockWidget->setVisible(!dockWidget->isVisible());
//}

#include "MainWindow.hpp"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QToolBar>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the editor
    editor = new Editor(this);
    setCentralWidget(editor);

    // Setup the menu bar
    setupMenuBar();

    // Create the dock widget for the side bar
    dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dockWidget->setFixedWidth(80); // Adjust the width as needed
    dockWidget->setStyleSheet("background-color: #303030;");
    dockWidget->setVisible(false); // Initially hidden

    QWidget *dockContent = new QWidget(dockWidget);
    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);

    // Create node buttons
    createNodeButton("Node 1", dockLayout);
    createNodeButton("Node 2", dockLayout);
    createNodeButton("Node 3", dockLayout);

    dockContent->setLayout(dockLayout);
    dockWidget->setWidget(dockContent);

    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    // Create a toolbar for the hamburger button
    QToolBar *toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    toolbar->setStyleSheet("QToolBar { background-color: rgb(30, 30, 30); }");

    QPushButton *toggleButton = new QPushButton(toolbar);
    toggleButton->setFixedSize(30, 30);

    // Set the icon for the button
    QIcon icon(":/hamburger.png");
    toggleButton->setIcon(icon);
    toggleButton->setIconSize(QSize(30, 30)); // Adjust the size as needed

    // Make the button transparent
    toggleButton->setStyleSheet("background-color: transparent; border: none;");

    toolbar->addWidget(toggleButton);

    addToolBar(Qt::TopToolBarArea, toolbar);

    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleDockWidget);
}

void MainWindow::setupMenuBar() {
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
    connect(undoAction, &QAction::triggered, editor, &Editor::undo);
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction("Redo", this);
    connect(redoAction, &QAction::triggered, editor, &Editor::redo);
    editMenu->addAction(redoAction);
}

void MainWindow::createNodeButton(const QString &label, QVBoxLayout *layout) {
    QPushButton *nodeButton = new QPushButton(label, this);
    nodeButton->setFixedSize(60, 30);
    nodeButton->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
    layout->addWidget(nodeButton);
    connect(nodeButton, &QPushButton::clicked, editor, &Editor::createNode); // Connect to the createNode slot
}

void MainWindow::toggleDockWidget() {
    dockWidget->setVisible(!dockWidget->isVisible());
}
