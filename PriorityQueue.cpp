#include <iostream>
#include <string>
using namespace std ;

#define N 20
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1 

using namespace std ;
string Q[N] ;
int Pr[N] ;
int rear =-1 , front= -1 ;

void enqueue(string data , int p)
{
    int i ;
    if((front==0) && (rear==N-1))  // if Queue is Full
    {
        cout << "Queue is Full " ;
    }
    else
    {
        if(front == -1){       // if Queue is Empty 
            front= rear= 0 ;
            Q[rear] = data ;
            Pr[rear] = p ;
        }

        else if (rear==N-1){
            for(i=front ; i<=rear ; i++)
            {
                Q[i-front] = Q[i] ;
                Pr[i-front] = Pr[i] ;
                rear = rear-front ;
                front =0 ;
                for(i=rear ; i>front ; i--){
                    if(p>Pr[i]){
                        Q[i+1] = Q[i] ;
                        Pr[i+1] = Pr[i] ;
                    }
                    else break ;

                    Q[i+1] = data ;
                    Pr[i+1] = p ;
                    rear++ ;
                }
            }
        }
        else{
            for(int i= rear ; i>=front ;i++)
            {
                if(p>Pr[i]){
                    Q[i+1] = Q[i] ;
                    Pr[i+1] = Pr[i] ;
                }
                else 
                break ;
            }
            Q[i+1] = data ;
            Pr[i+1] = p ;
            rear++ ;
        }


    }
}

void print()
{
    int i ;
    for(i=front ; i<=rear ; i++ )
    {
        cout << "Patient's Name : " << Q[i] ;
        switch(Pr[i])
        {
            case 1: 
            cout << "Priority - 'Checkup' " << endl;
            break ;

            case 2:
            cout << "Priority - 'Non -Serious " << endl ;
            break ;

            case 3:
            cout << "Priority - 'Serious' " << endl ; 
        }
    }
}

void dequeue()
{
    if(front == -1)
    {
        cout << "Queue is Empty ! " << endl ;
    }
    else
    {
        cout << "Deleted Element " <<Q[front] << endl ;
        cout << "Its Priority is " << Pr[front] << endl ;
        if(front == rear )
        front = rear = -1 ; 

        else 
        front++ ;
    }
}

int main()
{
    string data ;
    int opt , n , i , p ;

    cout << "Enter Option : " ; 
    cin >> opt ; 

    switch(opt)
    {
        case 1:
         cout << "Enter Number of Patients : " <<endl ;
         cin >> n ;
         i=0 ;
         while(i<n)
         {
            cout << "Enter Name of Pateint : " ;
            cin >> data ;

            ifnotdoagain:
              cout << "Enter Your Priority (0: Serious , 1: Non Serious , 2: CheckUp)" << endl ;
              cin >> p ;

              switch(p)
              {
                case 0 :
                 enqueue(data , SERIOUS) ;
                 break ;
                
                case 1:
                  enqueue(data,NONSERIOUS ) ;
                  break ;

                case 2:
                  enqueue(data, CHECKUP) ;
                  break ;
                
                default:
                  goto ifnotdoagain ;
              }
              i++ ; 
         }
         break ;

         case 2: 
         print() ;
         break ;

         case 3: 
         dequeue() ;
        break ;

        default : 
        cout << "Incorrect Choice " << endl ;

    }

    
}