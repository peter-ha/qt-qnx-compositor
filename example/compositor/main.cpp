#include <QGuiApplication>

#include "samplecompositor.h"

int main(int argc, char **argv)
{
    SampleCompositor compositor;
    QGuiApplication app(argc, argv);
    return app.exec();
}
