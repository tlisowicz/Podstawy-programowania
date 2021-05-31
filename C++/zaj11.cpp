#include <iostream>
#include <array>
#include <string>
#define N 10


class VectoredList
{
    class Bucket
    {
    protected:
    
        Bucket* next;
        Bucket* previous;
        int size;
        std::array<std::string, N> values;
    
    public:

        Bucket(): next(nullptr), previous(nullptr), size(0) {}
        ~Bucket(){  delete next; delete previous;   }
        int getSize()const {    return size;    }
        Bucket* getPrevious()const {    return previous;}
        Bucket* getNext()const {    return next;}
        void setNext(Bucket *next){ this->next=next;}
        void setPrevious(Bucket *previous){ this->previous=previous;}
        void incrementSize(){   ++size;   }
        void addValue(std::string s){   values[size] = s;}
        std::string& getValue(int pos){ return values[pos];} 
        
    };

    Bucket* head;
    Bucket* tail;
    size_t size_;
    int capacity_;

    class VectoredListIterator
    {
        VectoredList::Bucket* cursor;
    
    public:

        VectoredListIterator(const VectoredList& l):  cursor(l.head){}
        VectoredListIterator& operator++();
        VectoredList::Bucket* operator*()const;
        bool operator!=(const VectoredListIterator& it);
        VectoredListIterator begin();
        VectoredListIterator end();

    };

public:

    VectoredList(): head(new Bucket), tail(head), size_(1), capacity_(N*size_){};
    VectoredList(VectoredList && v);                                                            //zaj 12
    void push_back(std::string value);
    std::string& operator[](int pos)const;
    VectoredList& operator=(VectoredList && v);
    VectoredList& operator=(const VectoredList& new_vector);
    VectoredList& operator+(const VectoredList& rhs);
    void clean_vector();
    size_t get_size()const{
        if(size_ == 0)
            return 0;
        return (size_-1)*10+tail->getSize();
    }


    ~VectoredList() {   delete head;    }

    

};


VectoredList::VectoredList(VectoredList && v)                                                  //zaj 12
{
    this->head=v.head;
    this->tail=v.tail;
    this->capacity_= v.capacity_;
    this->size_=v.size_;
    v.head= nullptr;
    v.tail= nullptr;
    v.capacity_= 0;
    v.size_=0;
    std::cout<<"Konstruktor przenoszący"<<std::endl;

}
void VectoredList::clean_vector() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
    capacity_ = 0;
}

VectoredList& VectoredList::operator=(VectoredList&& v)
{
    if (this==&v){return *this;}
    this->clean_vector();

    this->head=v.head;
    this->tail=v.tail;
    this->capacity_= v.capacity_;
    this->size_=v.size_;
    v.head= nullptr;
    v.tail= nullptr;
    v.capacity_= 0;
    v.size_=0;

   return *this;
}
void VectoredList::push_back(std::string value)
{
    if (tail->getSize() ==  N)
    {
        Bucket* temp= new Bucket;
        temp->setPrevious(tail);
        tail->setNext(temp);
        tail=temp;
        size_++;
        capacity_+=N;
    }
    Bucket* temp= head;
    while (temp->getSize() == N)
    {
        temp=temp->getNext();
    }
    temp->addValue(value);
    temp->incrementSize();
    

}

std::string& VectoredList::operator[](int pos)const
{   
    int temp=pos/N+1, temp3= pos % N;
    Bucket * temp2=head;
    
    while(temp>1)
    {
        --temp;
        temp2=temp2->getNext();
        

    }
    return temp2->getValue(temp3);                          

}

VectoredList &VectoredList::operator=(const VectoredList &vector_to_copy) 
{
    if(&vector_to_copy!=this)
    {
        if(size_ !=0)
            this->clean_vector();

        for(int i = 0; i < vector_to_copy.get_size(); ++i)
        {
            this->push_back(vector_to_copy[i]);
        }
    }
    return *this;
}

VectoredList& VectoredList::operator+(const VectoredList& rhs)
{
    tail->setNext(rhs.head);
    this->tail=rhs.tail;
    this->size_+=rhs.size_;
    this->capacity_+=rhs.capacity_;
    return *this;
}


// VectoredList::VectoredListIterator& VectoredList::VectoredListIterator::operator++()
// {
//     if (cursor)
//     {
//         cursor=cursor->getNext();
//         return *this;
//     }
// }

//  VectoredList::Bucket* VectoredList::VectoredListIterator::operator*()const
// {
//     return cursor;
// }

// bool VectoredList::VectoredListIterator::operator!=(const VectoredListIterator& it)
// {
//     return cursor==it.cursor;
// }
// VectoredList::VectoredListIterator VectoredList::VectoredListIterator::begin() 
// {    
//     cursor=l.head;   
//     return *this;
// }

// VectoredList::VectoredListIterator VectoredList::VectoredListIterator::end() 
// {    
//     cursor=list.tail;   
//     return *this;
// }
 
 void printVector(const VectoredList& list)                             //REVERSE PRINT
 {
      for(int i=list.get_size(); i>=0; --i)
    {
        
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
 }

int main(){

    //TEST 1
    VectoredList list1;
    for(int i=0; i<101; ++i)
    {
        list1.push_back(std::to_string(i));
    }
    printVector(list1);

    //TEST 2
    // for(auto& i: list1){std::cout<< i<<" ";}
    
    //ZAJ 12 TESTY
    std::cout<<"[move constructor]"<<std::endl;  
    VectoredList list2(std::move(list1));
    printVector(list2);
    
    std::cout<<"[move assigment operator]"<<std::endl;  
    VectoredList list3;
    list3= std::move(list2);
    printVector(list3);
    
    std::cout<<"[operator+ test]"<<std::endl;
    VectoredList list4, list5;
    for(int i=0; i<101; ++i)
    {
        list4.push_back(std::to_string(i));
    } 
    for(int i=50; i>=0; --i)
    {
        list5.push_back(std::to_string(i));
    } 
    list4+list5;
    printVector(list4);

}