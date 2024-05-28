//
// Created by John on 5/26/2024.
//

#include "MainWindow.hpp"
#include "LogicGates/PowerSource.hpp"
#include "LogicGates/DisplayOutput.hpp"
#include "LogicGates/Gates/XorGate.hpp"
#include "LogicGates/Gates/AndGate.hpp"
#include "LogicGates/Gates/OrGate.hpp"
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

    QWidget *powerSourceWidget = createNodeButtonWithImage(":/resources/PowerSource.png", POWER_SOURCE); // Replace with Constants!
    dockLayout->addWidget(powerSourceWidget);

    QWidget *displayOutputWidget = createNodeButtonWithImage(":/resources/DisplayOutput.png", DISPLAY_OUTPUT);
    dockLayout->addWidget(displayOutputWidget);

    QWidget *xorGateWidget = createNodeButtonWithImage(":/resources/XorGate.png", XOR_GATE);
    dockLayout->addWidget(xorGateWidget);

    QWidget *andGateWidget = createNodeButtonWithImage(":/resources/AndGate.png", AND_GATE);
    dockLayout->addWidget(andGateWidget);

    QWidget *orGateWidget = createNodeButtonWithImage(":/resources/OrGate.png", OR_GATE);
    dockLayout->addWidget(orGateWidget);

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

//    // Create the edit menu
//    QMenu *editMenu = menuBar->addMenu("Edit");
//
//    QAction *undoAction = new QAction("Undo", this);
//    editMenu->addAction(undoAction);
//
//    QAction *redoAction = new QAction("Redo", this);
//    editMenu->addAction(redoAction);
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

    auto myEditor = editor;

    connect(button, &QPushButton::clicked, editor, [myEditor, buttonText, this]() {
        AbstractNode *node = nullptr;

        if (buttonText == POWER_SOURCE) {
            node = new PowerSource();
        } else if (buttonText == DISPLAY_OUTPUT) {
            node = new DisplayOutput();
        } else if (buttonText == XOR_GATE) {
            node = new XorGate();
        } else if (buttonText == AND_GATE) {
            node = new AndGate();
        } else if (buttonText == OR_GATE) {
            node = new OrGate();
        } else {
                qDebug() << "An error occurred. You did not populate the Node Name, or it was not defined in "
                << "the MainWindow class.";
                return;
        }
        myEditor->createNode(node);
    });

    return widget;
}

void MainWindow::toggleDockWidget() {
    dockWidget->setVisible(!dockWidget->isVisible());
}
