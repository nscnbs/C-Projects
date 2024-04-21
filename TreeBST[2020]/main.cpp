#include <iostream>
#include <math.h>
#include <string.h>
#include <strstream>
using namespace std;

typedef double T;

class TreeElement{
    public:
    T element;
    TreeElement* parent=NULL;
    TreeElement* left=NULL;
    TreeElement* right=NULL;

    TreeElement(T element){
        this->element=element;
    }
};

class Tree{
    public:
    TreeElement* root;


    //dodanie elementu do drzewa
    void insert(T n, TreeElement* start){
        if (root == NULL){
            root = new TreeElement(n);
        }
        else if(n < start->element){
            if(start->left != NULL){
                insert(n, start->left);
            }

            else{
                TreeElement* nowy = new TreeElement(n);
                nowy->parent = start;
                start->left = nowy;
            }
        }
        else{
            if(start->right!=NULL){
                insert(n, start->right);
            }

            else{
                TreeElement* nowy = new TreeElement(n);
                nowy->parent = start;
                start->right = nowy;
            }
        }
    }


    //sprawdza, czy element istnieje
    void isElement(T element,TreeElement* start){
        if(searchElement(start,element)!=NULL){
            cout<<"Element "<< element <<" istnieje w drzewie"<<endl;
        }
        else{
            cout<<"Element "<<element<<" nie isnieje w drzewie"<<endl;
        }
    }


    //funkcja zwraca wezel o podanej wartosci, badz NULL, gdy taki wezel nie istnieje
    TreeElement* searchElement(TreeElement* start, T element){
        if (start->element == element){
            return start;
        }
        else if (element < start->element && start->left != NULL){
            return searchElement(start->left, element);
        }
        else if (element > start->element && start->right != NULL){
            return searchElement(start->right, element);
        }
        return NULL;
    }


    //funkcja zwraca wskaznik elementu o najmniejszej wartosci (najbardziej na lewo)
    TreeElement* minimum(TreeElement* start){
        if(start->left != NULL){
            return minimum(start->left);
        }
        else{
            return start;
        }
    }


    //usuwa węzeł, który ma potrzebną wartość
    void deleteElement(TreeElement* start){

        if(start->left==NULL && start->right==NULL){
            if(start->parent==NULL){
                root=NULL;
            }
            else if(start->parent->left==start){
                start->parent->left=NULL;
            }
            else{
                start->parent->right=NULL;
            }

            delete start;
        }

        else if(start->left==NULL || start->right==NULL){
            if(start->left==NULL){
                if(start->parent==NULL){
                    root=start->right;
                }

                else if(start->parent->left==start){
                    start->parent->left=start->right;
                }
                else{
                    start->parent->right=start->right;
                }
            }
            else{
                //jezeli wezel jest korzeniem
                if(start->parent==NULL){
                    root=start->left;
                }
                //jezeli wezel jest po lewej stronie rodzica
                else if(start->parent->left==start){
                    //przyczep z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
                    start->parent->left=start->left;
                }
                else{
                    //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                    start->parent->right=start->left;
                }
            }
            delete start;
        }
        else{
            //wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
            TreeElement *temp;
            temp=minimum(start->right);
            start->element = temp->element;
            deleteElement(temp);
        }
    }


    //wydruk drzewa Preorder
    void draw(TreeElement* w){
        if( w!=NULL ){
            cout<<"(<"<<w->element<<"> L:";
            draw(w->left);
            cout<<" R:";
            draw(w->right);
            cout<<")";
        }
        else{
            cout<<"NULL";
        }
    }
};


//to nie java :(
int main(int argc, char *argv[]){
    Tree* tree = new Tree();
    string s;
    int i;
    k:
    cout <<endl<< "i - insert; d - draw; s - search; del - delete; q - exit"<<endl;
    cout << "Wprowadz operacje: ";
    cin >> s;
    if(s == "i"){
        cout << "Podaj element: ";
        cin >> i;
        tree->insert(i, tree->root);
        cout << "Element " << i << " dodany"<<endl;
        goto k;
    }
    else if(s == "d"){
        tree->draw(tree->root);
        cout<<endl;
        goto k;
    }
    else if(s == "s"){
        cout << "Podaj element: ";
        cin >> i;
        tree->isElement(i,tree->root);
        goto k;
    }
    else if(s == "del"){
        cout << "Podaj element: ";
        cin >> i; 
        tree->deleteElement(tree->searchElement(tree->root,i));
        cout << "Element " << i << " usuniety"<<endl;
        goto k;
    }
    else if(s == "q"){
        cout << "Do widzenia!";
        return 0;
    }
    else{
        cout<<"Nie ma takiej opcji"<<endl;
        goto k;
    }
}