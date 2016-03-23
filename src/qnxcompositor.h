#ifndef QNXCOMPOSITOR_H
#define QNXCOMPOSITOR_H

#include <QObject>

class QWindow;

class QnxCompositor : public QObject
{
    Q_OBJECT
public:
    explicit QnxCompositor(QObject *parent = 0);

signals:
    void windowCreated(QWindow *window);

public slots:
};

#endif // QNXCOMPOSITOR_H
