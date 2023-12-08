
/*the aim of this project is to make an automated fan that is controled by  the temperature Redings of a DHT11 sensor ->
if the temp read is greater than a certain value the fan automatically goes on */
#include<DHT.h>
#define PIN_DHT 33
DHT dht(PIN_DHT , DHT11); /*(pin , DHT model ) ->creating an object */

//pins initialization 
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {

  // initializing the DHT11
  dht.begin();
  delay(3000);//2 sec delay 

  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);

  Serial.begin(115200);

  
}

void loop() {
  // put your main code here, to run repeatedly:
 float temp = dht.readTemperature();
 float humidity = dht.readHumidity();

 Serial.print("temp =");
 Serial.print(temp );
 Serial.print( " C   ");
 Serial.print("humidity =" );
 Serial.print(humidity );
 Serial.print("%");
 delay(3000); 
 Serial.println();
  if(temp >=30){
    fan_on();
  }else{
    fan_OFF();
  }
  

}
void fan_on()
{
// Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 

}
void fan_OFF()
{

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  
}