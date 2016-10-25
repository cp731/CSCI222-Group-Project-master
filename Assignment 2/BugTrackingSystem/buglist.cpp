#include "buglist.h"
#include "ui_buglist.h"

BugList::BugList(QWidget *parent, QString searchValue, int currentUserType) :
    QMainWindow(parent),
    ui(new Ui::BugList)
{
    ui->setupUi(this);
    if(currentType == -1)
        ui->loginButton->setText("Login");
        ui->currentUserLabel->setText("You are not logged in");

// Read the bugs from the database
    qDebug() << "Contructing with: " << searchValue;
    QSqlQuery bugResult = bugQuery(searchValue);
    //setList(bugResult);
    currentType = currentUserType;
}

BugList::~BugList()
{
    delete ui;
}


// The search query's implementation
QSqlQuery BugList::bugQuery(QString searchTerm){

    Connect connection;
    connection.connOpen();

    // Perform the query
    QSqlQuery query(connection.mydb);

    if(searchTerm=="")
        if(!query.exec("SELECT bug_id, creation_ts, short_desc FROM bug"))
            qDebug() << "Search function failed: " << query.lastError();
        else{
            int count = 0;
            while(query.next())count++;
            qDebug() << "Read " << count << " entries.";
        }
    else{
        QString searchID;
        if(searchTerm.toInt() == 0)
            searchID = "null";
        else
            searchID = QString::number(searchTerm.toInt());
        qDebug() << "SearchID is: " << searchID;
        if(!query.exec("SELECT bug_id, creation_ts, short_desc FROM bug WHERE bug_id="+searchID
                       +" UNION SELECT bug_id, creation_ts, short_desc FROM bug WHERE short_desc LIKE '%"+searchTerm+"%'"))
            qDebug() << "Search function failed: " << query.lastError();
        else{
            int count = 0;
            while(query.next())count++;
            qDebug() << "Read " << count << " entries.";
        }
    }

    QGridLayout* layout = new QGridLayout();
    QSignalMapper* signalMapper = new QSignalMapper(this);
    QString bug_list;
    int results = 0;
    if(query.first()){
        do{
            int bugIdNum = query.value(0).toInt();
            bug_list = query.value(0).toString() + " | " + query.value(1).toString() + " | " + query.value(2).toString() + "\n";
            QHBoxLayout* bugEntry = new QHBoxLayout();
            QLabel* label = new QLabel();
            QPushButton* moreButton = new QPushButton(this);
            moreButton->setText("More");
            moreButton->setMaximumWidth(100);
            signalMapper->setMapping(moreButton, bugIdNum);
            connect(moreButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            label->setText(bug_list);
            bugEntry->addWidget(label);
            bugEntry->addWidget(moreButton);
            layout->addLayout(bugEntry, results, 0);
            layout->setAlignment(Qt::AlignTop);
            results++;
        }while(query.next());
    }
    QWidget* viewport = new QWidget();
    viewport->setLayout(layout);
    ui->bugList->setWidget(viewport);
    ui->bugList->setWidgetResizable(true);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(on_bugButton_clicked(int)));

    connection.connClose();

    return query;
}

// Constructs the search view
void BugList::on_searchButton_clicked()
{
    BugList* reload = new BugList(0,ui->searchBox->text());
    if(currentType != -1)
    reload->setCurrentUser(currentUser, currentType);
    reload->show();
    this->hide();
}

// Sets the list of elements displayed on screen
void BugList::setList(QSqlQuery bugs){

    QGridLayout* layout = new QGridLayout();
    QSignalMapper* signalMapper = new QSignalMapper(this);
    QString bug_list;
    int results = 0;
    if(bugs.first()){
        do{
            int bugIdNum = bugs.value(0).toInt();
            bug_list = bugs.value(0).toString() + " | " + bugs.value(1).toString() + " | " + bugs.value(2).toString() + "\n";
            QHBoxLayout* bugEntry = new QHBoxLayout();
            QLabel* label = new QLabel();
            QPushButton* moreButton = new QPushButton(this);
            moreButton->setText("More");
            moreButton->setMaximumWidth(100);
            signalMapper->setMapping(moreButton, bugIdNum);
            connect(moreButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            label->setText(bug_list);
            bugEntry->addWidget(label);
            bugEntry->addWidget(moreButton);
            layout->addLayout(bugEntry, results, 0);
            layout->setAlignment(Qt::AlignTop);
            results++;
        }while(bugs.next());
    }
    QWidget* viewport = new QWidget();
    viewport->setLayout(layout);
    ui->bugList->setWidget(viewport);
    ui->bugList->setWidgetResizable(true);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(on_bugButton_clicked(int)));
}

// Sets the current user of a page
void BugList::setCurrentUser(QString uname, int t){
    currentUser = uname;
    currentType = t;
    if(currentType != -1){
        ui->currentUserLabel->setStyleSheet("QPushButton {color: blue}");
        ui->currentUserLabel->setText("You are logged in as: " + currentUser);
        ui->loginButton->setText(QString("Logout"));
    }
}

// Slot for pressing the login/logout button.
void BugList::on_loginButton_clicked()
{
    if(currentType == -1){
        Login* newLogin = new Login();
        newLogin->show();
        this->hide();
    }else{
        BugList* bugList = new BugList();
        bugList->show();
        this->hide();
    }
}

// Slot for clicking on the username, goes to profile page.
void BugList::on_currentUserLabel_clicked()
{
    // Ensure that someone is logged in
    if (currentType == 1) {
        ProfilePage* profilePage = new ProfilePage();
        profilePage->setCurrentUser(currentUser, currentType);
        profilePage->show();
        this->hide();
    }
    else if (currentType == 0) {
        AdminProfile* adminPage = new AdminProfile();
        adminPage->setCurrentUser(currentUser, currentType);
        adminPage->show();
        this->hide();
    }
    else if (currentType == 2) {
        DeveloperPage* developerPage = new DeveloperPage();
        developerPage->setCurrentUser(currentUser, currentType);
        developerPage->show();
        this->hide();
    }
}

// Slot for launching the submit bug activity.
void BugList::on_newBugButton_clicked()
{
    if(currentType == -1){
        Login* loginPage = new Login();
        loginPage->show();
        this->hide();
    }else{
        Reportbug* reportBug = new Reportbug();
        reportBug->setCurrentUser(currentUser, currentType);
        reportBug->show();
        this->hide();

    }
}

// Slot for launching the bug view activity
void BugList::on_bugButton_clicked(int bugIdSpec){
    BugDisplay* bugDisplay = new BugDisplay(0, bugIdSpec, currentType);
    bugDisplay->setCurrentUser(currentUser, currentType);
    bugDisplay->show();
    this->hide();
}
/*
// Slot for launching the report genration activity
void BugList::on_reportsButton_clicked()
{

}*/
