#include <iostream>
#include <cstring>


class String {
    
public:
    size_t length;
    char* string;

String(){   new char[0]; length=0;  }
String(const char *string);
String(const String &s1);
String(String &&string);
~String();

void setNewText(const char* newText);
size_t getSize(){return length;}
};

String::String(const char* string){
    
    if(string==NULL)
    {
        this->string= new char[1];
        this->string[0]= '\0';
        this->length=0;
        
        std::cout<<"empty string"<<std::endl;
    }
    else{
        this->string = new char[strlen(string)+1];
        
        strcpy(this->string, string);
        std::cout<<this->string<<std::endl;
    }
}
String::~String(){  delete string;  }

String::String(const String &s1)
{
    this->string=s1.string;
    this->length=s1.length;
    std::cout<<this->string<<std::endl;
}
String::String(String &&str)
{
    this->string= str.string;
    this->length=strlen(string);
    str.string=NULL;
}

void String::setNewText(const char* newText){
    
    this->string=strcpy(this->string, newText);
    if(newText=NULL){
        length=0;
        }
    else {
        length=strlen(this->string);
        }
}

int main(){

String s1("Tomasz"), s2(s1);

std::cout<<s1.getSize()<<std::endl;

s2.setNewText("Lisowicz");

std::cout<<s2.string<<std::endl;


}
