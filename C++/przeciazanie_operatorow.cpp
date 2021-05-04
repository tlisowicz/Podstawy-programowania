#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

class NotUnderstandableFile{
    
    std::fstream file;
    std::string filepath;
public:
    NotUnderstandableFile(std::string fpath);
    std::string getPath()const { return filepath; }
    NotUnderstandableFile& operator|=(NotUnderstandableFile& f2);
    NotUnderstandableFile& operator&(NotUnderstandableFile& f2);
    NotUnderstandableFile& operator=(NotUnderstandableFile& f2);
    bool operator==(NotUnderstandableFile& f2);
    friend ostream& operator<<(ostream& os, NotUnderstandableFile& f2);
    friend istream& operator>>(istream& is, NotUnderstandableFile& f2);
    void * operator new(size_t size);
    void  operator delete(void * p);
    operator std::string();
    std::string getcontent();
    int getlinescount();
    ~NotUnderstandableFile() {  this->file.close(); }
};

std::string  NotUnderstandableFile::getcontent()
{
    std::string content;
    std::string line;
    this->file.open(this->getPath(), std::ios::in);
    
    if (this->file.good()==false)
    {  
        perror("Cannot open file");
        exit(1);
    }
    while (getline(this->file, line))
    {
        content+=line;
        content+="\n";
    }
    this->file.close();
    return content;
}

int NotUnderstandableFile::getlinescount()
{
    std::string line;
    int linecount=0;
    this->file.open(this->getPath(), std::ios::in);
    
    if (this->file.good()==false)
    {  
        perror("Cannot open file");
        exit(1);
    }
    while (getline(this->file, line))
    {
        linecount++;
    }
    this->file.close();
    return linecount;
}

NotUnderstandableFile::NotUnderstandableFile(std::string fpath)
{
    filepath=fpath;
}

NotUnderstandableFile &NotUnderstandableFile::operator=( NotUnderstandableFile& f2)
{   
    if (&f2==this) return *this;
    this->file.open(this->getPath(), std::ios::out);
    this->file<<f2.getcontent();
    this->file.close();
    return *this;
}

ostream& operator<<(ostream& os, NotUnderstandableFile& f)
{
    os<<"ZAWARTOSC PLIKU: "<<endl<<f.getcontent()<<endl<<"liczba linii: "<<endl<<f.getlinescount();
    return os;
}

istream& operator>>(istream& is, NotUnderstandableFile& f2)
{
    is>>f2.filepath;
    return is;
}

/**
 * \brief   operator|= overload function 
 *
 * \details This function  checks whether a given argument contains more chars than the object which
 *          called this function. If its true it joins files if not it just returns first parameter
 *
 * \param[in]     this  Refference to NotUnderstandableFile object
 * \param[in]     f2    Refference to NotUnderstandableFile object
 *
 * \return        returns reference to first given parameter
 *             
 * \author        Tomasz Lisowicz
 */
NotUnderstandableFile &NotUnderstandableFile::operator|=(NotUnderstandableFile& f2)
{   
    std::string content, content2;
    content=this->getcontent();
    content2= f2.getcontent();
    this->file.open(this->getPath(), std::ios::app | std::ios::in);
    
    if (this->file.good()==false)
    {  
        perror("Cannot open file ");
        exit(1);
    }
    
    if (strcmp(content.c_str(), content2.c_str())>0)
    {
        this->file<<"\n"<<content2;
    }
    this->file.close();
    return *this;


}

/**
 * \brief  operator& overload function 
 *
 * \details This function  simply joins 2 given files.
 
 * \param[in]     this  Refference to NotUnderstandableFile object
 * \param[in]     f2    Refference to NotUnderstandableFile object
 *
 * \return        returns returns a reference to first parameter given
 *
 * \author        Tomasz Lisowicz
 */

NotUnderstandableFile& NotUnderstandableFile::operator&(NotUnderstandableFile& f2)
{
    this->file.open(this->getPath(), std::ios::app | std::ios::in);
    this->file<<"\n"<<f2.getcontent();
    this->file.close();
    return *this;
}

bool NotUnderstandableFile::operator==(NotUnderstandableFile& f2)
{
    if (&f2==this) return true;
    if(strcmp(this->getcontent().c_str(), f2.getcontent().c_str())==0) { return true;}
    return false;
    
}

void * NotUnderstandableFile::operator new(size_t size)
{
    cout<< "Overloading new operator with size: " << size << endl;
    void * p = malloc(size);
    
    return p;
}

void NotUnderstandableFile::operator delete(void * p)
{
    cout<< "Overloading delete operator " << endl;
    free(p);
}

NotUnderstandableFile::operator std::string()
{
    return this->getcontent();
}


int main(){
    NotUnderstandableFile file("test.txt");
    NotUnderstandableFile file2("kopia.txt"), file3("kopia2.txt");
    
    // cout<<"///////////////(operator=) test///////////////"<<endl;
    // cout<<"===============FILE1==============="<<endl<<file.getcontent()<<endl;
    
    // file2=file3=file;
    
    // cout<<"===============FILE2==============="<<endl<<file2.getcontent()<<endl;
    // cout<<"===============FILE3==============="<<endl<<file3.getcontent()<<endl;
    
    // cout<<"///////////////(operator==) test///////////////"<<endl;
    // bool a;
    // a = (file==file2);  
    // cout<<a<<endl;
    
    // cout<<"///////////////(operator<<) test///////////////"<<endl;
    // cout<<file2<<endl;
    
    // // cout<<"///////////////(operator>>) test///////////////"<<endl;
    // // cout<<file.getPath()<<endl;
    // // cin>>file;
    // // cout<<file.getPath()<<endl;
    
    // cout<<"///////////////(operator&) test///////////////"<<endl;
    // file & file2;
    // cout<<file.getcontent()<<endl;
    
    // std::cout<<"///////////////(operator|=) test///////////////"<<endl;
    // file |= file3;
    // std::cout<<file.getcontent()<<endl;
    
    // std::cout<<"///////////////(operator new and delete) test///////////////"<<endl;
    // NotUnderstandableFile *p = new NotUnderstandableFile("plik.txt");
    // delete p;
    // std::cout<<"///////////////(cast operator ) test///////////////"<<endl;
    // std::string test = (std::string)file;
    // cout<<test;
}


