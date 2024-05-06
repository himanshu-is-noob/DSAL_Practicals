#include <iostream>
#include <stack>

using namespace std ;

class node 
{
    public :
    string word ,meaning ;
    node* left ;
    node*right ;

    node()
    {
        left = NULL ;
        right = NULL ;
    }
};

class AVL
{
    private :
    node* root ;

    public :
    AVL()
    {
        root = NULL ;
    }

    int height(node* temp)
    {
        if(temp == NULL)
        return 0 ;
        else
        return max(height(temp->left) , height(temp->right)) +1 ;
    }


    void insert()
    {
        string word,meaning ;

        cout << "Enter Word : " ;
        cin >> word ;

        cout << "Enter Meaning: " ;
        cin >> meaning ;
         this->root = insert(this->root,word,meaning);
    }

    node* insert(node* root , string word , string meaning)
    {
        if(root == NULL)
        {
            node* temp = new node() ;
            temp->word = word ;
            temp->meaning = meaning ;
            root = temp ;
            return root ;
        }
        else if(word > root->word){root->right = insert(root->right , word , meaning); return root ;}
        else if(word<root->word){root->left = insert(root->left ,word,meaning);return root ;}
        else return root ;
    }
    
    void display()
    {
        if(this->root == NULL) cout << "Tree is Empty " ;
        cout << "Words are : ";
        dis(this->root ) ;
    }
    
    void dis(node* root)
    {
        if(root!=NULL)
        {
            dis(root->left) ;
            cout << root->word << " ";
            dis(root->right) ;
        }
    }

};

int main(){
    AVL avl;
    int choice;
    bool run = true;
    while (run){
        cout << "MainMenu\n1.AddWord\n3.Display\n4.Exit\nEnter Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                avl.insert();
                break;
            
            case 3:
                avl.display();
                break;
            case 4:
                run = false;
                break;
            default:
                cout << "Invalid Choice!\n";
        }

        cout << "\n";
    }
    return 0;
}