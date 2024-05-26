//
//#include <QApplication>
//#include <QWidget>
//#include <QVBoxLayout>
//#include "Editor.hpp"
//
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//
//    // Define custom palette colors
//    QPalette customPalette;
//    customPalette.setColor(QPalette::Window, QColor(30, 30, 30));
//    customPalette.setColor(QPalette::WindowText, Qt::white);
//    customPalette.setColor(QPalette::Base, QColor(45, 45, 45));
//    customPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
//    customPalette.setColor(QPalette::ToolTipBase, Qt::white);
//    customPalette.setColor(QPalette::ToolTipText, Qt::white);
//    customPalette.setColor(QPalette::Text, Qt::white);
//    customPalette.setColor(QPalette::Button, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::ButtonText, Qt::white);
//    customPalette.setColor(QPalette::BrightText, Qt::red);
//    customPalette.setColor(QPalette::Link, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::Highlight, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::HighlightedText, Qt::black);
//
//    // Apply custom palette
//    app.setPalette(customPalette);
//
//    QWidget mainWindow;
//    mainWindow.setWindowTitle("Draggable Nodes");
//    mainWindow.resize(800, 600);
//
//    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);
//
//    Editor *editor = new Editor(&mainWindow);
//    layout->addWidget(editor->getMenuBar()); // Add the menu bar
//    layout->addWidget(editor);
//
//    mainWindow.setLayout(layout);
//    mainWindow.show();
//
//    return app.exec();
//}

//#include <QApplication>
//#include <QWidget>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QPushButton>
//#include <QDockWidget>
//#include "Editor.hpp"
//#include "Sidebar.hpp"
//
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//
//    QPalette customPalette;
//    customPalette.setColor(QPalette::Window, QColor(30, 30, 30));
//    customPalette.setColor(QPalette::WindowText, Qt::white);
//    customPalette.setColor(QPalette::Base, QColor(45, 45, 45));
//    customPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
//    customPalette.setColor(QPalette::ToolTipBase, Qt::white);
//    customPalette.setColor(QPalette::ToolTipText, Qt::white);
//    customPalette.setColor(QPalette::Text, Qt::white);
//    customPalette.setColor(QPalette::Button, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::ButtonText, Qt::white);
//    customPalette.setColor(QPalette::BrightText, Qt::red);
//    customPalette.setColor(QPalette::Link, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::Highlight, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::HighlightedText, Qt::black);
//
//    app.setPalette(customPalette);
//
//    QWidget mainWindow;
//    mainWindow.setWindowTitle("Draggable Nodes");
//    mainWindow.resize(1200, 800);
//
//    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
//    QHBoxLayout *editorLayout = new QHBoxLayout();
//
//    Editor *editor = new Editor(&mainWindow);
//    Sidebar *sidebar = new Sidebar(&mainWindow);
//
//    // Create a dock widget for the sidebar
//    QDockWidget *dockWidget = new QDockWidget(&mainWindow);
//    dockWidget->setWidget(sidebar);
//    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
//    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
//    dockWidget->setTitleBarWidget(new QWidget()); // Hide the title bar
//
//    // Create a button to toggle the sidebar
//    QPushButton *toggleButton = new QPushButton("☰", &mainWindow);
//    toggleButton->setMaximumWidth(50);
//    QObject::connect(toggleButton, &QPushButton::clicked, [dockWidget]() {
//        dockWidget->setVisible(!dockWidget->isVisible());
//    });
//
//    editorLayout->addWidget(dockWidget);
//    editorLayout->addWidget(editor);
//
//    mainLayout->addWidget(editor->getMenuBar());
//    mainLayout->addWidget(toggleButton);
//    mainLayout->addLayout(editorLayout);
//
//    mainWindow.setLayout(mainLayout);
//    mainWindow.show();
//
//    // Connect sidebar signals to editor slots
//    QObject::connect(sidebar, &Sidebar::node1Clicked, editor, &Editor::createNode);
//    QObject::connect(sidebar, &Sidebar::node2Clicked, editor, &Editor::createNode);
//    QObject::connect(sidebar, &Sidebar::node3Clicked, editor, &Editor::createNode);
//
//    return app.exec();
//}

//#include <QApplication>
//#include <QWidget>
//#include <QVBoxLayout>
//#include "Editor.hpp"
//
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//
//    QPalette customPalette;
//    customPalette.setColor(QPalette::Window, QColor(30, 30, 30));
//    customPalette.setColor(QPalette::WindowText, Qt::white);
//    customPalette.setColor(QPalette::Base, QColor(45, 45, 45));
//    customPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
//    customPalette.setColor(QPalette::ToolTipBase, Qt::white);
//    customPalette.setColor(QPalette::ToolTipText, Qt::white);
//    customPalette.setColor(QPalette::Text, Qt::white);
//    customPalette.setColor(QPalette::Button, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::ButtonText, Qt::white);
//    customPalette.setColor(QPalette::BrightText, Qt::red);
//    customPalette.setColor(QPalette::Link, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::Highlight, QColor(0, 120, 212));
//    customPalette.setColor(QPalette::HighlightedText, Qt::black);
//
//    // Apply custom palette
//    app.setPalette(customPalette);
//
//    QWidget mainWindow;
//    mainWindow.setWindowTitle("Draggable Nodes");
//    mainWindow.resize(1200, 800);
//
//    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);
//
//    Editor *editor = new Editor(&mainWindow);
//    layout->addWidget(editor->getMenuBar()); // Add the menu bar
//    layout->addWidget(editor);
//
//    mainWindow.setLayout(layout);
//    mainWindow.show();
//
//    return app.exec();
//}

#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPalette customPalette;
    customPalette.setColor(QPalette::Window, QColor(30, 30, 30));
    customPalette.setColor(QPalette::WindowText, Qt::white);
    customPalette.setColor(QPalette::Base, QColor(45, 45, 45));
    customPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    customPalette.setColor(QPalette::ToolTipBase, Qt::white);
    customPalette.setColor(QPalette::ToolTipText, Qt::white);
    customPalette.setColor(QPalette::Text, Qt::white);
    customPalette.setColor(QPalette::Button, QColor(0, 120, 212));
    customPalette.setColor(QPalette::ButtonText, Qt::white);
    customPalette.setColor(QPalette::BrightText, Qt::red);
    customPalette.setColor(QPalette::Link, QColor(0, 120, 212));
    customPalette.setColor(QPalette::Highlight, QColor(0, 120, 212));
    customPalette.setColor(QPalette::HighlightedText, Qt::black);

    // Apply custom palette
    app.setPalette(customPalette);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Draggable Nodes");
    mainWindow.resize(1200, 800);
    mainWindow.show();

    return app.exec();
}