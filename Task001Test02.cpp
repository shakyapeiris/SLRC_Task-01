// Team Name: Surge

//Note : This program is normally based on stl++ library.

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

  vector<double> normal = {}; //This is the array which subjected to sorting
  vector<double> edited = {}; //Normal array
  double dsValue; //Variable for reading distance sensor value
  bool consist = false; //Boolean to find whether a pillar of same distance is in the array.
  int round_2; //Value taken by rounding of the dsValue

  int pillar_count = 0;

  //*****************************************************************


  //Main Loop

  while (robot->step(timeStep) != -1) {
  //*****************************************************************
    //type your code here

    motor_1->setVelocity(0.7);//Changed the motor speed without changing the default speed given in line 24
    dsValue = ds->getValue();//Getting the value from distance sensor

    //reading values if it is in the range

    if (dsValue<1000.0 and dsValue>200.0){
         round_2 = round(dsValue);


        //Wait until the ray strikes the object 01 in the second round since every object do not have the same distance and every object has a difference of 10cm

        if (std::find(edited.begin(), edited.end(), round_2) != edited.end() or std::find(edited.begin(), edited.end(), round_2+2)!= edited.end() or std::find(edited.begin(), edited.end(), round_2-2)!= edited.end() or std::find(edited.begin(), edited.end(), round_2+1)!= edited.end() or std::find(edited.begin(), edited.end(), round_2-1)!= edited.end()){
            consist = true;
          }
        else{
          normal.push_back(round_2);
          edited.push_back(round_2);
          pillar_count = pillar_count + 1; //per every reading pillar count increase by 1.
         }
    }


    //Breaking the flow if a reading is already consists in the fixed array

    if (consist or pillar_count >=10){
      //Sorting algorithm
      sort(normal.begin(), normal.end(), greater<double>());

      //giving names and final output
      for (int x=0; x<pillar_count; x++){
        for (int y = 0; y<pillar_count; y++){
          if (normal[x]==edited[y] and edited[y]!=0){
            int term = y+1;
            cout << "Object "<<term<<endl;
            break;
          }
        }
      }
      exit(0);//Once printing is finished exiting the controller
    }
  //*****************************************************************
  };
  delete robot;
  return 0;
}
