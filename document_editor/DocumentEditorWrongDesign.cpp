/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#include<fstream>
#define ll long long
#define en endl
using namespace std;

class DocumentEditor{
private:    
    vector<string>docuementElements;
    string renderedDocument;  // this element used to save rendered document so it same element should not be rendered or store 

public: 
    void addText(string text){
        docuementElements.push_back(text);
    }
    void addImage(string imagePath){
        docuementElements.push_back(imagePath);
    }

    // renders the document by checking the type of each element at runtime 
    string renderDocument(){
        if(renderedDocument.empty()){
            string res;
            for(auto element:docuementElements){
                if(element.size()>4 && (element.substr(element.size() -4)==".jpg" || element.substr(element.size()-4)==".png")){
                    res+="[Image: " + element + "]" + "\n";
                }else{
                    res+=element + "\n";
                }
            }
            renderedDocument = res;
        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout<<"Document saved to Document.txt"<<en;
        }else{
            cout<<"Error: unable to open file for writing."<<en;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}