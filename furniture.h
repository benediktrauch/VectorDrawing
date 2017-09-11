#ifndef FURNITURE_H
#define FURNITURE_H

#include <QGraphicsItem>
#include <QObject>

class Furniture : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Furniture(QGraphicsItem *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QPointF pos() const;
    void setPos(const QPointF &pos);

    QColor borderColor() const;
    void setBorderColor(const QColor &borderColor);

    QColor fillColor() const;
    void setFillColor(const QColor &fillColor);

    qreal width() const;
    void setWidth(const qreal &width);

    qreal height() const;
    void setHeight(const qreal &height);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    QString m_name;
    QPointF m_pos;
    QColor m_borderColor; ///< Graphics Object Border Color
    QColor m_fillColor; ///< Graphics Object Fill Color
    qreal m_width;
    qreal m_height;

    Furniture *myItem;

};

#endif // FURNITURE_H
