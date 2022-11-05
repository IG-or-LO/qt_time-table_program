#include "dialog.h"

Dialog::Dialog(QWidget* parent):QDialog(parent)
{
    answer=new QLabel;
    layout_main=new  QVBoxLayout;
    layout_h=new  QHBoxLayout;
    layout_v=new  QVBoxLayout;

    applyBtn = new QPushButton( "Apply" );
    cancelBtn = new QPushButton( "Cancel" );

}

Dialog::~Dialog(){

}

void Dialog::delete_or_not_dialog()
{
    this->setFixedSize(400,150);
    setWindowTitle(tr("Подтверждение"));

   layout_v->addWidget(answer);
   answer->setText("Уверены что хотите удалить все данные из таблицы?");
   answer->setStyleSheet(stylehelper::getLableDialogStyle());
//конпка apply
   applyBtn->setStyleSheet(stylehelper::getButtonDialogApplyStyle());
   applyBtn->setFixedSize(btnSize);
   connect(applyBtn,&QPushButton::clicked,this,&Dialog::accept);
   connect(applyBtn,&QPushButton::clicked,this,&QDialog::close);
   applyBtn->setDefault(true);
   layout_h->addWidget( applyBtn);
//кнопка cancel
   cancelBtn->setStyleSheet(stylehelper::getButtonDialogCloseStyle());
   cancelBtn->setFixedSize(btnSize);
   connect( cancelBtn, &QPushButton::clicked,this, &QDialog::close );

   layout_h->addWidget( cancelBtn );
   //add layout


   layout_main->addLayout(layout_v);
   layout_main->addLayout(layout_h);
   setLayout(layout_main);
}

void Dialog::help_dialog()
{
     this->setFixedSize(500,250);
    setWindowTitle(tr("Помощь"));

//qlable
    answer->setStyleSheet(stylehelper::getLableDialogStyle());
   layout_main->addWidget(answer);
   answer->setText("Для добавления новой стройки нажмите на значек +\nЧтобы сохранить изменения нажмите иконку дискеты\n");

//кнопка cancel
   QPushButton* cancelBtn = new QPushButton( "OK" );
   connect( cancelBtn, &QPushButton::clicked,this, &QDialog::close );
   cancelBtn->setStyleSheet(stylehelper::getButtonDialogApplyStyle());
   cancelBtn->setFixedSize(btnSize);
   layout_main->addWidget( cancelBtn );

   setLayout( layout_main );
}

void Dialog::about_dialog()
{
     this->setFixedSize(500,250);
    setWindowTitle(tr("О программе"));

//qlable
   answer->setStyleSheet(stylehelper::getLableDialogStyle());
   layout_main->addWidget(answer);
   answer->setText("Программа создана в целях составления расписания\n\n Создатель: Лойко Игорь\n Главный дизайнер: Потетнева Дарья\n");

//кнопка cancel
   QPushButton* cancelBtn = new QPushButton( "OK" );
   cancelBtn->setStyleSheet(stylehelper::getButtonDialogApplyStyle());
   cancelBtn->setFixedSize(btnSize);
   connect( cancelBtn, &QPushButton::clicked,this, &QDialog::close );
   layout_main->addWidget( cancelBtn );


   setLayout( layout_main );
}
