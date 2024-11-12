  #include <WiFi.h>
  #include <HTTPClient.h>
 
 
const char* ssid = "Ashraf  TV ";
const char* password = "asm@05666600099";
 
const char* serverName = "https://unpardoning-baselin9.000webhostapp.com/post-data.php";
 
String apiKeyValue = "4TOc7~@b";
 
String sensorName = "Touch";
String sensorLocation = "HomeOffice";
 
 
void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to the Wifi Network");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi is Connected at this IP Address : ");
  Serial.println(WiFi.localIP());
 
 
}
 
void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    
    http.begin(serverName);
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                          + "&location=" + sensorLocation + "&value1=" + "value1"
                          + "&value2=" + "value2" + "&value3=" + "value3" + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
 
    int httpResponseCode = http.POST(httpRequestData);
     
 
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
 
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(30000);  
}
