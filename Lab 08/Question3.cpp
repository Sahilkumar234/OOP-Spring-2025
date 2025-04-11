#include<iostream>
using namespace std;

class Vector2D {
    int x;
    int y;
public:
    Vector2D() {}
    Vector2D(int x,int y) : x(x),y(y) {}

    Vector2D operator+(Vector2D VV) {
        Vector2D VV2;
        VV2.x = x + VV.x;
        VV2.y = y + VV.y;
        return VV2;
    }
    Vector2D operator-(Vector2D VV) {
        Vector2D VV2;
        VV2.x = x - VV.x;
        VV2.y = y - VV.y;
        return VV2;
    }
    Vector2D operator*(int k) {
        Vector2D VV2;
        VV2.x = k*x;
        VV2.y = k*y;
        return VV2;
    }

    friend void dotProduct(Vector2D V2,Vector2D V3);
    friend ostream& operator<<(ostream& OO,Vector2D& V2);
};

ostream& operator<<(ostream& OO,Vector2D& V2) {
    OO<<V2.x<<"i , "<<V2.y<<"j"<<endl;
}

void dotProduct(Vector2D V2,Vector2D V3) {
    int xx = V2.x * V3.x;
    int yy = V2.y * V3.y;
    cout<<"Dot product of Vector1 and Vector2: "<<endl;
    cout<<xx<<"i , "<<yy<<"j"<<endl;
}

int main() {
    Vector2D V11(4,5);
    Vector2D V22(3,3);
    Vector2D V33_add = V11 + V22;
    Vector2D V33_sub = V11 - V22;
    Vector2D V33_mult = V11 * 5;

    cout<<"Vector 1: "<<V11;
    cout<<"<<------------------------------->>"<<endl;
    cout<<"Vector 2: "<<V22;
    cout<<"<<------------------------------->>"<<endl;
    cout<<"Vector1 + Vector2: "<<V33_add;
    cout<<"<<------------------------------->>"<<endl;
    cout<<"Vector1 - Vector2: "<<V33_sub;
    cout<<"<<------------------------------->>"<<endl;
    cout<<"Vector1 * 5: "<<V33_mult;
    cout<<"<<------------------------------->>"<<endl;
    dotProduct(V11,V22);
    
}
