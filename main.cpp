#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "processcalculating.h"
#include <QQmlContext>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/font/Open_Sans.ttf") == -1)
        qDebug() << "Failed to load Open_Sans.ttf";
    QQmlApplicationEngine engine; //движок qml
    ProcessCalculating processCalculating;  //ядро приложения

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("processCalculating", &processCalculating);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    //QFontDatabase::addApplicationFont(":/font/ofont.ru_Open Sans.ttf)");
    return app.exec();
}


