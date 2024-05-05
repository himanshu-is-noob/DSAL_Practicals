#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

class File 
{
    private :
    string name ;
    int roll ;

    public :
    void Accept(int n) ;
    void Display(int n) ;
    void Search(int n,int key) ;
    void Delete(int n,int key) ;
};

void File :: Accept(int n)
{
    ofstream fout("St100.dat" ,ios:: app) ;

    for(int i=0 ; i<n ; i++)
    {
        cout << "Enter Name : " ;
        cin >> name ;

        cout << "Enter Roll No : " ;
        cin >> roll ;

        fout << name << " " << roll << endl ;
    }

    fout.close() ;
}

void File :: Display( int n)
{
    ifstream fin("St100.dat") ;
    for(int i=0 ; i<n ; i++)
    {
        fin >> name >> roll ;

        fin.ignore() ;

        cout << "Name : " << name << "Roll No : " << roll << endl ;
    } 
    fin.close();
}

void File :: Search(int n , int key) 
{
    ifstream fin("St100.dat" ) ;
    bool found = false ;

    while(fin >> name >> roll)
    {
        fin.ignore() ;
        if(key == roll)
        {
            cout << "Name " << name << " " << "Roll No " << roll << endl ;
            found = true ;
            break ;
        }

    }

    if(found!= true)
        {
            cout << "The Element is Not Present ! " << endl ;
        }   
}

void File :: Delete(int n , int key)
{
    ifstream fin("St100.dat") ;
    ofstream f1("f1.dat") ;

    bool found = false ;

    while(fin >> name >> roll)
    {
        fin.ignore() ;
        if(roll == key)
        {
            found = true ;
            cout << "Roll No " << roll << " Deleted Successfully ! " << endl ;
        }
        else
        {
            f1 << name << " " << roll << endl ; 
        }
    }
    fin.close() ;
    f1.close() ;


    remove("St100.dat") ;
    rename("St200.dat" , "St100.dat") ;

    if(!found){
        cout << "Record Not Found " << endl ;
    }
    
}

int main()
{
    File f ;
    int n , key , ch ;

    do{
        cout << "1. Write in File " << endl ;
        cout << "2. Display File " << endl ;
        cout << "3. Search File " << endl ;
        cout << "4. Delete Element " << endl ;
        cout << "0. Exit " << endl ;

        cout << "Enter your Choice : " ;
        cin >> ch ;

        switch(ch)
        {
            case 1:
            cout << "Enter Number of Student Count : " ;
            cin >> n ;
            f.Accept(n) ;
            break ;

            case 2:
            f.Display(n) ;
            break ;

            case 3:
            cout << "Enter Roll No to Search : " ;
            cin >> key ;

            f.Search(n,key);
            break ;

            case 4 : 
            cout << "Enter Roll No to be Deleted : " ;
            cin >> key ;

            f.Delete(n,key) ;
            break ;

        }
    }while(ch!= 0);
}