#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <SoftwareSerial.h>
#include <IRremote.h>
SoftwareSerial BTserial(10, 11);
int RECV_PIN = 9; //TSOP1738 Output 
int output1 = 2;//to buzzer to indicate obstacle or changed led 



#define code1 2229 //example



IRrecv irrecv(RECV_PIN);//Create the receiver object, using a name of your choice.

decode_results results;//Begin the receiving process. This will enable the timer interrupt which consumes a small amount of CPU every 50 µs.

void setup() {
 BTserial.begin(9600);
Serial.begin(9600); 

irrecv.enableIRIn(); 

pinMode(output1, OUTPUT);



}

void loop() {
  
digitalWrite(output1,LOW);//L
if (irrecv.decode(&results)) {//Attempt to receive a IR code. Returns true if a code was received, or false if nothing received yet. When a code is received, information is stored into "results".

unsigned int value = results.value;

if(value!=2229)
{
  
  digitalWrite(output1,HIGH);//H
  BTserial.print("Clear space!");

BTserial.print(";");

//message to the receiving device

//delay(20);

}
else
{
  digitalWrite(output1,LOW);
   BTserial.print("Change detected!");

BTserial.print(";");

//message to the receiving device

//delay(20);
}


Serial.println(value); // PRINT THE VALUE

irrecv.resume(); // Receive the next value

}

}
