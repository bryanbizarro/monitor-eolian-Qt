#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
#include <qcgaugewidget.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void readSerial();
    void updateValues(QString name, QString valor, int posicion = 0);

    void makeplot();
    void maximavelocidad();

    QString barTempStyle(double value);
    QString barVoltStyle(double value);
    QString barAmpStyle(double value);
    QString barSoCStyle(double value);

    void SetupProgressbars();
    void SetupSpeedometer();
    void SetupPlots();
    void SetupArduino();
    void GetProductVendorID();

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;      // Arduino:9025 |Xbee:1027
    static const quint16 arduino_uno_product_id = 67;       // Arduino:67   |Xbee:24577
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;

    double bms_temp[30];
    double bms_volt[30];
    double bms_amp[30];

    double amperaje1;
    double voltaje1;
    double amperaje2;
    double voltaje2;
    double speed;
    double torque1;

    double maxvel;
    double maxvelaux;

    QcGaugeWidget * mSpeedGauge;
    QcNeedleItem *mSpeedNeedle;

    double carga_restante=87;

    QString safe    = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #29D600,stop: 0.4999 #68d600,stop: 0.5 #68d600,stop: 1 #93d600 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString safe1   = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #93d600,stop: 0.4999 #ecee00,stop: 0.5 #ecee00,stop: 1 #f0ff00 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString danger  = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #f0ff00,stop: 0.4999 #ffb400,stop: 0.5 #ffb400,stop: 1 #ff8100 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString danger1 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #ff8100,stop: 0.4999 #ff4000,stop: 0.5 #ff4000,stop: 1 #ff0000 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";

    QString safe11    = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #93d600,stop: 0.4999 #68d600,stop: 0.5 #68d600,stop: 1 #29D600 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString safe111   = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #f0ff00,stop: 0.4999 #ecee00,stop: 0.5 #ecee00,stop: 1 #93d600 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString danger11  = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #ff8100,stop: 0.4999 #ffb400,stop: 0.5 #ffb400,stop: 1 #f0ff00 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";
    QString danger111 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #ff0000,stop: 0.4999 #ff4000,stop: 0.5 #ff4000,stop: 1 #ff8100 );border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px; border: 0px solid black;}QProgressBar{border: 0px;background: white; padding: 1px; text-align: center;border-top-left-radius: 3px ;border-top-right-radius: 3px;border-bottom-right-radius: 3px ;border-bottom-left-radius: 3px;font: 75 10pt;}";


};

#endif // DIALOG_H