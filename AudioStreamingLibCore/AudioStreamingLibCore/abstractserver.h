#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include <QtCore>
#include <QtNetwork>
#include "tcpserver.h"
#include "common.h"
#include "audiostreaminglibcore.h"

class AbstractServer : public QObject
{
    Q_OBJECT
public:
    explicit AbstractServer(QObject *parent = 0);

signals:
    void connected(PeerData,QString);
    void disconnected(PeerData);
    void readyRead(PeerData);
    void pending(QHostAddress,QString);
    void error(QString);

public slots:
    virtual void abort(qintptr descriptor) = 0;
    virtual void setKeys(const QByteArray &private_key, const QByteArray &public_key) = 0;
    virtual void listen(quint16 port, bool auto_accept, int max_connections,
                        const QByteArray &negotiation_string,
                        const QString &id,
                        const QByteArray &password) = 0;
    virtual void stop() = 0;
    virtual void rejectNewConnection() = 0;
    virtual void acceptNewConnection() = 0;
    virtual void writeToHost(const QByteArray &data, qintptr descriptor) = 0;
    virtual int writeToAll(const QByteArray &data) = 0;
};

#endif // ABSTRACTSERVER_H
