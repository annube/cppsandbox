// tst_mytest.cpp
#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:
    void qmlEngineAvailable(QQmlEngine *engine)
    {
        engine->rootContext()->setContextProperty("myContextProperty", QVariant(true));
    }
};

QUICK_TEST_MAIN_WITH_SETUP(qmltest1, Setup)

#include "qmltest1.moc"
