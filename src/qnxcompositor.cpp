#include <QWindow>
#include <QEvent>
#include <QVariant>
#include <QCoreApplication>
#include <QDebug> // ### remove

#include "qnxcompositor.h"

DynamicPropertyChangeWatcher::DynamicPropertyChangeWatcher(QObject *parent)
    : QObject(parent)
{
}

bool DynamicPropertyChangeWatcher::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::DynamicPropertyChange) {
        qDebug() << "@@@ dynamic property change";
        QVariant windowVariant = object->property("QNXWindowCreated");
        if (windowVariant.isValid()) {
            void *window = windowVariant.value<void *>();
            Q_ASSERT(window);
            // ### here emit signal
        } else {
            // ### should not happen
        }
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}

QnxCompositor::QnxCompositor(QObject *parent) : QObject(parent)
{
    // make sure we get informed about windows being created and destroyed
    DynamicPropertyChangeWatcher *watcher = new DynamicPropertyChangeWatcher(this);
    QCoreApplication::instance()->installEventFilter(watcher);
}
