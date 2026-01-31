/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vec vector<ll>
ll MOD = (7 + (1e9));
#define en endl
using namespace std;

// abstraction for document elements

class DocuementElement{
public: 
    virtual string render()= 0;
};


class TextElement : public DocuementElement{
private:
    string text;
public:
    TextElement(string text){
        this->text = text;
    }
    string render() override{
        return text;
    }
};

class ImageElement: public DocuementElement{
private:
    string imagePath;

public:
    ImageElement(string imagePath){
        this->imagePath=imagePath;
    }
    string render() override{
        return "[Image:" + imagePath+ "]";
    }
};

// newline element represents a line break in the docuement

class NewLineElement: public DocuementElement{
public:
    string render() override{
        return "\n";
    }  
};

class TabSpaceElement:public DocuementElement{
public:
    string render() override{
        return "\t";
    }
};

class Document{
private:
    vector<DocuementElement*> documentElements;

public:
    void addElement(DocuementElement* element){
        documentElements.push_back(element);
    }

    string render(){
        string res;
        for(auto element:documentElements){
            res+=element->render();
        }
        return res;
    }
};

class Persistance{
public:
    virtual void save(string data) = 0;
};

class FileStorage:public Persistance{
public:
    void save(string data) override{
        ofstream outFile("document.txt");
        if(outFile){
            outFile<<data;
            outFile.close();
            cout<<"Document saved to document.txt"<<endl;
        }else{
            cout<<"Error: Unable to open file for writing"<<endl;
        }
    }
};

class DBStorage:public Persistance{
public:
    void save(string data) override{
        cout<<"Stored in Database"<<endl;
    }
};

class DocumentEditor{
private:
    Document* document;
    Persistance* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistance* storage){
        this->document=document;
        this->storage=storage;
    }
    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }
    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }
    void saveDocument(){
        storage->save(renderDocument());
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Document* document = new Document();
    Persistance* persistance = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,persistance);
   
    
    editor->addText("Hello world!");
    editor->addNewLine();
    editor->addText("Yo! dawg , are you good?");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Idented text after a tab space");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout<<editor->renderDocument()<<endl;
    editor->saveDocument();

    return 0;
}