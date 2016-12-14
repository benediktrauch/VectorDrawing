#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include <QColor>

class Draw : public QObject
{
    Q_OBJECT
public:
    explicit Draw(QObject *parent = 0);

    QColor getBorderColor() const;
    QColor getFillColor() const;

    enum Tool {selectTool, circleTool, rectTool, noTool}; ///< Tool List
    Draw::Tool getT() const;

signals:

public slots:
    void setBorderColor(const QColor &value);
    void setFillColor(const QColor &value);
    void setT(const Draw::Tool &t);

private:
    QColor borderColor;
    QColor fillColor;
    Draw::Tool _t;
};

#endif // DRAW_H