#ifndef DATABASE_H
#define DATABASE_H
#include<canal.h>
#include<vector>
#include <QSqlQuery>
#include<QtSql>
#include"IMesaj.h"
#include"thread.h"
using namespace std;

class Database
{
private:
    vector<Canal*>canale;
    static Database*instance;
    Database(){};
    Database(const Database&){};
    ~Database(){};
public:
    void GetCanalsfromDB();
    void ConnectToDB();
    static Database&getinstance();
    static void destroyInstance();
    void Disconnect();
    int Login(const QString& username,const QString& parola);
    int Register(const QString& username,const QString& parola,const QString& email);
    int ChangePassword(const QString& username,const QString& email);
    vector<QString> GetNotifications(const QString& username);
    int CreateChannel(const QString& ChannelName,const QString& Descriere,const QString& Owner);
    vector<QString> GetChannels(const QString& username);
    vector<QString> GetPosts(const QString& canal);
    int AddMember(const QString& Channel,const QString& Owner,const QString& User);
    vector<QString> GetUsersFromChannel(const QString& canal);
    vector<QString> GetFilesFromChannel(const QString& canal);
    vector<QString> GetUsers();
    vector<QString> GetConversation(QString& user1,QString& user2);
    void AddMessageInConversation(const QString&source,const QString&destination,const QString&message);
    QString AddPost(const QString&Channel,const QString&post,const QString&owner);
    vector<QString> GetEvents(const QString&user);
    int AddFile(const QString&channel,const QString&Owner,const QString&Nume,const QString&continut);
    vector<QString> downloadFile(const QString&channel,const QString&file);
};

#endif // DATABASE_H
