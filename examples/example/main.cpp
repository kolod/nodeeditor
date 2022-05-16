#include <NodeData>
#include <FlowScene>
#include <FlowView>
#include <DataModelRegistry>

#include <QtWidgets/QApplication>

#include "TextSourceDataModel.h"
#include "TextDisplayDataModel.h"

using QtNodes::DataModelRegistry;
using QtNodes::FlowView;
using QtNodes::FlowScene;

static std::shared_ptr<DataModelRegistry>
registerDataModels()
{
  auto ret = std::make_shared<DataModelRegistry>();

  ret->registerModel<TextSourceDataModel>();

  ret->registerModel<TextDisplayDataModel>();

  return ret;
}


int
main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  FlowScene scene(registerDataModels());

  FlowView view(&scene);

  view.setWindowTitle("Node-based flow editor");
  view.resize(800, 600);
  view.show();

  return app.exec();
}
