#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>
#include <nodes/TypeConverter>

#include <nodes/DataModelRegistry>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>

using QtNodes::ConnectionStyle;
using QtNodes::FlowScene;
using QtNodes::DataModelRegistry;
using QtNodes::FlowView;



//----------------------------------------------------------
namespace Ui {
class Dialog;
}
//----------------------------------------------------------

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void processFrameAndUpdateGUI();

private slots:
    void on_btnPauseResume_clicked();

private:
    Ui::Dialog *ui;
    cv::VideoCapture capWebcam;
    cv::Mat matOriginal;
    cv::Mat matProcessed;

    QImage qimgOriginal;
    QImage qimgProcessed;

    std::vector<cv::Vec3f> vecCircles;
    std::vector<cv::Vec3f> ::iterator ittCircles;

    QTimer* tmrTimer;
};

#endif // DIALOG_H
