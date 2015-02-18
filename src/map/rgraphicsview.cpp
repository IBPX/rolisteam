/***************************************************************************
 *     Copyright (C) 2009 by Renaud Guezennec                             *
 *   http://renaudguezennec.homelinux.org/accueil,3.html                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify     *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QDebug>


#include "rgraphicsview.h"

RGraphicsView::RGraphicsView(Map *map)
    : QGraphicsView(map)
{
}
void RGraphicsView::keyPressEvent ( QKeyEvent * event)
{
    if(event->key ()==Qt::Key_Delete)
    {
        QList<QGraphicsItem*> list= scene()->selectedItems();
        if(list.size()>0)
        {
            foreach(QGraphicsItem* tmp, list)
            {
                scene()->removeItem(tmp);
            }
        }

    }
    QGraphicsView::keyPressEvent(event);
}
void RGraphicsView::mousePressEvent ( QMouseEvent * event)
{
    QGraphicsView::mousePressEvent (event);
}
void RGraphicsView::focusInEvent ( QFocusEvent * event )
{

    QGraphicsView::focusInEvent (event);
}
