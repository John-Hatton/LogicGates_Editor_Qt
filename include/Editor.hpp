//
// Created by John on 5/24/2024.
//
#include "AbstractNode.hpp"
#include <Connection.hpp>
#include <ConnectionPoint.hpp>


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QAction>
#include <QLabel>


#include <QDockWidget>
#include <QUndoStack>
#include <QRubberBand>


#pragma once //LOGICGATES_EDITOR_QT_EDITOR_HPP

//class Editor : public QGraphicsView {
//Q_OBJECT
//
//public:
//    Editor(QWidget *parent = nullptr);
//
//protected:
//    void resizeEvent(QResizeEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
//    void wheelEvent(QWheelEvent *event) override;
//    void drawBackground(QPainter *painter, const QRectF &rect) override;
//    void updateNodesPosition(const QPointF &delta);
//
//private slots:
//    void newFile();
//    void exitApp();
//
//private:
//    void updatePositionLabel();
//    void updateConnections();
//    void startRubberBandSelection(const QPoint &pos);
//    void updateRubberBandSelection(const QPoint &pos);
//    void finishRubberBandSelection();
//
//    QGraphicsScene *scene;
//    QAction *newNodeAction;
//    QAction *newFileAction;
//    QAction *exitAction;
//    QLabel *positionLabel;
//    QPointF viewCenter;
//    qreal scaleFactor;
//    bool isPanning;
//    bool isRubberBandSelecting;
//    QPoint panStartPos;
//    QPoint rubberBandStartPos;
//    QRubberBand *rubberBand;
//    QVector<Connection*> connections;
//    QGraphicsLineItem *currentConnection;
//    ConnectionPoint *startPoint;
//    ConnectionPoint *hoveredPoint;
//    QPointF dragStartPos;
//
//    QUndoStack *undoStack;
//
//public slots:
//    void createNode();
//    void newCanvas();
//    void startConnection(ConnectionPoint *point);
//    void updateConnection(const QPointF &pos);
//    void endConnection(ConnectionPoint *point);
//    void cancelConnection();
//    void finalizeConnection(ConnectionPoint *start, ConnectionPoint *end);
//
//    void undo();
//    void redo();
//};

class Editor : public QGraphicsView {
Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void keyPressEvent(QKeyEvent *event) override;
    void updateNodesPosition(const QPointF &delta);

public slots:
    void newFile();
    void exitApp();
    void createNode(AbstractNode* node);
    void newCanvas();
    void startConnection(ConnectionPoint *point);
    void updateConnection(const QPointF &pos);
    void endConnection(ConnectionPoint *point);
    void cancelConnection();
    void finalizeConnection(ConnectionPoint *start, ConnectionPoint *end);


private:
    void updatePositionLabel();
    void updateConnections();
    void startRubberBandSelection(const QPoint &pos);
    void updateRubberBandSelection(const QPoint &pos);
    void finishRubberBandSelection();

    QGraphicsScene *scene;
    QAction *newNodeAction;
    QAction *newFileAction;
    QAction *exitAction;
    QLabel *positionLabel;
    QPointF viewCenter;
    qreal scaleFactor;
    bool isPanning;
    bool isRubberBandSelecting;
    QPointF panStartPos;
    QPoint rubberBandStartPos;
    QRubberBand *rubberBand;
    QVector<Connection*> connections;
    QGraphicsLineItem *currentConnection;
    ConnectionPoint *startPoint;
    ConnectionPoint *hoveredPoint;
    QPointF dragStartPos;
    ConnectionPoint* lastHoveredPoint;

};
