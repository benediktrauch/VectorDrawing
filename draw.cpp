#include "draw.h"
/**
 * @brief Draw::Draw
 * @param parent
 */
Draw::Draw(QObject *parent) : QObject(parent)
{

}
/**
 * @brief Draw::getBorderColor
 * @return
 */
QColor Draw::getBorderColor() const
{
    return borderColor;
}
/**
 * @brief Draw::setBorderColor
 * @param value
 */
void Draw::setBorderColor(const QColor &value)
{
    borderColor = value;
}
/**
 * @brief Draw::getFillColor
 * @return
 */
QColor Draw::getFillColor() const
{
    return fillColor;
}
/**
 * @brief Draw::setFillColor
 * @param value
 */
void Draw::setFillColor(const QColor &value)
{
    fillColor = value;
}
/**
 * @brief Draw::getT
 * @return
 */
Draw::Tool Draw::getT() const
{
    return _t;
}
/**
 * @brief Draw::setT
 * @param t
 */
void Draw::setT(const Draw::Tool &t)
{
    _t = t;
}
