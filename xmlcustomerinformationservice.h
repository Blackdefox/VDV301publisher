#ifndef XMLCUSTOMERINFORMATIONSERVICE_H
#define XMLCUSTOMERINFORMATIONSERVICE_H
#include "xmlcommon.h"
#include <QObject>

class XmlCustomerInformationService : XmlCommon
{
public:
    XmlCustomerInformationService();
   // QString AllData1_0(QVector<ZastavkaCil> docasnySeznamZastavek, QString doorState, QString locationState, QVector<PrestupMPV> prestupy, CestaUdaje stav);

    QString AllData1_0(QVector<Spoj> seznamSpoju, QVector<Prestup> prestupy, CestaUdaje stav);
    QString AllData2_2CZ1_0(QVector<Spoj> seznamSpoju, QVector<Prestup> prestupy, CestaUdaje stav);
    QString AllData_empty_1_0();
    QString AllData_empty2_2CZ1_0();

    QString CurrentDisplayContent1_0(int poradi, QVector<ZastavkaCil> docasnySeznamZastavek, CestaUdaje stav);

    QString CurrentDisplayContent2_2CZ1_0(int poradi, QVector<ZastavkaCil> docasnySeznamZastavek, CestaUdaje stav);

    //rozdelano
    QString CurrentDisplayContent2_4(int poradi, QVector<ZastavkaCil> docasnySeznamZastavek, CestaUdaje stav);
    QString AllData2_4(QVector<Spoj> seznamSpoju, QVector<Prestup> prestupy, CestaUdaje stav);
};

#endif // XMLCUSTOMERINFORMATIONSERVICE_H
