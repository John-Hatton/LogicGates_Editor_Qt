//
// Created by John on 5/24/2024.
//
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QAction>
#include <QLabel>

#ifndef COLORSTEALQT_EDITOR_HPP
#define COLORSTEALQT_EDITOR_HPP

#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QAction>
#include <QLabel>

class Editor : public QGraphicsView {
Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    QMenuBar* getMenuBar() const;

private slots:
    void createNode();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QGraphicsScene *scene;
    QMenuBar *menuBar;
    QAction *newNodeAction;
    QLabel *positionLabel;
    double scaleFactor;
    bool isPanning;
    QPointF panStartPos;
    QPointF viewCenter;  // Store the center position

    void updatePositionLabel();

    void updateNodesPosition(const QPointF &delta);
};
#endif //COLORSTEALQT_EDITOR_HPP
