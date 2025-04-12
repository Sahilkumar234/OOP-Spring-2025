#include<iostream>
using namespace std;

class FitnessTracker {
    private:
        string userName;
        int dailyStepGoal;
        int stepTaken;
        double caloriesBurned;
    public:
    void setValue(string userName,int dailyStepGoal) {
        this->userName = userName;
        this->dailyStepGoal = dailyStepGoal;
        stepTaken = 0;
        caloriesBurned = 0.0;
    }
    void logSteps(int steps) {
        stepTaken += steps;
    }
    void calculateCalories() {
        caloriesBurned = stepTaken * 0.05;
    }
    void displayProgress() {
        cout<<"Progress of "<<userName<<" is..."<<endl;
        cout<<endl;
        cout<<"Daily step goal is: "<<dailyStepGoal<<" Steps"<<endl;
        cout<<"Steps taken: "<<stepTaken<<endl;
        cout<<"Calories burned: "<<caloriesBurned<<endl;
    }
};

int main() {
    FitnessTracker F1;
    F1.setValue("Sahil Kumar",4000);
    F1.logSteps(1500);
    F1.calculateCalories();
    F1.displayProgress();

    return 0;
}
