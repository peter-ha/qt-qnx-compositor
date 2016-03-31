#ifndef SAMPLECOMPOSITOR_H
#define SAMPLECOMPOSITOR_H

#include <QtQuick/QQuickView>

// ### we want to get rid of screen specific stuff in the example
#include <screen/screen.h>

#include "qnxcompositor.h"

class QProcess;

class SampleCompositor : public QObject
{
    Q_OBJECT

public:
    SampleCompositor(QObject *parent = 0);
    Q_INVOKABLE void startApp(const QString &appName);
    static SampleCompositor *instance();

private slots:
    void windowCreated(void *window);
    void windowDeleted(void *window);

private:
    QnxCompositor m_qnxCompositor;
    QQuickView m_quickView;
    QProcess *m_process1;
    QProcess *m_process2;

    static SampleCompositor *s_instance;
};

#endif // SAMPLECOMPOSITOR_H
