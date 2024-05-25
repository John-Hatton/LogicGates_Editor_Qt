
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include "Editor.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Define custom palette colors
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

    QWidget mainWindow;
    mainWindow.setWindowTitle("Draggable Nodes");
    mainWindow.resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);

    Editor *editor = new Editor(&mainWindow);
    layout->addWidget(editor->getMenuBar()); // Add the menu bar
    layout->addWidget(editor);

    mainWindow.setLayout(layout);
    mainWindow.show();

    return app.exec();
}