#include <BluetoothSerial.h>

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin1 = 14; 
int motor1Pin3 = 33; 
int motor1Pin4 = 25; 
int enable1Pin2 = 32; 


BluetoothSerial SerialBT;
byte BTData;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;


/* Check if Bluetooth configurations are enabled in the SDK */
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

void setup()
{
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin1, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(enable1Pin2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin();
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop()
{
  if(SerialBT.available())
  {
    BTData = SerialBT.read();
    Serial.write(BTData);
  }

  /* If received Character is 1, then turn ON the LED */
  /* You can also compare the received data with decimal equivalent */
  /* 48 for 0 and 49 for 1 */
  /* if(BTData == 48) or if(BTData == 49) */
  if(BTData == '1')
  {
  Serial.println("FORWARD");
  digitalWrite(enable1Pin1,HIGH);
  digitalWrite(enable1Pin2,HIGH);
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH); 
 
  }
  
  /* If received Character is 0, then turn OFF the LED */
  if(BTData == '2')
  {
  Serial.println("BACKWARD");
  digitalWrite(enable1Pin1,HIGH);
  digitalWrite(enable1Pin2,HIGH);
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW); 
   
    
  }
 
  if(BTData == '3')
  {
    Serial.println("RIGHT");
    digitalWrite(enable1Pin1,HIGH);
    digitalWrite(enable1Pin2,HIGH);
  
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, HIGH);
    digitalWrite(motor1Pin4, LOW);
  }
   if(BTData == '4')
  {
    Serial.println("LEFT");
    digitalWrite(enable1Pin1,HIGH);
    digitalWrite(enable1Pin2,HIGH);
  
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, HIGH);
  }
   if(BTData == '5')
  {
    Serial.println("STOPPED");
    digitalWrite(enable1Pin1,LOW);
    digitalWrite(enable1Pin2,LOW);
  
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
  }
}
