#include <QWindow>
#include <QEvent>
#include <QVariant>
#include <QCoreApplication>
#include <QDebug> // ### remove

#include <screen/screen.h>

#include "qnxcompositor.h"

DynamicPropertyChangeWatcher::DynamicPropertyChangeWatcher(QObject *parent)
    : QObject(parent)
{
}

bool DynamicPropertyChangeWatcher::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::DynamicPropertyChange) {
        QVariant windowVariant = object->property("QNXWindowCreated");
        Q_ASSERT(windowVariant.isValid());
        void *window = windowVariant.value<void *>();
        Q_ASSERT(window);
        const screen_window_t nativeWindow =
                reinterpret_cast<screen_window_t>(window);
        QnxCompositor *compositor = qobject_cast<QnxCompositor *>(parent());
        emit compositor->windowCreated(window);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}

QnxCompositor::QnxCompositor(QObject *parent) : QObject(parent)
{
    // init needs a QCoreApplication instance, so call it through
    // the event loop
    QMetaObject::invokeMethod(this, "init", Qt::QueuedConnection);
}

void QnxCompositor::init()
{
    // make sure we get informed about windows being created and destroyed
    DynamicPropertyChangeWatcher *watcher = new DynamicPropertyChangeWatcher(this);
    Q_ASSERT_X(QCoreApplication::instance() != Q_NULLPTR, "QnxCompositor",
               "cannot create QnxCompositor before QCoreApplication");
    QCoreApplication::instance()->installEventFilter(watcher);
}
