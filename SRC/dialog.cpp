#include "dialog.h"
#include "ui_dialog.h"

static std::shared_ptr<DataModelRegistry> registerDataModels()
{
  auto ret = std::make_shared<DataModelRegistry>();
  // models are registered here !!!
  return ret;
}

#include <QtCore>
///////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    //-----------------------------------
    QVBoxLayout *l = new QVBoxLayout(ui->FlowField);
    auto scene = new FlowScene(registerDataModels(),ui->FlowField);
    l->addWidget(new FlowView(scene));
    //l->setContentsMargins(0, 0, 0, 0);
    //l->setSpacing(0);
    //-----------------------------------
    //capWebcam.open(0);
    //
    //if (capWebcam.isOpened() == false)
    //{
    //    ui->txtXYRadius->appendPlainText("error!!! webcam 0 not found  !! \r\n");
    //    return;
    //}

    //tmrTimer = new QTimer(this);
    //connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
    //tmrTimer->start(20);
}

//////////////////////////////////////////////////////////////////////////////
Dialog::~Dialog()
{
    delete ui;
}

/////////////////////////////////////////////////////////////////////////////
void Dialog::processFrameAndUpdateGUI()
{
    //capWebcam.read(matOriginal);
    //if (matOriginal.empty()==true) return;


}

/////////////////////////////////////////////////////////////////////////////
void Dialog::on_btnPauseResume_clicked()
{

}
