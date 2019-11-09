#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>

#define WIFI_SSID "<<Your SSID Here>>"
#define WIFI_PASSWORD "<<WiFi Password Here>>"
#define FIREBASE_HOST "<<Firebase Host Name Here>>"
#define FIREBASE_AUTH "<<Firebase Database Secretes Auth KEY Here>>"
int r,g,b;


void setup()
{
Serial.begin(115200);

pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);





  delay(2000);
  Serial.println('\n');
  
  wifiConnect();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  delay(10);
}

void loop()
{  
if (Firebase.failed())
  {
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Serial.println(Firebase.error());
    delay(10);
    Serial.println("Error connecting firebase!");

    

    
    
  }
  
Serial.println(Firebase.error());  






r= Firebase.getString("r").toInt();
g= Firebase.getString("g").toInt();
b= Firebase.getString("b").toInt();

Serial.println(r);
Serial.println(g);
Serial.println(b);

analogWrite(D0,r);
analogWrite(D1,g);
analogWrite(D2,b);




delay(10);

if(WiFi.status() != WL_CONNECTED)
{
  wifiConnect();
}
delay(10);


}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       // Wait for the Wi-Fi to connect
    delay(10);
    Serial.print(++teller); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}