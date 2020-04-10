//
//  main.cpp
//  PROJECTKM
//
//  Created by Kristina Myftaraga on 2/2/20.
//  Copyright © 2020 Kristina Myftaraga. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Company;
class Editor;
class User;
class VideoEditor;
class PhotoEditor;
class Simple;
class Complex;
class SocialMedia;
class VirtualReality;

vector < Company* > Companies;
vector < Company* > Promoted_Companies;
vector < Editor* > Editors;
vector < pair < Editor*, Company* > > FoundApps;
vector < User* > Users;
void OnlineStoreMenu();
class Company {
public:
    Company() {
        setname();
        setadress();
        setphone();
        setaccesscode();
    }

    Company(string name, string adress, string phone, string ac) {
        cName = name;
        cAdress = adress;
        cPhone = phone;
        accessCode = ac;
    }

    void setname() {
        cout << "Enter the name of the company: ";
        string name;
        cin.ignore();
        getline(cin, name);
        this->cName = name;
    }

    void setadress() {
        cout << "Enter the adress: ";
        string adress;
        cin.ignore();
        getline(cin, adress);
        this->cAdress = adress;
    }

    void setphone() {
        cout << "Enter phone number: ";
        string phone;
        cin.ignore();
        getline(cin, phone);
        this->cPhone = phone;
    }

    void setaccesscode() {
        cout << "Enter the accesscode: ";
        string p;
        cin >> p;
        this->accessCode = p;
    }
    
    string getCode() { return accessCode; }
    string getCname() { return cName; }
    string getCadress() { return cAdress; }
    string getCphone() { return cPhone; }


    void Info() {
        cout << " - Name: " << getCname() << endl;
        cout << " - Location: " << getCadress() << endl;
        cout << " - Phone: " << getCphone() << endl;
    }

private:
    string cName;
    string cAdress;
    string cPhone;
    string accessCode;
};


class Editor {
public:
    Editor() {
        setName();
        setID();
        setOsystem();
        setVersion();
        setFormat();
        
    }

    Editor(string NAME, string VERSION, string FORMAT, string id, string OSYSTEM) {
        eName = NAME;
        ID = id;
        eOsystem = OSYSTEM;
        eVersion = VERSION;
        eFormat = FORMAT;
    }
    void setName() {
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│    Name of the Editor:│  ";
        string n;
        cin.ignore();
        getline(cin, n);
        this->eName = n;
    }
    void setID() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│      Enter the ID:    │  ";
        string p;
        cin >> p;
        this->ID = p;
    }
    void setOsystem() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│   Operating system:   │  ";
        string os;
        cin.ignore();
        getline(cin, os);
        this->eOsystem=os;
    }
    void setVersion() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│        Version:       │  ";
        string a;
        cin.ignore();
        getline(cin, a);
        this->eVersion = a;
    }
    void setFormat() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│        Format:        │  ";
        string ag;
        cin.ignore();
        getline(cin, ag);
        this->eFormat=ag;
        cout << "\t\t✂----------------------------------------------------------";
    }
    
    void setCompany(Company* object) {company = object;}
               
    //virtual functions
    virtual void Description() {
        cout << " + Name: " << eName<< endl;
        cout << " + Version: " << eVersion<< endl;
        cout << " + Format: " << eFormat << endl;
        cout << " + ID: "<< ID << endl;
        cout << " + Operating system : " << eOsystem << endl;
    }

    virtual double getTotalPrice() = 0;
    
    Company* getCompany() { return company; }
    string getEversion() { return eVersion; }
    string getEformat() { return eFormat; }
    string getoSystem() { return eOsystem; }
    string getEname() { return eName; }
    string getID() { return ID; }

private:
    Company *company;
    string eVersion;
    string eFormat;
    string eOsystem;
    string eName;
    string ID;

};

class PhotoEditor : public Editor {
public:
    PhotoEditor() {
        setOriginalSaved();
        setColorMode();
        setLayers();
    }

                                //constructor to read from the file
    PhotoEditor(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, bool _OriginalSaved, string _ColorMode, int layers):
        Editor(NAME, VERSION, FORMAT, id, OSYSTEM),
                OriginalSaved(_OriginalSaved),
                ColorMode(_ColorMode),
                Layers (layers){}

    void setOriginalSaved(){
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│Can the user software save the original version?│  ";
                string solution;
                cin >> solution;
            if (solution=="Y"|| solution=="y"){
                this->OriginalSaved=true;
            }
            else if(solution=="N" || solution=="n"){
                this->OriginalSaved=false;
            }
            else{cout<<"Wrong format!!\n";setOriginalSaved();}
        }
    
    void setColorMode() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│   The color mode:    │  ";
        string p;
        cin.ignore();
        getline(cin, p);
        this->ColorMode = p;
        }
    
    void setLayers() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│ The number of layers:│  ";
        string l;
        cin >> l;
            unsigned int w = atoi(l.c_str());
            if (w) { this->Layers = w;
                cout << "\t\t✂----------------------------------------------------------";
            }
            else { cout << "\nInvalid!\n"; setLayers(); }
       }
    
    double getTotalPrice(){
        double toReturn=0;
        toReturn+=PhotoEditor::getLayers()*10;
        if (PhotoEditor::getOsaved()){
            toReturn+=20;
        }
        return toReturn;
    }
    
    void Description() {
        Editor::Description();
        cout << " + OriginalSaved or Not: " << getOriginalSaved() << endl;
        cout << " + Color mode: " << getColorMode() << endl;
        cout << " + The number of layers: " << getLayers() << endl;
    }
    
    bool getOsaved(){return OriginalSaved;}
    string getOriginalSaved() { if(OriginalSaved)return"Yes"; else return "No"; }
    string getColorMode() { return ColorMode; }
    int getLayers() { return Layers; }

private:
    bool OriginalSaved;
    string ColorMode;
    int Layers;
};

class Simple : public PhotoEditor {
public:
    Simple() {
        setSIZE();
        setFilters();
        setFeatures();
    }
    
    Simple(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, string SIZE, bool OriginalSaved, string ColorMode, int layers, string filter, string Features) :
                PhotoEditor(NAME, VERSION, id, FORMAT, OSYSTEM, OriginalSaved, ColorMode, layers),
                Filters(filter),
                SIZE (SIZE),
                Features (Features){}

    void setSIZE() {
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│         SIZE:       │  ";
           string t;
           cin.ignore();
           getline(cin, t);
           this-> SIZE = t;
       }
    
    void setFilters() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│       Filters:       │  ";
            string f;
            cin.ignore();
            getline(cin, f);
            this-> Filters = f;
    }
    
    void setFeatures() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│      Features:       │  ";
            string e;
            cin.ignore();
            getline(cin, e);
            this-> Features = e;
        cout << "\t\t✂----------------------------------------------------------";

    }

    double getTotalPrice(){
        double toReturn=PhotoEditor::getTotalPrice();
        if (Editor::getoSystem()=="iOS-Android and Windows mobile devices"){toReturn+=50;}
        else {toReturn+=20;}
        return toReturn;
    }
    
    void Description() {
        PhotoEditor::Description();
        cout << " + SIZE: " << getSIZE() << endl;
        cout << " + Do you want the original saved? " << getOriginalSaved() <<endl;
        cout << " + Filters: " << getFilters() <<endl;
        cout << " + Features: " << getFeatures() << endl;
    }

    string getFilters() { return Filters; }
    string getFeatures() { return Features; }
    string getSIZE() { return SIZE; }

private:
    string Filters;
    string Features;
    string SIZE;
};

class Complex : public PhotoEditor {
public:
    Complex() {
        setMobileFormat();
        setPortraitCorrection();
        setPhotoMasking();
        setCatalog();
        setTraceImage();
        setVector();
    }

    Complex(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, bool OriginalSaved, string ColorMode, int layers, string mf,  bool PortraitCorrection, string catalog, string masking, string traceimage, string _vector):
                PhotoEditor(NAME, VERSION, id, FORMAT, OSYSTEM, OriginalSaved, ColorMode, layers),
                MobileFormat(mf),
                PortraitCorrection(PortraitCorrection),
                Catalog (catalog),
                PhotoMasking (masking),
                TraceImage (traceimage),
                Vector (_vector)
    {}
    
    void setMobileFormat() {
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│The photos are accesible in the mobile format:│ ";
        string c;
        cin.ignore();
        getline(cin, c);
        this->MobileFormat = c;
    }
    void setPhotoMasking() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│              Masking options:                │  ";
           string p;
           cin.ignore();
           getline(cin, p);
           this->PhotoMasking = p;
       }

    void setPortraitCorrection() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│  Do you want the portrait correction (y/n)?  │  ";
               string solution;
               cin>>solution;
        if (solution=="Y"|| solution=="y"){
            this->PortraitCorrection=true;
        }
        else if(solution=="N" || solution=="n"){
            this->PortraitCorrection=false;
        }
        else{cout<<"Wrong format!!\n";setPortraitCorrection();}
    }


    void setCatalog() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│         The photos saved in the catalog:    │  ";
        string a;
        cin.ignore();
        getline(cin, a);
        this->Catalog = a;
    }
    
    void setTraceImage() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│             Trace image editing:           │  ";
        string t;
        cin.ignore();
        getline(cin, t);
        this->TraceImage = t;
       }

       void setVector() {
           cout << "\t\t✂----------------------------------------------------------";
           cout << "\n\t\t│                  Vector:                 │  ";
           string t;
           cin.ignore();
           getline(cin,t);
           this->Vector = t;
           cout << "\t\t✂----------------------------------------------------------";
           
       }
    
    double getTotalPrice(){
        double toReturn=PhotoEditor::getTotalPrice();
        if (getPC()){toReturn+=30;}
        else {toReturn+=10;}
        return toReturn;
    }

    void Description() {
        PhotoEditor::Description();
        cout << " + Accessible in mobile format:  " << getMobileFormat() << endl;
        cout << " + PortraitCorrection? " << getPortraitCorrection() << endl;
        cout << " + Trace image options: " << getTraceImage() << endl;
        cout << " + Vector type: " << getVector() << endl;
        cout << " + Photo masking options: " << getPhotoMasking() <<endl;
        cout << " + Where are photos saved? " << getCatalog() << endl;
    }

    bool getPC() {return PortraitCorrection;}
    string getMobileFormat() { return MobileFormat; }
    string getPortraitCorrection() { if(PortraitCorrection)return "Yes"; else return "No";}
    string getCatalog() { return Catalog; }
    string getPhotoMasking() { return PhotoMasking;}
    string getTraceImage() { return TraceImage; }
    string getVector() { return Vector; }

private:
    string MobileFormat;
    bool PortraitCorrection;
    string Catalog;
    string PhotoMasking;
    string TraceImage;
    string Vector;
};


class VideoEditor : public Editor {
public:
    VideoEditor() {
        setaudioformats();
        setMontage();
        seteffects();
    }

    VideoEditor(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, string am, string montage, string effects):
        Editor(NAME, VERSION, id, FORMAT, OSYSTEM),
        audioformats(am),
        Montage(montage),
        effects(effects)
        {}


    void setMontage() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│    Montage:     │  ";
               string t;
               cin.ignore();
               getline(cin, t);
               this->Montage = t;
    }

    void seteffects() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│     Effecs:     │  ";
        string t;
        cin.ignore();
        getline(cin, t);
        this->effects = t;
        cout << "\t\t✂----------------------------------------------------------";

    }

    void setaudioformats(){
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│  Audio Formats: │  ";
            string t;
            cin.ignore();
            getline(cin, t);
            this->audioformats = t;

        }
    
    double getTotalPrice(){return 100;}//base price for videoeditors

    void Description() {
        Editor::Description();
        cout << " + Audio formats: " << getaudioformats() <<endl;
        cout << " + Montage: " << getMontage() << endl;
        cout << " + Effects: " << geteffects() << endl;
    }
    string getMontage() { return Montage; }
    string geteffects() { return effects; }
    string getaudioformats() { return audioformats; }

private:
    string Montage;
    string effects;
    string audioformats;
};


class SocialMedia : public VideoEditor {
public:
    SocialMedia() {
        setMotionGraphics();
        setproperties();
    }

    SocialMedia(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, string af, string montage, string effects, string motiongraphics, string properties):
                VideoEditor(NAME, VERSION, id, FORMAT, OSYSTEM, af, montage, effects),
                MotionGraphics (motiongraphics),
                properties (properties)
    {}

    void setMotionGraphics() {
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│ Motion Graphics:  │  ";
       string t;
        cin.ignore();
        getline(cin, t);
        this->MotionGraphics = t;
    }

    void setproperties() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│   Properties:     │  ";
        string t;
            cin.ignore();
            getline(cin, t);
            this->properties = t;
        cout << "\t\t✂----------------------------------------------------------";

    }

   double getTotalPrice(){
        double toReturn=VideoEditor::getTotalPrice();
        if (getMotionGraphics().length()>20){toReturn+=25;}
        else {toReturn+=14;}
        return toReturn;
    }


    void Description() {
        VideoEditor::Description();
        cout << " + Motion graphics: " << getMotionGraphics() << endl;
        cout << " + Properties: " << getproperties() << endl;

    }

    string getMotionGraphics() { return MotionGraphics; }
    string getproperties() { return properties; }


private:
    string MotionGraphics;
    string properties;

};

class VirtualReality : public VideoEditor {
public:
    VirtualReality() {
        setPlatforms();
        setTransitions();
        setTimeline();
        setStory();
    }

    VirtualReality(string NAME, string VERSION, string id, string FORMAT, string OSYSTEM, string af, string montage, string effects,string platforms, string transitions, string story, string timeline):
                VideoEditor(NAME, VERSION, id, FORMAT, OSYSTEM, af, montage, effects),
                Platforms (platforms),
                Transitions (transitions),
                timeline (timeline),
                story (story)

    {}

    void setStory() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│      Story/ plot:   │  ";
       string t;
                 cin.ignore();
                 getline(cin, t);
                 this->story = t;
    cout << "\t\t✂----------------------------------------------------------";
    }

    void setPlatforms() {
        cout << "\n\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│      Platforms:      │  ";
       string t;
                 cin.ignore();
                 getline(cin, t);
                 this->Platforms = t;
    }


    void setTransitions() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│    Transitions:      │  ";
           string t;
                 cin.ignore();
                 getline(cin, t);
                 this->Transitions = t;
    }

    void setTimeline() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│     The timeline:    │  ";
                    string t;
                  cin.ignore();
                  getline(cin, t);
                  this->timeline = t;
    }

    double getTotalPrice(){
          double toReturn=VideoEditor::getTotalPrice();
          return toReturn+122;
      }

    void Description() {
        VideoEditor::Description();
        cout << " + Platforms available on: " << getPlatforms() << endl;
        cout << " + Transitions: " << getTransitions() << endl;
        cout << " + Scripting: " << getStory() << endl;
        cout << " + The timeline: " << getTimeline() << endl;
    }

    string getPlatforms() { return Platforms; }
    string getTransitions() { return Transitions; }
    string getStory() { return story; }
    string getTimeline() { return timeline; }

private:
    string Platforms;
    string Transitions;
    string story;
    string timeline;

};

class User {

public:

    User() {
        setName();
        setID();
        setBudget();
        setAdress();
        setPhone();
        setGPA();
        }


    User(string n, string id, double budget, string ad, string phone, double gpa) {
        Name = n;
        ID = id;
        Budget = budget;
        Adress = ad;
        Phone = phone;
        UnGPA = gpa;
    }

    void setGPA() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│University GPA (0 - 4.0 scale): │  ";
        string g;
        cin >> g;
        double w = atoi(g.c_str());
        if (w && w >= 0 && w <= 4) {
            this->UnGPA = w;
        cout << "\t\t------------------------------------------------------------";

        }
        else { cout << "\nInvalid GPA!\n"; setGPA(); }
    }
    
    void setName() {
        cout << "\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│           Name:                │  ";
        string n;
        cin.ignore();
        getline(cin, n);
        this->Name = n;
    }

    void setAdress() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│           Adress:              │  ";
        string a;
        cin.ignore();
        getline(cin, a);
        this->Adress = a;
    }

    void setPhone() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│       Phone Number:            │  ";
        string p;
        cin >> p;
        this->Phone = p;
    }
    void setBudget() {
          cout << "\t\t✂----------------------------------------------------------";
          cout << "\n\t\t│           Budget:              │  ";
          string b;
          cin >> b;
          unsigned int w = atoi(b.c_str());
          if (w) { this->Budget = w; }
          else { cout << "\nInvalid!\n"; setBudget(); }
      }
    
    void CreateEditors(){
        cout << "\n\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│     Photo (A) or Video (B):     │  ";
        string choice;
        cin>>choice;
        if(choice=="A"){
            cout << "\t\t✂----------------------------------------------------------";
            cout << "\n\t\t│   Simple (a) or complex (b):    │  ";
            string c;
            cin>>c;
            cout << "\t\t✂----------------------------------------------------------";
            if(c=="a")CreatedEditors.push_back(new Simple());
            else if(c=="b")CreatedEditors.push_back(new Complex());
            else {
                cout << "Invalid!"<<endl;CreateEditors();
                
            }
            
        }
        else if (choice=="B"){
            cout << "\t\t✂----------------------------------------------------------";
            cout << "\n\t\t│Social Media (a) or Virtual Reality (b):│  ";
            string d;
            cin>>d;
            cout << "\t\t✂----------------------------------------------------------";
            if(d=="a") CreatedEditors.push_back (new SocialMedia());
            else if(d=="b") CreatedEditors.push_back (new VirtualReality());
            else {cout << "Incorrect!"<< endl; CreateEditors();}
        }
        else{ cout<<"\t\tInvalid input!\n"; CreateEditors();
        }
    }


    void reduceBudget(int b) {
        Budget -= b;
    }

    void setCompany(Company *C) {
        comp = C;
        this->hasComp = true;
    }

    void setID() {
        cout << "\t\t✂----------------------------------------------------------";
        cout << "\n\t\t│           ID:                  │  ";
        string id;
        cin >> id;
        this->ID = id;
    }
 
    bool getStatus(){return hasComp;}

    vector<Editor*> getCreatedEditors() { return CreatedEditors; }
    vector<Editor*> getBoughtEditors() { return BoughtEditors; }
    string getAdress() { return Adress; }
    double getBudget() { return Budget; }
    string getPhone() { return Phone; }
    string getName() { return Name; }
    double getGPA() { return UnGPA; }
    string getID() { return ID; }
    Company* getCompany() { return comp; }
    bool has() { return hasComp; }

private:
    vector<Editor*> CreatedEditors;
    vector<Editor*> BoughtEditors;
  
    double UnGPA= 0;
    double Budget = 0;
    string Adress = "";
    string Phone = "";
    string Name = "";
    string ID = "";

    Company *comp;
    bool hasComp = false;
};




//------------------------------------------------------------Functions------------------------------------------Functions----------------------------------------------
//MergeSort Algorithm to be used in the main function
void merges(vector<Editor*>&collection, int start, int mid, int ends) {
// temp vector of items
    vector<Editor*>temp(ends - start + 1);

// iterators of intervals
    int i = start, j = mid+1, k = 0;

// here we compare and add smaller  to temp  (when comparing doubles use 0.0001 for precision)
    while(i <= mid && j <= ends) {

    if( collection[i]->getTotalPrice() <= collection[j]->getTotalPrice()) {
            temp[k] = collection[i];
            k += 1; i += 1;
        }
        else {
            temp[k] = collection[j];
            k += 1; j += 1;
        }
    }
    while(i <= mid) {
        temp[k] = collection[i];
        k += 1; i += 1;
    }
    // Copy the remaining elements of vector<Item*> ends , if there are any
    while(j <= ends) {
        temp[k] = collection[j];
        k += 1; j += 1;
    }
    // Copy the remaining elements of vector<Item*> starts , if there are any
    for(i = start; i <= ends; i += 1) {
        collection[i] = temp[i - start];
    }
}

void mergeSort( vector<Editor*>&collection, int start, int ends) {
    if(start < ends) {
          //Sort the first and second halves
        int mid = (start + ends) / 2;
         //Recursion of mergeSort function
        mergeSort(collection, start, mid);
        mergeSort(collection, mid+1, ends);
         //merge the two halves together
        merges(collection, start, mid, ends);
    }
}
//User Menu
void UserMenu() {
    
    cout << "\n\n\t\t                     ░▒▓█ USER MENU █▓▒░                  ";
    cout << "\n\t\t✂----------------------------------------------------------";
    cout << "\n\t\t│         1) Login          │        2) Register         │";
    cout << "\n\t\t│---------------------------│----------------------------│\n\n";
    cout << "\nChoice: ";
    
    char choice;
    cin>>choice;
    
    if(choice=='1'){
        cout<<"\n\t\t〄 First Name: ";
        string name,id;
        cin.ignore();
        getline(cin,name);

        cout<<"\t\t〄 ID: ";
        cin>>id;
        
        bool loggedIn = false;
        for(auto currUser : Users){
            if( currUser->getName() == name && currUser->getID()==id){
                cout<<"\n\t\t\t\t\t\t\tヽ(^o^)ノ";
                cout<<"\n\t\t\tSuccessfully logged in as "<<name<<endl;
                loggedIn = true;

                if(currUser->getStatus()){
                    cout<<"\t\t\t\t\t > Current company: " << currUser->getCompany()->getCname()<<"\n";
                }
                else{
                    cout<<"\t\t\t! User not part of our partner Companies !\n\n";
                }
                cout << "\n\t\t✂----------------------------------------------------------";
                cout << "\n\t\t│    1) Apply to Company    │       2) Buy Editor        │";
                cout << "\n\t\t│---------------------------│----------------------------│\n";
                if(currUser->getStatus()){
                cout << "\t\t│                     3) Add Editor                      │";
                cout << "\n\t\t│--------------------------------------------------------│\n\n";

                }
                
                cout<<"\nChoice: ";
                cin>>choice;
                while (choice!='0')
                if(choice=='1'){ // list companies and apply
                    int it=1;
                    for(auto currCompany: Companies){
                        cout<<"\t\t\t\t"<<it<<"> "<<currCompany->getCname()<<"\n";
                        it++;
                    }
                     
                    if(it==1){
                        cout<<"\n\t\t\tNot promoted Companies!\n\n";
                    }
                    else{
                        cout<<"\nSelect a company to apply 〢 ";
                        int choice;
                        cin>>choice;
                        auto currCompany = Companies[choice-1];
                        cout<<"\n\t\t ↬ We reviewed your data..."<< endl;
                        bool accepted = false;
                        if(currUser->getGPA()>=3.0)accepted=true;
                        if(accepted){
                            cout<<"\t\t ⇢ Congratulations you are now part of "<<currCompany->getCname()<<" family!\n";
                            cout<<"\t\t\tPlease log in again!\n\n";
                            currUser->setCompany(currCompany);
                            UserMenu();
                            
                        }
                        else{
                            cout<<"\t\t ⇢ Verdict: Rejected!\n";
                            UserMenu();
                        }
                        
                    }
                }
                
                else if(choice=='2'){ // list Editors and buy (compare price and budget)
                    int it=1;
                    mergeSort(Editors, 0,(int) Editors.size()-1);
                    for(auto currEditor: Editors){
                        cout<<setw(18)<<it<<"- "<<currEditor->getEname()<<"\t\t\t $"<<currEditor->getTotalPrice()<<endl;
                        it++;
                    }
                    
                    if(it==1){cout<<"\n\t\t\tNo Editors for sale!\n\n"; }
                    else{
                        int choice;
                        do{
                            cout<<"\nCurrent budget: $ "<<currUser->getBudget()<<endl;
                            cout<<"Choice: ";cin>>choice;
                            
                        }
                        while ( choice<1 && choice>=(int)Editors.size());
                        
                            
                        auto currentEditor=Editors[choice-1];
                        if (currUser->getBudget()>=currentEditor->getTotalPrice()){
                            cout<<"\t\t✎"<<currentEditor->getEname()<<" successfully purchased!\n\n";
                            
                            currUser->reduceBudget(currentEditor->getTotalPrice());
                            cout<< "\t\t$ "<<currUser->getBudget() << " dollars remaining in your account!\n";
                            UserMenu();
                        }
                        else { cout<<"Not enough budget to buy editor :(\n\n";}
                    }
                }
                
                else if(choice=='3'){
                    currUser->CreateEditors();
                    UserMenu();
                }
            }
        }
        if(loggedIn==false){
            cout<<setw(40)<<"\n\n\t\t\t\t\t\t\t\t (｡●́‿●̀｡)";
            cout<<setw(40)<<"\n\t\t\t\t\t\t\t !! Incorrect name or ID !!\n";
        }
    }
    
    else if( choice=='2'){
        User* curr = new User();
        Users.push_back(curr);
        cout<<setw(46)<<"\n\n\t\t\t\t\t\t\t\t\t (｡●́‿●̀｡)";
        cout<<setw(40)<<"\n\t\t\t\t\t\t\t Successfully registered! \n\n\n";
        ofstream o;
        string toAppend="";
        toAppend+=curr->getName()+",";
        toAppend+=curr->getID()+",";
        toAppend+=to_string(curr->getBudget())+",";
        toAppend+=curr->getAdress()+",";
        toAppend+=curr->getPhone()+",";
        toAppend+=curr->getGPA();
        o.open("Users.txt",ios_base::app);
        o<<toAppend;
        o.close();
        UserMenu();
        
    }
}


void CompanyInfo () {
    if (Companies.size() == 0) { cout << "\n  Not available Companies\n\n"; }
    else { cout << "\n\t\t\tThe Companies, sorted based on their first letter, are: " << endl;
        cout << "\t\t\t\t  Select a Company to get the Description:\n\n";
            for (unsigned int q = 0; q < Companies.size(); q++) {
                cout <<"\t\t\t"<< q + 1 << " - " << Companies[q]->getCname() << endl;
            }
            cout << "\nChoice: ";
            string c;
            cin >> c;

            unsigned int w = atoi(c.c_str());
            if (w && w <= Companies.size()) {
                cout << "Displaying Description...\n\n";
                Companies[w - 1]->Info();
            }

            else { cout << "\nInvalid command!\n\n"; CompanyInfo(); }
    }
}
void EditorsInfo() {
    if (Editors.size() == 0) { cout << "\n  Not available Editors\n\n"; }
    else {
       // quickSort(PhotoEditors, 0, PhotoEditors.size() - 1);
        cout << "\n\t\t\tThe Editors, sorted based on their price, are: " << endl;
        mergeSort(Editors,0,(int)Editors.size()-1);//calling the function
        cout << "\t\t\t  Select an Editor to get the Description:\n\n";
        for (unsigned int q = 0; q < Editors.size(); q++) {
            cout <<"\t\t\t"<< q + 1 << " - " << Editors[q]->getEname() << " $"<< Editors[q]->getTotalPrice() << endl;
        }
        cout << "\nChoice: ";

        string c;
        cin >> c;
        unsigned int w = atoi(c.c_str());
        if (w && w <= Editors.size()) {

            cout << "Displaying Description...\n\n";
            Editors[w - 1]->Description();
        }

        else { cout << "\nInvalid command!\n\n"; EditorsInfo(); }
    }
}

void readCompanies() {
    ifstream Database("Companies.txt");

    if (Database.fail()) { cout << "\nFailed accessing Companies"; }
    else {

        while (!Database.eof()) {
            string name;
            string adress;
            string phone;
            string ac;

            Database >> name >> adress >> phone >> ac;
     if (!Database.eof()) { Companies.push_back(new Company(name, adress, phone, ac));
     }
        }
        Database.close();
    }
}


void readUsers() {

    ifstream O;
    O.open("Users.txt");
    if (!O) { cout << "\nProblem importing User data!"; }

    string line;

    while (getline(O, line)) {
        string name, id, budget, adress, phone, gpa;
        istringstream ss(line);
        while (getline(ss, name, ',')){
                getline(ss, id, ',');
                getline(ss, budget, ',');
                getline(ss, adress, ',');
                getline(ss, phone, ',');
                getline(ss, gpa);
            int budgets = atoi(budget.c_str());
            double GPA = atoi(gpa.c_str());
            
            Users.push_back(new User(name,id,budgets,adress,phone,GPA));
        }
    }
    O.close();

}

void readEditors() {

    ifstream C;
    C.open("Editors.txt");

    if (C.fail()) { cout << "\nFailed accessing Editors!\n"; }

    string line;
    while (getline(C, line)) {

        string name,VERSION,id,type, FORMAT,  OSYSTEM, _OriginalSaved, _ColorMode,layers, mf,PortraitCorrection,catalog, masking, traceimage,_vector,SIZE,filter, features,AD, audioformats, montage, effects, motiongraphics, properties, platforms, transitions, story, timeline;
        istringstream qs(line);

        while (getline(qs, type, ',')) {

            if (type == "Complex") {
                getline(qs, name, ',');
                getline(qs, VERSION, ',');
                getline(qs, id, ',');
                getline(qs, FORMAT, ',');
                getline(qs, OSYSTEM, ',');
                getline(qs, _OriginalSaved, ',');
                getline(qs, _ColorMode, ',');
                getline(qs, layers, ',');
                getline(qs, mf, ',');
                getline(qs, PortraitCorrection, ',');
                getline(qs, catalog, ',');
                getline(qs, masking, ',');
                getline(qs, traceimage, ',');
                getline(qs, _vector);
                int Layers = atoi(layers.c_str());
                bool OS=false,PC=false;
                if(_OriginalSaved=="Yes")OS=true;
                if(PortraitCorrection=="Yes")PC=true;

                Editors.push_back(new Complex(name, VERSION, id, FORMAT, OSYSTEM,OS,_ColorMode,Layers, mf, PC, catalog, masking, traceimage,_vector));

            }

            else if (type == "Simple") {
                getline(qs, name, ',');
                getline(qs, VERSION, ',');
                getline(qs, id, ',');
                getline(qs, FORMAT, ',');
                getline(qs, OSYSTEM, ',');
                getline(qs, SIZE, ',');
                getline(qs, _OriginalSaved, ',');
                getline(qs, _ColorMode, ',');
                getline(qs, layers, ',');
                getline(qs, filter, ',');
                getline(qs, features);
               int Layers = atoi(layers.c_str());
                bool OS=0;
               if(_OriginalSaved=="Yes")OS=1;


                Editors.push_back(new Simple(name, VERSION, id, FORMAT, OSYSTEM,SIZE,OS,_ColorMode,Layers,filter,features));
            }

            else if (type == "Social Media") {

                getline(qs, name, ',');
                getline(qs, VERSION, ',');
                getline(qs, id, ',');
                getline(qs, FORMAT, ',');
                getline(qs, OSYSTEM, ',');
                getline(qs, audioformats, ',');
                getline(qs, montage, ',');
                getline(qs, effects, ',');
                getline(qs, motiongraphics, ',');
                getline(qs, properties);

                Editors.push_back(new SocialMedia(name, VERSION, id, FORMAT, OSYSTEM, audioformats, montage, effects, motiongraphics, properties));

        }

        else if (type == "Virtual Reality") {
                       getline(qs, name, ',');
                       getline(qs, VERSION, ',');
                       getline(qs, id, ',');
                       getline(qs, FORMAT, ',');
                       getline(qs, OSYSTEM, ',');
                       getline(qs, audioformats, ',');
                       getline(qs, montage, ',');
                       getline(qs, effects, ',');
                       getline(qs, platforms, ',');
                       getline(qs, transitions, ',');
                       getline(qs, story, ',');
                       getline(qs, timeline);

                Editors.push_back(new VirtualReality(name, VERSION, id, FORMAT, OSYSTEM, audioformats, montage, effects, platforms, transitions, story, timeline));

                   }

               }
    }
    C.close();

}

//BM Algorithm
void HelperMethod( string str, int size,  int tempArr[256])
{
    int i;
    // Initialize all occurrences as -1
    for (i = 0; i < 256; i++)tempArr[i] = -1;
    for (i = 0; i < size; i++)tempArr[(int) str[i]] = i;
}

/* A pattern searching function that uses BadCharacter Heuristic of Boyer Moore Algorithm */
int  CurrOccurances=0;
void searchBM( string txt, string pat)
{
    int m = (int)pat.size();
    int n = (int)txt.size();
    int tempArr[256];
    HelperMethod(pat, m, tempArr);
    int s = 0; // s is shift of the pattern withrespect to text
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])j--;
        if (j < 0)
        {
            CurrOccurances+=1;//this keeps track of the number of occurancies of the word and then sort those in decreasing order.
            if(s+m < n) s+= m-tempArr[txt[s + m]];
            else s+=1;
        }
        else s += max(1, j - tempArr[txt[s + j]]);
    }
}


string lowerWord(string temp){
    string toReturn ="";
    for(char x: temp)
    { toReturn += tolower(x);}
    return toReturn;
}

void importData() {

    readUsers();
    readCompanies();
    readEditors();
}
void SearchCompanies(){
    string finder1;
    cout << "Enter the Company you want to search: \b";
    cin >> finder1;

    vector<pair<int,Company*> > allCompanies;//used the vecor of pair to sort in decreasiing order
    //a loop to calculate and display the total prices of all elements in the Items collection
    for (Company * i : Companies) {
            string UpperString = i -> getCname();
            string toFind = finder1;
            CurrOccurances = 0;
            toFind = lowerWord(toFind);
            UpperString =lowerWord(UpperString);
            searchBM(UpperString,toFind);


            if(CurrOccurances>0)
              allCompanies.push_back(make_pair(CurrOccurances,i));

    }
    sort(allCompanies.begin(),allCompanies.end()); // sort them from number or occurences
    reverse(allCompanies.begin(),allCompanies.end()); // start from biggest
    if(allCompanies.size()==0)cout<<"\n\t\tNo Company with name: "<<finder1<<endl;
    else cout<<allCompanies.size()<< "\t\t Companies found...\n";
    for(auto curr: allCompanies){
      cout<< " \t> "<< curr.second->getCname() <<" ("<< curr.first << ")\t";
  
    }
    
    string choice;
    cout<<"\n\n";
    cout<<"Press 1 to search another Editor or anything to exit: ";
    cin>>choice;
    if(choice=="1")SearchCompanies();
    else OnlineStoreMenu();
}


void SearchEditors(){
    string finder1;
    cout << "Enter the Editor you want to search: \b";
    cin >> finder1;

    vector<pair<int,Editor*> > allEditors;//used the vecor of pair to sort in decreasiing order
    //a loop to calculate and display the total prices of all elements in the Items collection
    for (Editor * i : Editors) {
            string UpperString = i -> getEname();
            string toFind = finder1;
            CurrOccurances = 0;
            toFind = lowerWord(toFind);
            UpperString =lowerWord(UpperString);
            searchBM(UpperString,toFind);


            if(CurrOccurances>0)
              allEditors.push_back(make_pair(CurrOccurances,i));

    }
    sort(allEditors.begin(),allEditors.end()); // sort them from number or occurences
    reverse(allEditors.begin(),allEditors.end()); // start from biggest
    if(allEditors.size()==0)cout<<"\n\t\tNo Editor with name: "<<finder1<<endl;
    else cout<<allEditors.size()<< "\t\tEditors found...\n";
    for(auto curr: allEditors){
      cout<< " \t> "<< curr.second->getEname() <<" ("<< curr.first << ")\t";
      cout<< "  - $"<<curr.second->getTotalPrice()<<endl;
    }
    
    string choice;
    cout<<"\n\n";
    cout<<"Press 1 to search another Editor or anything to exit: ";
    cin>>choice;
    if(choice=="1")SearchEditors();
    else OnlineStoreMenu();
}


void OnlineStoreMenu() {
    string choice;
    do {
        cout << "\n\n\t\t        ▄▀▄▀   WELCOME TO OUR ONLINE STORE   ▀▄▀▄         \n";
        cout << "\t\t✂--------------------------------------------------------\n";
        cout << "\t\t│       1-User Menu         │       3-List Editors      │";
        cout << "\n\t\t│---------------------------│---------------------------│";
        cout << "\n\t\t│       2-Search            │ 4-List Promoted Companies │";
        cout << "\n\t\t│---------------------------│---------------------------│\n";
        cout << "\n\t\t                      ꐕ  0-CLOSE  ꐕ                      \n";

        cout<<"\n\nChoice: ";
        cin >> choice;



           if (choice == "0") { cout << "\n\t\t\t\t\t\t\t * Goodbye! *\n\n"; }
           else if (choice == "1") { UserMenu(); cout << "\nENTER to continue..."; cin.ignore(); cin.ignore(); }
           else if (choice == "3") {
               string choice;
               do { EditorsInfo();
                   cout << "\n\n\t\t\tEnter 0 to exit (or any button to continue) > ";
                   cin>>choice;
               }
               while(choice!="0");
           }
           else if(choice =="2"){
               string c;
               cout<<"Search for companies (1) or Editors (2): ";
               cin>>c;
               
               if(c=="1")SearchCompanies();
                else if (c=="2")SearchEditors();
                else OnlineStoreMenu();
               
               
           }
           else if (choice == "4") { CompanyInfo(); cout << "\nENTER to continue..."; cin.ignore(); cin.ignore();}
           else { cout << "\nInvalid\n"; }
       } while (choice != "0");
}

//-----------------------------------------------Main------------------------------------------------------------Main-------------------------------------------------------------------------------------


int main()
{

    cout << "\n\t\t\t\tPress ENTER to continue ツ\n";
    cin.ignore();

    importData();
    OnlineStoreMenu();

}

