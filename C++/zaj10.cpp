#include <iostream>
#include <cstring>

using namespace std;

class String{
    
    char* tekst;
    size_t size;

public:
    
    String(): size(0), tekst(new char[0])  {}
    String(const char* s1): size(s1!=nullptr ? strlen(s1)+1 : 0), tekst(new char[size])
    {    
        if(s1==nullptr) throw std::invalid_argument("empty string"); 
        std::copy(s1, s1+size, this->tekst);
    }
    String(const String& s1): size(s1.size), tekst(new char[size])
    {
        if(s1.text()==nullptr) throw std::invalid_argument("empty string"); 
        std::copy(s1.text(), s1.text()+size, this->tekst);
    }
    ~String(){  delete [] tekst; }
    char* text()const{ return tekst; }
    size_t Size()const { return size; }
    String& operator=(const char* newText);
    String& operator=(const String& newText);
    String& operator+=(const char* text2Append);
    String& operator+(const char* text2Append); 
    friend ostream& operator<<(ostream& os, String& s1 );
    friend istream& operator>>(istream& is, String& s1 );
};

String& String::operator=(const char* newText)
{
    if (newText==nullptr) throw std::invalid_argument("empty string"); 
    this->size= sizeof(newText);
    this->tekst= new char[size];
    std::copy(newText, newText+size, this->tekst);
    return *this;
}

String& String::operator=(const String& newText)
{
    if (&newText==this) return *this;
    this->size=newText.Size();
    this->tekst= new char[size];
    std::copy(newText.text(), newText.text()+size, this->tekst);
    return *this;
}

String& String::operator+=(const char* text2Append)
{
    strcat(this->tekst, text2Append);
    return *this;
}

String& String::operator+(const char* text2Append)                  //do poprawy
{
    strcat(this->tekst, text2Append);
    return *this;
}

ostream& operator<<( ostream& os, String& s1)
{
    os<<s1.text()<<endl;
    return os;
}

istream& operator>>(istream& is, String& s1)
{
    is>>s1.tekst;
    return is;
}
int main(){

    String s1("some random words"), s5;
    cout<<"TEST KONSTRUKTOROW s1('...')"<<endl;
    cout<<s1.text()<<endl;
    
    cout<<"TEST KONSTRUKTOROW s2=s1"<<endl;
    s5=s1;

    cout<<s5.text()<<endl;

    cout<<"TEST OPERATORÓW"<<endl;
    cout<<"TEST s=s2=s3"<<endl;
    String s, s2, s3("some random text ");
    s=s2=s3;
    cout<<"s: "<< s.text()<<endl;
    cout<<"s2: "<< s2.text()<<endl;
    cout<<"s3: "<< s3.text()<<endl;

    cout<<"TEST s3=s3"<<endl;
    s3=s3;
    cout<<s3.text()<<endl;
    cout<<"TEST s3+=const char*"<<endl;
    s3+= "cos dodaje ";
    cout<<s3.text()<<endl;
    //s = s3 + "dasdasdas    ";
    // cout<<s.text()<<endl;
    cout<<s3;
    //cin>>s3

}