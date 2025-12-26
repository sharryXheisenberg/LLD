/* 
 * Author - Balerion_The_second
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;



// violating the SRP
class UserProfileManager{
    public:
        void getProfile(int userID) {/*fetch from DB*/}
        void updateProfile(int userID){/*update DB */}
        void uploadProfilePicture(int userID) {/*upload from S3*/}
        void delteAccount(int userId) {/*delete user from DB*/}
};


//  Fixed version of SRP for above violating SRP
class UserProfileService {/*get & update profile */};
class UserPictureService {/*upload profile pic*/};
class UserAccountManager {/*delete account */};

//Notification Service

class EmailSender{void send(string to , string msg);};
class SmsSender{void send(string to , string msg);};
class PushSender{void send(string to , string msg);};





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}