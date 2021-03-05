#include "qq/login.hpp"
#include "qq/setting.hpp"


Login::Login(QWidget *parent):QWidget(parent), ui(new Ui::Login),mysql_conn_(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    QImage *img=new QImage();
    QDir curr_dir = QDir::current();
    img->load(curr_dir.absolutePath()+"/../"+"resource/img/qq.jpeg"); 
    *img = img->scaled(81, 81);
    ui->portrait_label->setPixmap(QPixmap::fromImage(*img));
}

Login::~Login(){
    if(mysql_conn_ !=nullptr){
        mysql_conn_->disconnect();
        delete mysql_conn_;
        mysql_conn_ = nullptr;
    }
    delete ui;
}

void Login::on_login_button_clicked()
{
    if(ui->account_lineEdit->text()==""||ui->passwd_lineEdit->text()==""){
        ui->warn_label->setText("账号/密码不能为空!!");
    }else{
        // ui->account_lineEdit->hide();
        // ui->passwd_lineEdit->hide();
        this->connMysql();
        if(!mysql_conn_) return;
        string id = ui->account_lineEdit->text().toStdString();
        string passwd = ui->passwd_lineEdit->text().toStdString();
        string comm = "select passwd from accounts where id = "+ id;
        Query query = mysql_conn_->query(comm);
        StoreQueryResult result = query.store();
        if(result.num_rows()==0){
            ui->warn_label->setText("账号不存在!!");
            return;
        } 
        Row row = result[0];
        QString passwd_queried = QString::fromUtf8(result[0][0]);
        cout<< id<< " "<< passwd<<endl;
        if(passwd== passwd_queried.toStdString()){
            ui->warn_label->setText("登录成功!!");
        }else{
            ui->warn_label->setText("账号/密码不正确!!");
        }
    }
}


void Login::connMysql(){
    if(mysql_conn_ != nullptr){
        mysql_conn_->disconnect();
        delete mysql_conn_;
        mysql_conn_ = nullptr;
    }
    try{
        mysql_conn_ = new Connection();
        SetCharsetNameOption *charset = new SetCharsetNameOption("utf8");
        mysql_conn_->set_option(charset);
        mysql_conn_->connect(m_db.toLatin1(),m_ip.toLatin1(),m_user.toLatin1(),
                                            m_passwd.toLatin1(),m_port.toInt());
    }catch(...){
        cout<<"数据库连接错误";
    }
}