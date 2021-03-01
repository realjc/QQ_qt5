#include "qq/login.hpp"


Login::Login(QWidget *parent):QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    QImage *img=new QImage();
    QDir curr_dir = QDir::current();
    img->load(curr_dir.absolutePath()+"/../"+"resource/img/qq.jpeg"); 
    *img = img->scaled(81, 81);
    ui->portrait_label->setPixmap(QPixmap::fromImage(*img));
}

Login::~Login(){
    delete ui;
}

void Login::on_login_button_clicked()
{
    if(ui->account_lineEdit->text()==""||ui->passwd_lineEdit->text()==""){
        ui->warn_label->setText("账号密码不能为空!!");
    }else{
        ui->warn_label->hide();
        ui->login_button->hide();
        ui->account_lineEdit->hide();
        ui->passwd_lineEdit->hide();
    }
}


