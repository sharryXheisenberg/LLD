/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


class MySQLDatabase{// low level module
public:
    void saveToSQL(string data){     
        cout<<"Executing SQL Query: INSERT INTO users VALUES "<<data<<";"<<endl;
    }
};

class MongoDBDatabase{// low level module
public:
    void saveToMongoDB(string data){    
        cout<<"Executing MongoDB function: db.users.insert(name) " <<data<<";"<<endl;
    }
};

class UserSerive{  //  high level module (tightly coupled with above saveToSQL() and saveToMongoDB() low level modules
private:
    MySQLDatabase sqlDb;   // direct dependency on MySQL  (only references)
    MongoDBDatabase mongoDb; // direct dependency on MongoDB

public:
    void storeUserToSQL(string user){
        sqlDb.saveToSQL(user);
    }
    void storeUserToMongoDB(string user){
        mongoDb.saveToMongoDB(user);
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    UserSerive userService;
    userService.storeUserToMongoDB("2Pac");
    userService.storeUserToSQL("Rudiger");
    return 0;
}