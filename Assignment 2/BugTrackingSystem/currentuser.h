#ifndef CURRENTUSER_H
#define CURRENTUSER_H

namespace Ui {
class CurrentUser;
}

class CurrentUser
{
private:

public:
    QString username;
    int type;
    CurrentUser();
    CurrentUser(QString, int);
    CurrentUser(CurrentUser&);

};

CurrentUser::CurrentUser(){
    username = "0";
    type = 0;
}

CurrentUser::CurrentUser(QString u, int t){
    username = u;
    type = t;
}

CurrentUser::CurrentUser(CurrentUser& cu){
    username = cu.username;
    type = cu.type;
}

#endif // CURRENTUSER_H
