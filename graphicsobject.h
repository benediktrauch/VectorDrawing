#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QObject>
#include <QString>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class QGraphicsItem;

/**
 * @brief The GraphicsObject class
 */
class GraphicsObject : public QObject
{
    Q_OBJECT

public:
    explicit GraphicsObject(QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    virtual QGraphicsItem *graphicsItem() const;

    qreal posX() const;
    void setPosX(const qreal &posX);

    qreal posY() const;
    void setPosY(const qreal &posY);

    QColor borderColor() const;
    void setBorderColor(const QColor &borderColor);

    QColor fillColor() const;
    void setFillColor(const QColor &fillColor);

    //virtual QString toString() = 0;

signals:

public slots:

protected:

private:
    QString m_name; ///< Graphics Object Name
    qreal m_posX; ///< Graphics Object X-Position
    qreal m_posY; ///< Graphics Object Y-Position
    QColor m_borderColor; ///< Graphics Object Border Color
    QColor m_fillColor; ///< Graphics Object Fill Color
    static unsigned long m_graphicsObjectCounter; ///< Counter for Graphics Objects
    QGraphicsItem *m_graphicsItem;
};

#endif // GRAPHICSOBJECT_H
