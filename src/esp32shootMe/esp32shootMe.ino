#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "##Ashen"; //wifi name
const char* password = "##Ser200"; //pass
WiFiUDP udp;
const unsigned int localPort = 20056; 

// Variables to store received data
float x1_pos, y1_pos, x2_pos, y2_pos, score, class_id, actualX, actualY, centerX, centerY;
int x_thresh = 320;
int y_thresh = 240;
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi connected.");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    udp.begin(localPort);
    Serial.println("UDP server started.");


  //real work....
  pinMode(26 , OUTPUT);
  pinMode(25, OUTPUT);

}

void loop() {
  // Check for a client connection
  char packetBuffer[255];
    int packetSize = udp.parsePacket(); //parsePacket checks if phacket has been recived
    if (packetSize) { // if data received
        int len = udp.read(packetBuffer, 255); //read stores data into packetBuffer array
        if (len > 0) {
            packetBuffer[len] = '\0'; // Null-terminate the buffer
            parseData(packetBuffer);
            Serial.println("Received: " + String(packetBuffer));
            
        }
    }

 
}

// Parse the received string and assign to variables
void parseData(String data) {
  delay(200); //remove this delay
  int index = 0;
  String parts[10];

  // Split the data string by commas
  while (data.indexOf(',') >= 0 && index < 10) {
    parts[index++] = data.substring(0, data.indexOf(','));
    data = data.substring(data.indexOf(',') + 1);
  }
  parts[index] = data; // Add the last part

  // Assign the parsed values to variables
  x1_pos = parts[0].toFloat(); //converting string to float
  y1_pos = parts[1].toFloat();
  x2_pos = parts[2].toFloat();
  y2_pos = parts[3].toFloat();
  score = parts[4].toFloat();
  class_id = parts[5].toFloat();
  actualX = parts[6].toFloat();
  actualY = parts[7].toFloat();
  centerX = parts[8].toFloat();
  centerY = parts[9].toFloat();

  // Print the values
  Serial.print("Parsed values:");
  Serial.print(" x1_pos: " + String(x1_pos));
  Serial.print(" y1_pos: " + String(y1_pos));
  Serial.print(" x2_pos: " + String(x2_pos));
  Serial.print(" y2_pos: " + String(y2_pos));
  Serial.print(" score: " + String(score));
  Serial.print(" class_id: " + String(class_id));
  Serial.print(" actualX: " + String(actualX));
  Serial.print(" actualY: " + String(actualY));
  Serial.print(" centerX: " + String(centerX));
  Serial.print(" centerY: " + String(centerY));

  //WORK HERE
   Work();
  

  
}


void Work(){
  int roundedX = round(actualX);
  int roundedY = round(actualY);
  
  if (roundedX > x_thresh) {
    digitalWrite(26, HIGH);
  } 
  else{
    digitalWrite(26 , LOW);
  }
  if(roundedY < y_thresh){
    digitalWrite(25 , HIGH);
  }
  else{
    digitalWrite(25, LOW);
  }
 
}