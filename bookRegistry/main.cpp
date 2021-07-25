#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


class book {
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;
public:
    book () {
    author = new char [20];
    title = new char [20];
    publisher = new char [20];
    price = new float;
    stock = new int;
    }
    void feedData();
    void editData();
    void showData();
    int search (char[], char []);
    void buyBook();


};

void book::feedData() {
    cin.ignore();
    cout<<"Enter your name: "; cin.getline(author, 20);
    cout<<"Enter the title of the book: "; cin.getline(title, 20);
    cout<<"Enter publisher name: "; cin.getline(publisher, 20);
    cout<<"Enter price: "; cin>>*price;
    cout<<"Enter stock position: "; cin>>*stock;
}

void book::editData() {
    cin.ignore();
    cout<<"Enter your name: "; cin.getline(author, 20);
    cout<<"Enter the title of the book: "; cin.getline(title, 20);
    cout<<"Enter publisher name: "; cin.getline(publisher, 20);
    cout<<"Enter price: "; cin>>*price;
    cout<<"Enter stock position: "; cin>>*stock;
}

void book::showData() {
    cout<<"Author: "<<author<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Stock position: "<<stock<<endl;
}

int book::search(char tBuy[20], char aBuy[20]) {
    if(strcmp(tBuy, title) == 0 && strcmp(aBuy, author) == 0)
        return 1;
    else return 0;
}
void book::buyBook() {
    int count;
    cout<<"Enter amount of books to buy: "<<endl;
    cin>>count;
    if (count == *stock){
        *stock = *stock - count;
    cout<<"Books bought successfully!"<<endl;
    cout<<"\nAmount:  EUR"<<(*price)*count;
    }
    else
        cout<<"Required copies not in stock."<<endl;
}

int main ()
{
    book *B[20];
    int i=0, r, t, choice;
    char titleBuy[20], authorBuy[20];
    while (1) {
        cout<<"\n\n\t\tMenu"
        <<"\n[1] Entry of a new book"
        <<"\n[2] Buy a book"
        <<"\n[3] Search for a book"
        <<"\n[4] Edit details of a book"
        <<"\n[5] Exit"
        <<"\n\nEnter your choice: ";
        cin>>choice;
    }
    switch (choice) {
    case 1: B[i] = new book;
            B[i]->feedData();
            i++; break;
    case 2: cin.ignore();
            cout<<"Enter the title of the book: "; cin.getline(titleBuy,20);
            cout<<"Enter the author of the book: "; cin.getline(authorBuy,20);

            for (t=0; t<i; t++){
            if(B[t]->search (titleBuy, authorBuy)) {
                cout<<"Book found succesfully!";

            B[t]->showData();
            break;
            }
            if (t==1) {
                cout<<"This book isn't in stock.";
                break;
            }
        }
    case 3: cin.ignore();
            cout<<"Enter the title of the book: "; cin.getline(titleBuy,20);
            cout<<"Enter the author of the book: "; cin.getline(authorBuy,20);
            for (t=0; t<i; t++){
            if(B[t]->search (titleBuy, authorBuy)) {
                cout<<"Book found succesfully!";

            B[t]->showData();
            break;
        }
        if (t == i) {
            cout<<"This book not in stock";
            break;
        }
    }
    case 4: cin.ignore();
            cout<<"Enter the title of the book: "; cin.getline(titleBuy,20);
            cout<<"Enter the author of the book: "; cin.getline(authorBuy,20);
            for (t=0; t<i; t++){
            if(B[t]->search (titleBuy, authorBuy)) {
                cout<<"Book found succesfully!";

            B[t]->editData();
            break;
        }
        if(t==i)
        {
            cout<<"This book is not in stock";
            break;
        }
    }
    case 5: exit (0);
    default: cout<<"Invalid choice entered.";
}
return 0;
}










