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
//    dockLayout->setContentsMargins(0, 0, 0, 0);
//    dockLayout->setSpacing(2); // Set the spacing between items
//
//    auto createButtonWithImage = [&](const QString& imagePath, const QString& buttonText) {
//        QWidget *widget = new QWidget(dockContent);
//        QVBoxLayout *layout = new QVBoxLayout(widget);
//
//        QLabel *imageLabel = new QLabel(widget);
//        QPixmap pixmap(imagePath);
//        imageLabel->setPixmap(pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//        layout->addWidget(imageLabel, 0, Qt::AlignHCenter);
//
//        QPushButton *button = new QPushButton(buttonText, widget);
//        button->setFixedSize(80, 30);
//        button->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px;");
//        layout->addWidget(button);
//
//        layout->setContentsMargins(0, 0, 0, 0);
//        layout->setSpacing(2);
//        return widget;
//    };
//
//    QWidget *node1Widget = createButtonWithImage(":/resources/PowerSource.png", "Power Source");
//    dockLayout->addWidget(node1Widget);
//    connect(node1Widget->findChild<QPushButton*>(), &QPushButton::clicked, editor, &Editor::createNode);
//
//    QWidget *node2Widget = createButtonWithImage(":/resources/DisplayOutput.png", "Display Output");
//    dockLayout->addWidget(node2Widget);
//    connect(node2Widget->findChild<QPushButton*>(), &QPushButton::clicked, editor, &Editor::createNode);
//
//    QWidget *node3Widget = createButtonWithImage(":/resources/XorGate.png", "Xor Gate");
//    dockLayout->addWidget(node3Widget);
//    connect(node3Widget->findChild<QPushButton*>(), &QPushButton::clicked, editor, &Editor::createNode);
//
//    dockContent->setLayout(dockLayout);
//    dockWidget->setWidget(dockContent);
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
//    QIcon icon(":/resources/hamburger.png");
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

//#include "MainWindow.hpp"
//#include <QMenuBar>
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QApplication>
//#include <QToolBar>
//#include <QIcon>
//#include <QLabel>
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
//    dockWidget->setFixedWidth(120); // Adjust the width to 120 pixels
//    dockWidget->setStyleSheet("background-color: #303030;");
//    dockWidget->setVisible(false); // Initially hidden
//
//    QWidget *dockContent = new QWidget(dockWidget);
//    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);
//    dockLayout->setContentsMargins(2, 2, 2, 2); // Adjust margins for styling
//    dockLayout->setSpacing(2); // Set the spacing between items
//
//    QWidget *node1Widget = createNodeButtonWithImage(":/resources/PowerSource.png", "Power Source");
//    dockLayout->addWidget(node1Widget);
//
//    QWidget *node2Widget = createNodeButtonWithImage(":/resources/DisplayOutput.png", "Display Output");
//    dockLayout->addWidget(node2Widget);
//
//    QWidget *node3Widget = createNodeButtonWithImage(":/resources/XorGate.png", "Xor Gate");
//    dockLayout->addWidget(node3Widget);
//
//    dockContent->setLayout(dockLayout);
//    dockWidget->setWidget(dockContent);
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
//    QIcon icon(":/resources/hamburger.png");
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
//QWidget* MainWindow::createNodeButtonWithImage(const QString& imagePath, const QString& buttonText) {
//    QWidget *widget = new QWidget();
//    QVBoxLayout *layout = new QVBoxLayout(widget);
//    layout->setContentsMargins(0, 0, 0, 0);
//    layout->setSpacing(2); // Adjust the spacing between image and button
//
//    QLabel *imageLabel = new QLabel(widget);
//    QPixmap pixmap(imagePath);
//    imageLabel->setPixmap(pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//    layout->addWidget(imageLabel, 0, Qt::AlignHCenter);
//
//    QPushButton *button = new QPushButton(buttonText, widget);
//    button->setFixedSize(100, 30); // Adjust the button size to fit the sidebar width
//    button->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px; text-align: center;");
//    layout->addWidget(button);
//
//    connect(button, &QPushButton::clicked, editor, &Editor::createNode);
//
//    return widget;
//}
//
//void MainWindow::toggleDockWidget() {
//    dockWidget->setVisible(!dockWidget->isVisible());
//}


#include "MainWindow.hpp"
#include "LogicGates/PowerSource.hpp"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QToolBar>
#include <QIcon>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the editor
    editor = new Editor(this);
    setCentralWidget(editor);

    // Setup the menu bar
    setupMenuBar();

    // Create the dock widget for the side bar
    dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dockWidget->setFixedWidth(120); // Adjust the width to 120 pixels
    dockWidget->setStyleSheet("background-color: #303030;");
    dockWidget->setVisible(false); // Initially hidden

    QWidget *dockContent = new QWidget(dockWidget);
    QVBoxLayout *dockLayout = new QVBoxLayout(dockContent);
    dockLayout->setContentsMargins(2, 2, 2, 2); // Adjust margins for styling
    dockLayout->setSpacing(5); // Set the spacing between items

    QWidget *node1Widget = createNodeButtonWithImage(":/resources/PowerSource.png", "Power Source");
    dockLayout->addWidget(node1Widget);

    QWidget *node2Widget = createNodeButtonWithImage(":/resources/DisplayOutput.png", "Display Output");
    dockLayout->addWidget(node2Widget);

    QWidget *node3Widget = createNodeButtonWithImage(":/resources/XorGate.png", "Xor Gate");
    dockLayout->addWidget(node3Widget);

    dockLayout->addStretch(); // Ensure items are pushed to the top

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
    QIcon icon(":/resources/hamburger.png");
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
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction("Redo", this);
    editMenu->addAction(redoAction);
}

QWidget* MainWindow::createNodeButtonWithImage(const QString& imagePath, const QString& buttonText) {
    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(2); // Adjust the spacing between image and button

    QLabel *imageLabel = new QLabel(widget);
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    layout->addWidget(imageLabel, 0, Qt::AlignHCenter);

    QPushButton *button = new QPushButton(buttonText, widget);
    button->setFixedSize(100, 30); // Adjust the button size to fit the sidebar width
    button->setStyleSheet("background-color: #0078D4; color: white; border: none; padding: 5px; text-align: center;");
    layout->addWidget(button);

    AbstractNode* node;

    if (buttonText == "Power Source")
    {
        node = new PowerSource();
    }
    else
    {
        node = nullptr;
        qDebug() << "An error occurred. You did not populate the Node Name, or it was not defined in " <<
                    "the MainWindow class." ;
    }

    auto myEditor = editor;

    connect(button, &QPushButton::clicked, editor, [myEditor, node]() {

        myEditor->createNode(node);
    });

    return widget;
}

void MainWindow::toggleDockWidget() {
    dockWidget->setVisible(!dockWidget->isVisible());
}
