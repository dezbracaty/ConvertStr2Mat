#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "converttool.h"
#include "clipboardhelper.h"
#include <QQmlContext>

ClipBoardHelper clipBoardHelper;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<convertTool>("MyCvtTool",1,0,"CvtTool");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    engine.rootContext()->setContextProperty("clipBoardHelper", &clipBoardHelper);
    return app.exec();
}
