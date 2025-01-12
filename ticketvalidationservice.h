#ifndef TICKETVALIDATIONSERVICE_H
#define TICKETVALIDATIONSERVICE_H

#include "httpsluzba.h"
#include "xmlticketvalidationservice.h"
#include "VDV301struktury/prestupmpv.h"

class TicketValidationService : public HttpSluzba
{
public:
    //konstruktor
    TicketValidationService();    
    explicit TicketValidationService(QString nazevSluzby, QString typSluzby, int cisloPortu, QString verze);


    //instance knihoven


    //promenne


    //funkce
    void aktualizaceObsahuSluzby(QVector<Prestup> prestupy, CestaUdaje &stav);


private:

    //instance knihoven
    XmlTicketValidationService xmlGenerator;

    //promenne
    CestaUdaje mStav;
    QVector<ZastavkaCil> mSeznamZastavek ;

    //funkce
    void aktualizaceIntProm(QVector<Prestup> prestupy, CestaUdaje &stav, QVector<ZastavkaCil> seznamZastavek);

    QVector<Prestup> mPrestupy;

private slots:
    void slotTedOdesliNaPanely();
};

#endif // TICKETVALIDATIONSERVICE_H
