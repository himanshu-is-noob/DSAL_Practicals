#include <iostream>
#include <string>
#include <fstream>
using namespace std ;

class File
{
   public :
   typedef struct stud{
   int roll_no ;
   char name[20] ;
   char div[3] ;
   char add[100] ;
   }stud;
   
   stud rec ;
   
   
   
   void accept(int n);
   void display(int n) ;
   void Search(int n , int key) ;
   void Delete(int n , int key);
   
};

void File :: accept(int n)
{

   ofstream fout("Student1.dat",ios::binary | ios :: out | ios::app );
    
   for(int i=0 ; i<n ; i++ )
   {  
    cout << endl ;
    cout << "Enter Details of Student " <<i+1 << endl ; 
    cout << "Enter Name : " ;
    cin >> rec.name ;
    
    cout << "Enter Roll Number : " ;
    cin >> rec.roll_no ;
    
    cout << "Enter Div : " ;
    cin >> rec.div ;
    
    cout << "Enter Address : " ;
    cin >> rec.add ;
    

    fout.write((char*)&rec , sizeof(stud))  << flush ; 
    
    
    
   
   }
   fout.close();
     
    
}

void File :: display(int n)
{
   
   cout << "File Details are : " << endl ;
   cout << endl ;
   
   ifstream fin ;
   fin.open("Student1.dat" , ios::binary | ios :: in ) ;
   
   while(fin.read((char*)&rec , sizeof(stud))){
        cout << " Name : " << rec.name << "Roll No : " << rec.roll_no << " Div : " << rec.div << "Address : " <<rec.add <<  endl ;
   }
   
   fin.close() ;
}


void File :: Search(int n , int key)
{
   bool flag = false ;
   ifstream fin ;
   fin.open("Student1.dat" , ios::binary | ios :: in) ;
   fin.seekg(0,ios::beg);
   while(fin.read((char*)&rec ,sizeof(stud)))
   {
       if(key == rec.roll_no)
       {
          cout << " Name : " << rec.name << "Roll No : " << rec.roll_no << " Div : " << rec.div << "Address : " <<rec.add <<  endl ;
          
          bool flag = true ;
       }
   
   }
   
   if(flag == false)
   {
      cout << "Element Not Found ! " << endl ;
      
   }
   
   
}

void File :: Delete(int n , int key)
{
   ifstream fin;
   fin.open("Student1.dat" , ios::binary | ios :: in ) ;
   ofstream temp ;
   temp.open("TempDelete.dat" ,ios :: binary | ios :: out | ios :: app);
   
   
   if (!fin.is_open() || !temp.is_open()) {
      cout << "Error opening files!" << endl;
      return;
   }
   
   
   while(fin.read((char*)&rec , sizeof(stud)))
   {
       if(rec.roll_no != key)
       {
           temp.write((char*)&rec , sizeof(stud))  << flush ;
       }
   }
   
   fin.close() ;
   temp.close() ;
   
   
   remove("Student1.dat");
   
   
   rename("TempDelete.dat", "Student1.dat");

  
   ifstream updatedFile("Student1.dat", ios::binary | ios::in);
   while (updatedFile.read((char*)&rec, sizeof(stud)))
   {
       cout << " Name : " << rec.name << " Roll No : " << rec.roll_no << " Div : " << rec.div << " Address : " << rec.add << endl;
   }
   
   updatedFile.close();
}




int main()
{
  File f ;
  int n;
  int ch ;
  
  cout << "Enter Number of Elements : " ;
  cin >> n ;
  
  do
  {
     cout << "MENU" << endl ;
     cout << "1. Add Data " << endl ;
     cout << "2. Retrieve All Data " << endl ;
     cout << "3. Search " << endl ;
     cout << "4. Delete " << endl ; 
     cout << "0. Exit" << endl ;
     
     cout << "Enter Choice " ;
     cin >> ch ;
     
     switch(ch)
     {
       case 1 : 
       cout << "Enter Number of Students : " ;
       cin >> n ;
  
       f.accept(n);
       break ;
       
       case 2:
       f.display(n) ;
       break ;
       
       case 3:
       int key ;
       cout << "Enter Roll No to Search : " ;
       cin >> key ;
       f.Search(n,key);
       break;

       case 4:
       cout << "Enter Delete Roll : " ;
       cin >> key ;

       f.Delete(n, key) ;
       break ;
       
       
       

       
       
    }
    
  }while(ch!=0);
 
 
 cout << "Exited Successfully ! " ;
 
 //f.accept(n) ;
 //f.display(n);
 
 
  
  return 0 ;
  
}
