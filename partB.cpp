#include<iostream>
#include<fstream>

using namespace std;

class Product 
{
    private:
    int code;
    double price;
    int quantity;

    public:
    Product(int c=0, double p=0,int q=0)

    {
        set(c,p,q);

    }
    void set(int c,double p,int q)
    {
        code=c;
        price=p;
        quantity=q;
    }
    void setCode(int c){code=c;}
    void setPrice(double p){price=p;}
    void setQuantity(int q){quantity=q;}

    int getCode()const {return code;}
    double getPrice()const {return price;}
    int getQuantity()const {return quantity;}

};

int main()
{
    Product products[100];
    int n;
    int code,qty;
    double price;

    cout<<"Enter how many products: ";
    cin >>n;

    for(int i=0;i<n;i++) 
    {
        cout<<"Enter product #"<<(i+1)<<": "<<endl;
        cout<<"Code=> ";
        cin >> code;

        cout<<"Price=> ";
        cin >> price ;

        cout<<"Quantity=> ";
        cin >> qty;

        products[i].setCode(code);
        products[i].setPrice(price);
        products[i].setQuantity(qty);
    }

    fstream fout;
    fout.open("product.dat", ios::out|ios::binary);
    fout.write((char*)&products, sizeof(Product)*n);
    fout.close();


    cout<<endl;
    cout<<"No.\t Product Code \t Price \t Quantity \t Total"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<(i+1)<<"\t"
        <<products[i].getCode()<<"\t\t"
        <<products[i].getPrice()<<"\t"
        << products[i].getQuantity()<<"\t"<<
        products[i].getPrice()*products[i].getQuantity()<<endl;


    }

    cout<<endl;
    cout<<"Dear user, It has been save to binary file."<<endl;


    return 0;
}