#ifndef QNXCOMPOSITOR_H
#define QNXCOMPOSITOR_H

#include <QObject>

class QWindow;
class QEvent;

class DynamicPropertyChangeWatcher : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(DynamicPropertyChangeWatcher)

public:
    DynamicPropertyChangeWatcher(QObject *parent);

protected:
    bool eventFilter(QObject *object, QEvent *event);
};


class QnxCompositor : public QObject
{
    Q_OBJECT
public:
    explicit QnxCompositor(QObject *parent = 0);

signals:
    void windowCreated(QWindow *window);
    void windowDeleted(QWindow *window);

public slots:
};

#endif // QNXCOMPOSITOR_H
