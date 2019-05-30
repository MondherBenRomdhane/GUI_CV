#include "dialog.h"
#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>
#include <nodes/TypeConverter>

#include <nodes/DataModelRegistry>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>


#include <QApplication>


using QtNodes::ConnectionStyle;
using QtNodes::FlowScene;
using QtNodes::DataModelRegistry;
using QtNodes::FlowView;



static void setStyle()
{
  ConnectionStyle::setConnectionStyle(
  R"(
  {
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": "black",
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,

      "UseDataDefinedColors": true
    }
  }
  )");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    //QWidget mainWidget;
    setStyle();

    QVBoxLayout *l = new QVBoxLayout(&w);
    //auto scene = new FlowScene(registerDataModels(), &w);
    //l->addWidget(new FlowView(scene));
    //l->setContentsMargins(0, 0, 0, 0);
    //l->setSpacing(0);

    w.show();
    //mainWidget.show();

    return a.exec();
}
