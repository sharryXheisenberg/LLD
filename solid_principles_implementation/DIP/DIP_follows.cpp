/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

//  Dependency inversion principle says high level module not depend on low level module but both should depend on abstraction. Like neither low level modules communicate low level modules directly and vice-versa.


// abstraction (Interface)

class Database{
public:
    virtual void save(string data) = 0; 
};


// MySQL implementation (Low level module)
class MySQLDatabase : public Database{
public:
    void save(string data) override{
        cout<<"Executing SQL Query: INSERT INTO users VALUES "<<data<<";"<<endl;
    }
};

// MongoDB implementation (low level module)

class MongoDBDatabase:public Database{
public:
    void save(string data) override{
        cout<<"Executing MongoDB function: db.users.insert(name) " <<data<<";"<<endl;
    }
};


// high level module (Loosely coupled)
class UserService {
private:
    Database* db;    // dependency injection

public:
    UserService(Database* database){
        db = database;
    }
    void storeUser(string user){
        db->save(user);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("Spower");

    UserService service2(&mongodb);
    service2.storeUser("Admino");
    return 0;
}