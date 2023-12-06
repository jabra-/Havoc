#ifndef HAVOCCLIENT_EVENTWORKER_H
#define HAVOCCLIENT_EVENTWORKER_H

#include <Common.h>

#include <QThread>
#include <QString>
#include <QWebSocket>

class EventWorker : public QThread
{
Q_OBJECT
    QWebSocket* WebSocket = nullptr;
    bool        shutdown  = false;

public:
    explicit EventWorker();
    ~EventWorker();

    /* run event thread */
    void run();

public slots:
    void connected();
    void closed();
    void receivedEvent( const QByteArray &message );

signals:
    /* dispatch json event */
    void availableEvent( const QByteArray& event );
    void socketClosed();
};

#endif //HAVOCCLIENT_EVENTWORKER_H
