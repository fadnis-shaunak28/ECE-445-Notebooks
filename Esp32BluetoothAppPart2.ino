
// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h" 
#include <Wire.h>
#include <Adafruit_MLX90614.h>
// definition of the delaytime between button on and button off
#define DELAY 1000                      // delay is in milliseconds, so 1000ms corresponds to 1s
#define TOUCH_THRESHOLD 40  // Adjust this threshold value as needed
#define TOUCH_PIN 27 // Use the specific touch pin where your sensor is connected
// init Class:
BluetoothSerial ESP_BT;

const int mosfetHeater = 12;  // PWM pin connected to MOSFET gate
const int mosfetCooler = 14;  // PWM pin connected to MOSFET gate

// global var for determining which PWM pin
int heatingDevice = 0; // 0 is coil, Peltier is 1

// init PINs: assign any pin on ESP32
int led_pin_1 = 4;
int led_pin_2 = 0;
int led_pin_3 = 2;                      // On some ESP32 pin 2 is an internal LED, mine did not have one
int currentTemp = 0;
// Parameters for Bluetooth interface and timing
int incoming;                           // variable to store byte received from phone 
unsigned long now;                      // variable to store current "time" using millis() function
unsigned long time_button1;             // timestamp for button1 to 3 -> stores time when button is enabled
unsigned long time_button2;
unsigned long time_button3;

bool touch = false;


Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() {
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");        // Name of your Bluetooth interface -> will show up on your phone
  Wire.begin(); 
  mlx.begin();
  touchAttachInterrupt(TOUCH_PIN, touchCallback, TOUCH_THRESHOLD);
  pinMode(mosfetHeater, OUTPUT);  // Set PWM pin as output
  pinMode(mosfetCooler, OUTPUT);  // Set PWM pin as output
  analogWrite(mosfetHeater, 255);
  analogWrite(mosfetCooler, 255);
}
int counter = 0;
void loop() {
  now = millis();                       // Store current time
  
  float ambientTemp = mlx.readAmbientTempC(); // Read ambient temperature
  float objectTemp = mlx.readObjectTempC(); // Read object temperature
  //Serial.println(objectTemp);

  // You only need to pass the string to write() function. No need to pass the length.
  //ESP_BT.write(objectTemp);

  delay(1000);
  bool connection = ESP_BT.connected();
  //Serial.println(temp);
  if(connection){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Sending Temperature: ");
    Serial.print(objectTemp);
    Serial.println("C");
    ESP_BT.write(objectTemp);
  }
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) {
    incoming = ESP_BT.read(); //Read what we receive and store in "incoming"
    if (incoming == 246) {
      heatingDevice = 1;
    } else {
      heatingDevice = 0;
    }
    int button = floor(incoming / 10);
    int value = incoming % 10;    
    //Serial.println(incoming);
    switch (incoming) {
      case 30:  
        Serial.println("Heat Change to: 30C");
        currentTemp = 30;
        break;
      case 45:  
        Serial.println("Heat Change to: 45C");
        currentTemp = 45;
        break;
      case 60:  
        Serial.println("Heat Change to: 60C");
        currentTemp = 60;
        break;
      case 246:
        Serial.println("Heat Change to: -10C");
        currentTemp = -10;
        break;

    }
  }
  determinePower(heatingDevice);
  if(touch){
    analogWrite(mosfetHeater, 255);
    analogWrite(mosfetCooler, 255);
  }
}
void touchCallback() {
  Serial.println(touchRead(TOUCH_PIN));
  analogWrite(mosfetHeater, 255);
  analogWrite(mosfetCooler, 255);
  touch = true;
}
void determinePower(int heatingDev){
  int pwmPin;
  int dutyCycle;
  heatingDev == 0 ? pwmPin = mosfetHeater : pwmPin = mosfetCooler;
  switch (currentTemp) {
      case 30:  
        dutyCycle = 40 * 255 / 100;  // 70% duty cycle
        analogWrite(pwmPin, dutyCycle);  // Output PWM signal
        analogWrite(mosfetCooler, 255);
        delay(1000);  // Delay for stability, adjust as needed
        break;
      case 45:  
        dutyCycle = 25 * 255 / 100;  // 70% duty cycle
        analogWrite(pwmPin, dutyCycle);  // Output PWM signal
        analogWrite(mosfetCooler, 255);
        delay(1000);  // Delay for stability, adjust as needed
        break;
      case 60:  
        dutyCycle = 1 * 255 / 100;  // 70% duty cycle
        analogWrite(pwmPin, dutyCycle);  // Output PWM signal
        analogWrite(mosfetCooler, 255);
        delay(1000);  // Delay for stability, adjust as needed
        break;
      case -10  :
        dutyCycle = 1 * 255 / 100;  // 70% duty cycle
        analogWrite(pwmPin, dutyCycle);  // Output PWM signal
        analogWrite(mosfetHeater, 255);
        delay(1000);  // Delay for stability, adjust as needed
        break;
    }
}
