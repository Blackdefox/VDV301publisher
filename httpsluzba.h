#ifndef HTTPSLUZBA_H
#define HTTPSLUZBA_H

#include <QObject>
#include <QtXml>
#include <QtHttpServer>
#include <QMap>

#include "QtZeroConf/qzeroconf.h"


#include "httpserverpublisher.h"
#include "subscriber.h"

#include "VDV301struktury/cestaudaje.h"
#include "VDV301struktury/zastavkacil.h"




class HttpSluzba: public QObject
{
    Q_OBJECT
public:
    HttpSluzba(QString nazevSluzby, QString typSluzby, int cisloPortu, QString verze);

    //struktury
    QVector<Subscriber> seznamSubscriberu;
    QString globVerze="1.0";
    QString nazevSluzbyInterni="";

    //funkce
    void PostDoDispleje(QUrl adresaDispleje, QString dataDoPostu);
    int nastavObsahTela(QString klic, QString obsah);
    void aktualizaceIntProm(QDomDocument prestupyDomDocument, CestaUdaje &stav, QVector<ZastavkaCil> interniSeznamZastavek);
    void bonjourStartKomplet();

    //funkce subscriber
    QString novySubscriber(Subscriber subscriber);
    int jeSubscriberNaSeznamu(QVector<Subscriber> seznam, Subscriber prvek);
    int odstranitSubscribera(int index);

    QByteArray vyrobSubscribeResponseBody(int vysledek);  //nepouzito

    //casovac pro periodicke odesilani dat
    QTimer *timer = new QTimer(this);


    ~HttpSluzba();


    QString StringToNmToken(QString vstup);
    int cisloPortu() const;
    void setCisloPortu(int newCisloPortu);

private:
    //instance knihoven
    QZeroConf zeroConf;
    HttpServerPublisher httpServerPublisher ;
    QNetworkAccessManager *manager2 = new QNetworkAccessManager();

    //promenne
    int mCisloPortu=0;
    QString mTypSluzby="_ibisip_http._tcp";

    //funkce
    void bonjourStartPublish(QString nazevSluzby, QString typSluzby, int port, QString verze, QZeroConf &instanceZeroConf);
    void zastavBonjourSluzbu();

    QByteArray vyrobHlavickuGet(); //nepouzito
    QString vyrobHlavickuSubscribe();
protected:

    QMap<QString,QString> obsahTelaPole; //obsahuje payload a klíč, pod kterým je uložený
    int asocPoleDoServeru(QMap<QString, QString> pole);

public slots:
    void slotVypisObsahRequestu(QByteArray vysledek, QString struktura);
    void slotVypisChybuZeroConfig();
    void slotStop(bool parametr);
    void slotStartDnsSd(bool parametr);
    void slotVymazSubscribery();
    void slotZastavCasovac();
    void slotServerReady(int portVstup);
    void slotStartServer();


private slots:
    void slotVyprseniCasovace(); //nepouzito
    void slotPrislaOdpovedNaPost(QNetworkReply *reply);

    void slotSluzbaPublikovana();
signals:
    void signalPridejSubscribera(QUrl adresaSubscribera); //nepouzito
    void signalVypisSubscriberu(QVector<Subscriber> seznamSubscriberuInt);
    void signalStav(bool stav);
    void signalStart(); //nepouzito
    void signalStop(); //nepouzio
    void signalOdpovedNaPost(QNetworkReply *reply);
    void signalZmenaParametru(QMap<QString,QString> hodnoty);
    void signalSluzbaPublikovana(QString nazevSluzby);



};

#endif // HTTPSLUZBA_H
