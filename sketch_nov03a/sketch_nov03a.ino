#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi ağınızın SSID ve parolasını buraya girin
const char* ssid = "YOUR_SSID";  // Wi-Fi SSID
const char* password = "YOUR_PASSWORD";  // Wi-Fi password

// Sunucu URL'sini buraya girin
const char* serverName = "http://iotapplications.lovestoblog.com/post-data.php";

// Sensör verilerinizi tanımlayın
String sensorName = "Distance";
String sensorLocation = "HomeOffice";

// ESP32'yi başlatın
void setup() {
  Serial.begin(115200);
  
  // Wi-Fi bağlantısını başlatın
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Wi-Fi bağlantısını kontrol edin
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // HTTP POST isteğini başlatın
    http.begin(serverName);

    // Header ekleyin
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Sensör değerlerini burada hesaplayın
    float distance = 0.92;  // Buraya gerçek sensör değerini ekleyin
    String httpRequestData = "sensor=" + sensorName + "&location=" + sensorLocation + "&value=" + String(distance);
    
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    // POST isteği gönderin
    int httpResponseCode = http.POST(httpRequestData);

    // Yanıt kodunu kontrol edin
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    // HTTP istemcisini kapatın
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  
  // Belirli bir süre bekleyin
  delay(30000);  // 30 saniye bekle
}
