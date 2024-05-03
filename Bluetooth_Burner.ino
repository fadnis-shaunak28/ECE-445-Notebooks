#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h> // Include library for descriptors that allow notifications
#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define SERVICE_UUID            "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_TX  "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC_UUID_RX  "abcdef01-2345-6789-abcd-ef0123456789" // RX for receiving data


BLEServer *pServer = nullptr;
BLECharacteristic *pCharacteristicTX;
BLECharacteristic *pCharacteristicRX;
BLEService *pService;
BLEAdvertising *pAdvertising;
bool bleInitialized = false;
unsigned long lastSentTime = 0;  // Last time a notification was sent
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int mosfetGatePin = 18; // Define the GPIO pin connected to the MOSFET gate
bool heat;
bool activate;

class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) override {
      pServer->startAdvertising(); // Restart advertising on connect
    }

    void onDisconnect(BLEServer* pServer) override {
      pServer->startAdvertising(); // Keep advertising on disconnect
    }
};

class MyCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
        if (pCharacteristic == pCharacteristicRX) {
            std::string rxValue = pCharacteristic->getValue(); // Get the value written to the characteristic

            if (rxValue.length() > 0) {
                Serial.println("Received Value: ");
                for (int i = 0; i < rxValue.length(); i++) {
                    Serial.print(rxValue[i]);
                }
                // TODO: Add the actions to perform after receiving the data
                if(rxValue == "Heat"){
                  Serial.println("Heating On");
                  digitalWrite(mosfetGatePin, LOW);
                }
            }
        }
    }
};

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(mosfetGatePin, OUTPUT); // Set the MOSFET gate pin as output
  digitalWrite(mosfetGatePin, HIGH);
  Wire.begin(); 
  mlx.begin();
  initializeBluetooth();
}

void initializeBluetooth() {
  if (!bleInitialized) {
    BLEDevice::init("Bluetooth Burner");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
    pService = pServer->createService(SERVICE_UUID);

    // Characteristic for sending data to client (TX)
    pCharacteristicTX = pService->createCharacteristic(
                          CHARACTERISTIC_UUID_TX,
                          BLECharacteristic::PROPERTY_NOTIFY
                        );
    pCharacteristicTX->addDescriptor(new BLE2902());

    // Characteristic for receiving data from client (RX)
    pCharacteristicRX = pService->createCharacteristic(
                          CHARACTERISTIC_UUID_RX,
                          BLECharacteristic::PROPERTY_WRITE
                        );
    pCharacteristicRX->setCallbacks(new MyCallbacks()); // Set callbacks for write operations

    pService->start();
    pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // Helps with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    bleInitialized = true;
    Serial.println("Bluetooth Initialized and Advertising Started");
    
  }
}

void loop() {
  
  if (millis() - lastSentTime >= 5000) {
    float ambientTemp = mlx.readAmbientTempC();  // Read ambient temperature
    float objectTemp = mlx.readObjectTempC();    // Read object temperature

    // Convert temperature to string and send it over BLE
    char buf[50];
    snprintf(buf, sizeof(buf), "Ambient: %.2f C, Object: %.2f C", ambientTemp, objectTemp);
    pCharacteristicTX->setValue(buf);
    pCharacteristicTX->notify();
    lastSentTime = millis();

    Serial.print("Sent Value: ");
    Serial.println(buf);

    // Toggle LED to indicate activity
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
