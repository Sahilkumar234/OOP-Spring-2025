#include<iostream>
using namespace std;

class Library {
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];
    int listCount = 0;
    int borrowedCount = 0;
    int availableCount = 0;

    public:
        void addBooks(string BookName) {
            if(listCount < 100) {
                bookList[listCount++] = BookName;
                availableBooks[availableCount++] = BookName;
                cout<<"The Book ["<<BookName<<"] added successfully..."<<endl;
            }
            else {
                cout<<"Invalid Data...."<<endl;
            }
        }
        void lendBooks(string BookName) {
            bool found = false;
            for(int i=0;i<availableCount;i++) {
                if(availableBooks[i] == BookName) {
                    borrowedBooks[borrowedCount++] = BookName;
                    for(int j=i;j<availableCount-1;j++) {
                        availableBooks[j] = availableBooks[j+1];
                    }
                    availableCount--;
                    found = true;
                    cout<<"Book ["<<BookName<<"] has been borrowed.."<<endl;
                    break;
                }
            }
            if(!found) {
                cout<<"Book "<<BookName<<" is not available to borrow..."<<endl;
            }
        }
        void returnBooks(string BookName) {
            bool found = false;
            for(int i = 0 ; i < borrowedCount ; i++) {
                if(borrowedBooks[i] == BookName) {
                    availableBooks[availableCount++] = BookName;
                    for(int j=i;j<borrowedCount-1;j++) {
                        borrowedBooks[j] = borrowedBooks[j+1];
                    }
                    borrowedCount--;
                    found = true;
                    cout<<"Book "<<BookName<<" has been returned.."<<endl;
                    break;
                }
            }
            if(!found) {
                cout<<"Book "<<BookName<<" is not available to return..."<<endl;
            }
        }

        void displayBooks() {
            cout<<endl;
            cout<<"Total Books in Library...."<<endl;
            for(int i=0;i<listCount;i++) {
                cout<<"Book "<<i+1<<": "<<bookList[i]<<endl;
            }
            cout<<endl;
        }
        void displayBorrowedBooks() {
            cout<<endl;
            cout<<"Borrowed books in library..."<<endl;
            for(int i=0;i<borrowedCount;i++) {
                cout<<"Borrowed Book "<<i+1<<": "<<borrowedBooks[i]<<endl;
            }
        }
        void displayAvailableBooks() {
            cout<<endl;
            cout<<"Available books in library..."<<endl;
            for(int i=0;i<availableCount;i++) {
                cout<<"Available Book "<<i+1<<": "<<availableBooks[i]<<endl;
            }
        }
};

int main() {
    Library L1;
    L1.addBooks("Atomic HAbits");
    L1.addBooks("The monk who sold his ferrari");
    L1.addBooks("In Cold Blood");

    L1.displayBooks();

    L1.lendBooks("In Cold Blood");
    L1.displayAvailableBooks();
    L1.displayBorrowedBooks();

    L1.returnBooks("In Cold Blood");
    L1.displayAvailableBooks();
    L1.displayBorrowedBooks();

    return 0;
}
