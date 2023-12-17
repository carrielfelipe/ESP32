   #include <WiFi.h>
  #include <HTTPClient.h>

  String UniqueID = "noface";
  float valor_enviar = 100;

// Replace with your network credentials
const char* ssid     = "Fourier";
const char* password = "12345678";




const char* APP_SERVER = "script.google.com";
const char* KEY = "key"; 





void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;

    String URL = "https://script.google.com/macros/s/";

    URL += KEY;
    URL += "/exec?";
    URL += "UniqueID=";
    URL += UniqueID;
    URL += "&temperatura=";
    URL += valor_enviar;
    URL += "&humedad=" ;
    URL += valor_enviar;
    URL += "&humedadtierra=" ;
    URL += valor_enviar;
  
  

    Serial.println("[HTTP] begin...");
    Serial.println(URL);

    // Your Domain name with URL path or IP address with path
    http.begin(URL);
    int httpCode = http.GET();
    Serial.print("[HTTP] GET... code: ");
    Serial.println(httpCode);

   // http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
  //delay(10000);
}
