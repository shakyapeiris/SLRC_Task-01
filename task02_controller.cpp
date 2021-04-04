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
  auto message = reinterpret_cast<unsigned char*>(const_cast<void*>(receiver->getData())); //Converting from const void to unsigned char
  

  int led_id;

  //Filtering the message
  
  //LED01
  if (message[0] == '1'){
    led_id = 0;

    if (message[2] == '1'){
        led[led_id]->set(1);
    }
    else if (message[2] == '2'){
        led[led_id]->set(2);
    }
    else if (message[2] == '3'){
        led[led_id]->set(3);
    }
  }
  
  //LED02
  else if (message[0] == '2'){
    led_id = 1;
    if (message[2] == '1'){
        led[led_id]->set(1);
    }
    else if (message[2] == '2'){
        led[led_id]->set(2);
    }
    else if (message[2] == '3'){
        led[led_id]->set(3);
    }
  }
  
  //LED03
  else if (message[0] == '3'){
    led_id = 2;
    if (message[2] == '1'){
        led[led_id]->set(1);
    }
    else if (message[2] == '2'){
        led[led_id]->set(2);
    }
    else if (message[2] == '3'){
        led[led_id]->set(3);
    }
  }
  
  //LED04
  else if (message[0] == '4'){
    led_id = 3;
    if (message[2] == '1'){
        led[led_id]->set(1);
    }
    else if (message[2] == '2'){
        led[led_id]->set(2);
    }
    else if (message[2] == '3'){
        led[led_id]->set(3);
    }
  }
  
  receiver->nextPacket();

}
//*******************************************************************************
}


int main(int argc, char **argv) {

    initReceiver();
    initLED();

//*********************************************************************************************
//call the ReceiveAndDecode() function and light up the LEDs in here.Use a while loop if needed.



  while (robot->step(TIME_STEP) != -1) {

    ReceiveAndDecode(); //Running the external function

  };

//**********************************************************************************************

    delete robot;
    return 0;
}
