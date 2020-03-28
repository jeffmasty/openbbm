
#include <QtWidgets>

#include "loopCountDialog.h"

LoopCountDialog::LoopCountDialog(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);
    integerButton = new QPushButton();
    integerButton->setFlat(true);
    integerButton->setObjectName("loopCountButton");
    if (loopCount>1000)
        loopCount = 0;
    
    integerButton->setText(QString("Loop\n")+QString::number(loopCount));

    connect(integerButton, SIGNAL(clicked()), this, SLOT(setInteger()));
    mainLayout->addWidget(integerButton, 0, nullptr);

    setToolTip(tr("Loop Count"));
}

void LoopCountDialog::setInteger()
{
    emit sigSubWidgetClicked(); // if you click on Loop, you must select song

    bool ok;
    int i = QInputDialog::getInt(this, tr("Loop Count"),
             tr("This is how many times this \npart will loop before continuing.  \n0 means infinite."), loopCount, 0, 1000, 1, &ok);
    
    if (ok) {
       integerButton->setText(tr("Loop\n%1").arg(i));
       loopCount = i;
       emit sigSetLoopCount();
    }
}

int LoopCountDialog::getLoopCount()
{
    return loopCount;
}

void LoopCountDialog::setLoopCount(int i) {
    
    loopCount = i;
    integerButton->setText(QString("Loop\n")+QString::number(loopCount));
}