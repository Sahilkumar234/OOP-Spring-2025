
#include<iostream>
using namespace std;

class BMI {
    private:
    string status;
    float weight;
    float BMI;
    float Height;
    
    public:
    void setValue(string status,float weight,float BMI,float Height) {
        this->status = status;
        this->weight = weight;
        this->BMI = BMI;
        this->Height = Height;
    }

    void getInput() {
        cout<<"Enter status: ";
        cin>>status;
        cout<<"Enter "
    }


    float calculateBMI(float weight,float Height) {
        float BMI = weight /(Height*Height) * 703;
        return BMI;
    }
    string findStatus(float BMI) {
        string status;
        if(BMI < 18.5) {
            status = "underWeight";
        }
        else if(BMI < 25.0) {
            status = "Normal";
        }
        return status;
    }
};

int main() {

    return 0;
}
