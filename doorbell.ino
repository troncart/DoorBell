/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Door Bell**************
***********13-07-2019**************
*/
#define trigPin A2 //Define the HC-SE04 triger on pin 6 on the arduino
#define echoPin A1 //Define the HC-SE04 echo on pin 5 on the arduino
#define sound 8 //Define the relay signal on pin 9 on the arduino
#define buzzer 2

void setup()
  {
    Serial.begin (9600); //Start the serial monitor
    pinMode(trigPin, OUTPUT); //set the trigpin to output
    pinMode(echoPin, INPUT); //set the echopin to input
    pinMode (sound, OUTPUT); //set the bulb on pin 9 to output
    pinMode(buzzer,OUTPUT);
  }

    void loop()
      {
        int duration, distance; //Define two intregers duration and distance to be used to save data
        digitalWrite(trigPin, HIGH); //write a digital high to the trigpin to send out the pulse
        delayMicroseconds(500); //wait half a millisecond
        digitalWrite(trigPin, LOW); //turn off the trigpin
        digitalWrite(sound, HIGH);
        duration = pulseIn(echoPin, HIGH); //measure the time using pulsein when the echo receives a signal set it to high
        distance = (duration/2) / 29.1; //distance is the duration devided by 2 becasue the signal traveled from the trigpin then back to the echo pin, then divide by 29.1 to convert to centimeters
        if (distance < 50) //if the distance is less than 13 CM
          {
            tone(buzzer, 1000); // Send 1KHz sound signal...
            delay(1000);        // ...for 1 sec
            noTone(buzzer);     // Stop sound...
            delay(1000);
            digitalWrite(sound, LOW); //execute the Light subroutine below
         }
      Serial.print(distance); //Dispaly the distance on the serial monitor
      Serial.println(" CM"); //in centimeters
      delay(500); //delay half a second
     }
