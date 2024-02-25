#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

int main()
{
    const double g = 9.80665;  
    const double PI = 3.14159265; 

    string information;

    double Velocity;
    double angle;           
    double Angle; 
    

    double MH;       
    double MD;    
    double TH;       
    double TD;     
   

    cout << endl << string(30, '*') << endl;
    cout << "***** Projectile Motion\n";
    cout << string(30, '*') << endl;

    cout << "Enter the title line information: ";
    getline(cin, information, '\n');
    cout << information << endl;

    cout << setprecision(3) << fixed << left;

    cout << "\nEnter in the velocity(in meters/sec): ";
    cin >> Velocity;
    cout << Velocity << endl;

    cout << "\nEnter in the angle(in degrees): ";
    cin >> angle;
    cout << angle << endl << endl;



    
    Angle = angle * PI / 180.0;

    TH = Velocity * sin(Angle) / g;
  
    TD = 2.0 * Velocity * sin(Angle) / g;

    MH = pow(Velocity, 2) * pow(sin(Angle), 2) / (2.0 * g);
    
    MD = Velocity * TD * cos(Angle);
    
   

    cout << "Results for " << information << endl;
    cout << setprecision(3) << fixed << left;
    cout << setw(25) << "Initial Velocity: " << Velocity << " seconds\n";
    cout << setw(25) << "Starting Angle: " << angle << " degrees\n";
    cout << setw(25) << "Time to Max Height:  " << TH << " seconds\n";
    cout << setw(25) << "Time to Max Distance: " << TD << " seconds\n";
    cout << setw(25) << "Maximum Height: " << MH << " meters" << endl;
    cout << setw(25) << "Maximum Distance: " << MD << " meters\n\n";
    return 0;
}