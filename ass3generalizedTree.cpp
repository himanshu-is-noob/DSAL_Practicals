#include <iostream>
#include <string>

using namespace std ;

struct node
{
    char label[10] ;
    int ch_count ;
    struct node* child[10] ;
}*root ;

class GT
{
    public :
    void create_tree();
    void display(node* r1);

    GT()
    {
        root = NULL ;
    }
};

void GT :: create_tree()
{
    int tbook , tchapters, i ,j , k;
    root = new node ;
    cout << "Enter Name of Book : " ;
    cin >> root ->label ;

    cout << "Enter Number of Chapters in book : " ;
    cin >> tchapters ;

    root->ch_count = tchapters ;
    for(int i=0 ; i<tchapters ; i++)
    {
        root->child[i] = new node ;
        cout << "Enter Chapter Name : " ;
        cin >> root -> child[i] ->label ;
        cout << "Enter No of sections in Chapter " << root->child[i] ->label ;
        cin >> root ->child[i] ->ch_count  ;
        for(j=0 ; j<root->child[i] ->ch_count ; j++){
            root->child[i] ->child[j] = new node ;
            cout << "Enter Section " << j+1 << " name : " ;
            cin >> root -> child[i] -> child[j] -> label ; 
        }
    }

}

void GT :: display(node* r1)
{
    int i,j,k,tchapters ;
    if(r1 != NULL)
    {
        cout << "---Book Hierarchy---" ;
        cout << "Book Title " << r1->label ;
        tchapters = r1->ch_count  ;

        for(int i=0 ; i<tchapters ; i++)
        {
            cout << "Chapter " << i+1 ;
            cout << " " << r1->child[i] ->label << endl;
            cout << "Sections " ;
            for (int j=0 ; j<r1->child[i] ->ch_count ; j++)
            {
                cout << " " << r1->child[i] ->child[j] ->label << endl ;
            }
        }
    }
}

int main()
{
    int choice ;
    GT gt ;

    while(1)
    {
        cout << "Book Tree Creation" << endl ;
        cout << "1. Create " << endl ;
        cout << "2. Display " << endl ; 
        cout << "3. Quit " << endl ;

        cout << "Enter Your Choice : " ;
        cin >> choice ;

        switch(choice)
        {
            case 1 :
              gt.create_tree() ;
              break ;
            
            case 2 : 
               gt.display(root) ;
               break ;

            case 3 :
               exit(1) ;
               break ;
        }
    }
}

