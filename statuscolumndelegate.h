#ifndef STATUSCOLUMNDELEGATE_H
#define STATUSCOLUMNDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>
#include "streamtablemodel.h"

#define STATUS_ICON_RADIUS      4

class StatusColumnDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit StatusColumnDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}
    
protected:

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        QStyleOptionViewItemV4 opt = option;
        initStyleOption(&opt, index);

        bool status = index.model()->data(index.model()->index(index.row(), STREAM_TABLE_COLUMNS_STATUS)).toBool();

        // draw correct background
        opt.text = "";
        QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();
        style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, opt.widget);

        QRect rect = opt.rect;
        QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
        if (cg == QPalette::Normal && !(opt.state & QStyle::State_Active)) {
            cg = QPalette::Inactive;
        }

        // set pen color
        if (opt.state & QStyle::State_Selected) {
            painter->setPen(opt.palette.color(cg, QPalette::HighlightedText));
        }
        else {
            painter->setPen(opt.palette.color(cg, QPalette::Text));
        }

        painter->setPen(QPen(Qt::NoPen));
        if (status) {
            painter->setBrush(QBrush(QColor(Qt::green)));
        }
        else {
            painter->setBrush(QBrush(QColor(Qt::red)));
        }

        painter->setRenderHint(QPainter::Antialiasing);
        painter->drawEllipse(rect.center(), STATUS_ICON_RADIUS, STATUS_ICON_RADIUS);

        // TODO: could use this (below) to add more than one line or text per cell
        // draw 2 lines of text
        //painter->drawText(QRect(rect.left(), rect.top(), rect.width(), rect.height()/2), opt.displayAlignment, line0);
        //painter->drawText(QRect(rect.left(), rect.top()+rect.height()/2, rect.width(), rect.height()/2), opt.displayAlignment, line1);
    }

    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
    {
        QSize result = QStyledItemDelegate::sizeHint(option, index);
        result.setHeight(result.height()*2);
        return result;
    }

signals:
    
public slots:
    
};

#endif // STATUSCOLUMNDELEGATE_H
