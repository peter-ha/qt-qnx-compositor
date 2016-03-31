#include <QGuiApplication>

#include "samplecompositor.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    SampleCompositor compositor;
    return app.exec();
}
