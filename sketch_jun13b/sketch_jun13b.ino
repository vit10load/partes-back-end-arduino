#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <SIM800HTTP.h>

SoftwareSerial ss(6, 7);
TinyGPSPlus gps;
SIM800HTTP sim800(1);

String latitude;
String longitude;

void enviarCoordenadas(String lati, String lon){
     if(longitude != "0" && latitude !="0" ){        
         sim800.setContent("{\"latitude\":\""+lati+"\", \"longitude\":\""+lon+"\" }","application/json"); 
         sim800.httpPost();
     }
}

void adquirirCoordenadas(){
  ss.flush();
  while (ss.available()){
    if (gps.encode(ss.read())){
        if (gps.location.isUpdated()){
            latitude = String(gps.location.lat(), 7);
            longitude = String(gps.location.lng(), 7);
            enviarCoordenadas(latitude,longitude);   
        } else{
            latitude = "0";
            longitude = "0";
        }
     }
  }
}

void setup() {
  latitude = "0";
  longitude = "0";
  sim800.begin(9600);
  ss.begin(4800);
  while(!sim800.configGprs("zap.vivo.com.br"));
  sim800.openBearer();
  sim800.httpInit();  
  sim800.setURL("http://petrastreio.herokuapp.com/rest/coords");   
}

void loop() {
    adquirirCoordenadas(); 
}

