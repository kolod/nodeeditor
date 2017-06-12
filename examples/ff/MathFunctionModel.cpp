#include "MathFunctionModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFormLayout>

#include "ExpressionRangeData.hpp"

#include <cmath>

#include <QtCore/QDebug>

MathFunctionModel::
MathFunctionModel()
{
  createNameAndFunctions();

  _widget = new QWidget();

  auto l = new QFormLayout();

  _functionComboBox = new QComboBox;

  for (auto const & f  : _nameAndFunctions)
  {
    _functionComboBox->addItem(std::get<0>(f));
  }

  _variableLabel = new QLabel();
  _variableLabel->setMargin(3);
  _variableLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

  _rangeLabel = new QLabel();
  _rangeLabel->setMargin(3);
  _rangeLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

  l->addRow("Function:", _functionComboBox);
  l->addRow("Variable:", _variableLabel);
  l->addRow("Range:", _rangeLabel);

  _widget->setLayout(l);

  connect(_functionComboBox, SIGNAL(currentIndexChanged(int)),
          this, SLOT(onFunctionIndexChanged(int)));
}


void
MathFunctionModel::
onFunctionIndexChanged(int index)
{
  processData();
}


QJsonObject
MathFunctionModel::
save() const
{
  QJsonObject modelJson = NodeDataModel::save();

  if (_expression)
    modelJson["expression"] = _expression->expression();

  return modelJson;
}


void
MathFunctionModel::
restore(QJsonObject const &p)
{
  QJsonValue v = p["expression"];

  if (!v.isUndefined())
  {
    QString str = v.toString();

    std::vector<double> d;
    d.push_back(0.0);

    _expression = std::make_shared<ExpressionRangeData>(str, d);
    _variableLabel->setText(str);
  }
}


unsigned int
MathFunctionModel::
nPorts(PortType portType) const
{
  unsigned int result = 1;

  switch (portType)
  {
    case PortType::In:
      result = 1;
      break;

    case PortType::Out:
      result = 1;

    default:
      break;
  }

  return result;
}


NodeDataType
MathFunctionModel::
dataType(PortType, PortIndex) const
{
  return ExpressionRangeData().type();
}


std::shared_ptr<NodeData>
MathFunctionModel::
outData(PortIndex)
{
  return _expression;
}


QString
MathFunctionModel::
convertRangeToText(std::vector<double> const &range) const
{
  QString result("(");

  for (std::size_t i = 0; i < range.size() - 1; ++i)
  {
    result = result + QString::number(range[i]) + ", ";
  }

  result = result + QString::number(range.back()) + ")";

  return result;
}


std::vector<double>
MathFunctionModel::
applyFunction(std::vector<double> const &range) const
{
  std::vector<double> result;

  FunctionPtr const & f = std::get<2>(_nameAndFunctions[_functionComboBox->currentIndex()]);

  for (auto const & d : range)
  {
    result.push_back(f(d));
  }

  return result;
}


void
MathFunctionModel::
createNameAndFunctions()
{
  _nameAndFunctions.push_back(
    std::make_tuple(QString("sin()"),
                    QString("sin(%1)"),
                    static_cast<FunctionPtr>([](double d) {
    return sin(d);
  })));

  _nameAndFunctions.push_back(
    std::make_tuple(QString("cos()"),
                    QString("cos(%1)"),
                    static_cast<FunctionPtr>([](double d) {
    return cos(d);
  })));
}


void
MathFunctionModel::
processData()
{
  auto inputExpression = _inputExpression.lock();

  if (inputExpression)
  {
    QString input = inputExpression->expression();
    std::vector<double> const & inputRange = inputExpression->range();
    std::vector<double> modifiedRange      = applyFunction(inputRange);

    QString tt = std::get<1>(_nameAndFunctions[_functionComboBox->currentIndex()]);

    _expression = std::make_shared<ExpressionRangeData>(tt.arg(input), modifiedRange);

    _variableLabel->setText(_expression->expression());
    _variableLabel->adjustSize();

    _rangeLabel->setText(convertRangeToText(modifiedRange));
    _rangeLabel->adjustSize();

    emit dataUpdated(0);
  }
}


void
MathFunctionModel::
setInData(std::shared_ptr<NodeData> nodeData, PortIndex portIndex)
{
  _inputExpression = std::static_pointer_cast<ExpressionRangeData>(nodeData);

  processData();
}


QWidget *
MathFunctionModel::
embeddedWidget()
{
  return _widget;
}