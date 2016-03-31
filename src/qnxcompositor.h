#ifndef QNXCOMPOSITOR_H
#define QNXCOMPOSITOR_H

#include <QObject>

#include <screen/screen.h>

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
    void windowCreated(void *nativeWindow);
    void windowDeleted(void *nativeWindow);

private:
    Q_INVOKABLE void init();
};

#endif // QNXCOMPOSITOR_H
