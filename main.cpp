// Team Name: Surge

#include <webots/Receiver.hpp>
#include <iostream>
#include <math.h> 
#include <webots/Robot.hpp>
#include <webots/LED.hpp>

#define TIME_STEP 64

using namespace std;
using namespace webots;

Robot *robot = new Robot();

Receiver *receiver; 
char rec_name[10] = {"receiver"};

LED *led[4];
char led_name[4][6] = {"led_1","led_2","led_3","led_4"};


void initReceiver(){ //this function initialize the receiver. This is an example.Don't need to change anything in here.
  receiver = robot->getReceiver(rec_name);
  receiver->enable(TIME_STEP);
}


void initLED(){
//*******************************************************************************
//initialize the LEDs here

  led[0] = robot->getLED(led_name[0]);
  led[1] = robot->getLED(led_name[1]);
  led[2] = robot->getLED(led_name[2]);
  led[3] = robot->getLED(led_name[3]);
  //led[i]->set(3);



//*******************************************************************************
}


void ReceiveAndDecode(){
//*******************************************************************************
//type your code to receive the message, decode it and get the required colour numbers

while(receiver->getQueueLength()>0){
  auto message = reinterpret_cast<unsigned char*>(const_cast<void*>(receiver->getData()));
  //cout<<typeof(message)<<endl;
  //have to add to a array
  
  cout<<"LED ID is : "<<message[0]<<" and Color is : "<<message[2]<<endl;
  //led[0]->set((int)message[2]);
  
  int led_id;
  int col;
  
  if (message[0] == '1'){
    led_id = 0;
    led[led_id]->set(1);
  }
  else if (message[0] == '2'){
    led_id = 1;
    led[led_id]->set(1);
  }
  else if (message[0] == '3'){
    led_id = 2;
    led[led_id]->set(1);
  }
  else if (message[0] == '4'){
    led_id = 3;
    led[led_id]->set(1);
  }
  
  
    
  
  //cout<<message<<endl;
  receiver->nextPacket();

}
//*******************************************************************************
}


int main(int argc, char **argv) {
   
    initReceiver();
    initLED();
    
//*********************************************************************************************
//call the ReceiveAndDecode() function and light up the LEDs in here.Use a while loop if needed.

  
  
  while (robot->step(1000) != -1) {
    
    ReceiveAndDecode();
    
  };

//**********************************************************************************************

    delete robot;
    return 0;
}