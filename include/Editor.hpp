//
// Created by John on 5/24/2024.
//
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <ConnectionPoint.hpp>
#include <Connection.hpp>
#include <QDockWidget>

#ifndef LOGICGATES_EDITOR_QT_EDITOR_HPP
#define LOGICGATES_EDITOR_QT_EDITOR_HPP


class Editor : public QGraphicsView {
Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    QMenuBar *getMenuBar() const;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void updateNodesPosition(const QPointF &delta);

private:
    void updatePositionLabel();
    void updateConnections();

    QGraphicsScene *scene;
    QMenuBar *menuBar;
    QLabel *positionLabel;
    QPointF viewCenter;
    qreal scaleFactor;
    bool isPanning;
    QPointF panStartPos;
    QVector<Connection*> connections;
    QGraphicsLineItem *currentConnection;
    ConnectionPoint *startPoint;
    ConnectionPoint *hoveredPoint;

public slots:
    void createNode();
    void newCanvas();
    void startConnection(ConnectionPoint *point);
    void updateConnection(const QPointF &pos);
    void endConnection(ConnectionPoint *point);
    void cancelConnection();
    void finalizeConnection(ConnectionPoint *start, ConnectionPoint *end);
};


#endif //LOGICGATES_EDITOR_QT_EDITOR_HPP
