#ifdef DEBUG_MODE
#include "main.h"

#include"wdebug.h"

int MASK = 0;
int LOGMASK = 0;

#ifdef DEBUG_MODE

WDebug::WDebug(QWidget *parent) :
  QWidget(parent)
{

    QLabel * DBGLabel = new QLabel;
    DBGLabel->setText("Stabilire:\n\n Livello di WDebug (0 - 15)");
    DBGLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QSpinBox * maskValue = new QSpinBox();
    maskValue->setValue(0);
    maskValue->setMinimum(0);
    maskValue->setMaximum(15);
    connect(maskValue, SIGNAL(valueChanged(int)),this,SLOT(changeMaskValue(int)));
    GD2(cout<<"[WDebug::WDebug] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QLabel * LDBGLabel = new QLabel;
    LDBGLabel->setText("Livello di Log (0 - 1)");
    LDBGLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

    QSpinBox * logMaskValue = new QSpinBox();
    logMaskValue->setValue(0);
    logMaskValue->setMinimum(0);
    logMaskValue->setMaximum(1);
    connect(logMaskValue, SIGNAL(valueChanged(int)), this,SLOT(changeLogMaskValue(int)));
    GD2(cout<<"[WDebug::WDebug] ho inizializzato lo spinbox  e connesso i segnali"<<endl);

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(DBGLabel);
    layout->addWidget(maskValue);
    layout->addWidget(LDBGLabel);
    layout->addWidget(logMaskValue);


    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    setLayout(layout);

}

WDebug::~WDebug()
{
    GD1(cout<<"[WDebug:~WDebug] oggetto deallocato correttamente"<<endl);
}

void WDebug::changeMaskValue(int value)
{
    assert(value >= 0);

    MASK = value;

    GD2(cout<<"[WDebug::changeMaskValue] Valore di MASK: "<<MASK<<endl);
}

void WDebug::changeLogMaskValue(int value)
{
    assert(value >= 0);

    LOGMASK = value;

    GD2(cout<<"[WDebug::changeLogMaskValue] Valore di LOGMASK: "<<LOGMASK<<endl);
}

#endif
#endif