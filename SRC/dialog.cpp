#include "dialog.h"
#include "ui_dialog.h"

#include <QtCore>
///////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    capWebcam.open(0);

    if (capWebcam.isOpened() == false)
    {
        ui->txtXYRadius->appendPlainText("error!!! webcam 0 not found  !! \r\n");
        return;
    }

    tmrTimer = new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
    tmrTimer->start(20);
}

//////////////////////////////////////////////////////////////////////////////
Dialog::~Dialog()
{
    delete ui;
}

/////////////////////////////////////////////////////////////////////////////
void Dialog::processFrameAndUpdateGUI()
{
    capWebcam.read(matOriginal);
    if (matOriginal.empty()==true) return;


}

/////////////////////////////////////////////////////////////////////////////
void Dialog::on_btnPauseResume_clicked()
{

}
