// Team Name: Surge

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>
#include <stdio.h>
//#include <algorithm>
#include <bits/stdc++.h> 
using namespace std; 

using namespace webots;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  int timeStep = 64;
  DistanceSensor*ds;
  ds=robot->getDistanceSensor("distance sensor");
  ds->enable(timeStep);
  
  Motor *motor_1=robot->getMotor("motor");
  motor_1->setPosition(INFINITY);
  motor_1->setVelocity(0.5);
  //*****************************************************************
  //define your variables here
  
  //double readings[10] = {};
  //double sorted[10] = {};
  vector<double> normal = {};
  vector<double> edited = {};
  double dsValue;
  
  int i = 0;
  
  
  //*****************************************************************

  
  while (robot->step(timeStep) != -1) {
  //*****************************************************************
    //type your code here
    motor_1->setVelocity(0.7);
    
    dsValue = ds->getValue();
    
    
    
    
    if (dsValue<1000.0 and dsValue>200.0){
        normal.push_back(dsValue);
        edited.push_back(dsValue);
        i = i+1;
    }
    
    if (i==3){
      sort(normal.begin(), normal.end(), greater<double>());
      for (int x=0; x<3; x++){
        //std::cout<<normal[x]<<std::endl;
        for (int y = 0; y<3; y++){
          if (normal[x]==edited[y]){
            int term = y+1;
            cout << "Object"<<term<<endl;
            break;
          }
        }
      }
      exit(0);
    }  
  //*****************************************************************
    
  };

 
  delete robot;
  return 0;
}