# back-end protótipo do arduino:

Classes Implementadas:

- SIM800http;
A SIM800http é uma das classes chaves do projeto, pois ela tem métodos responsáveis por configurar o GPS e o GPRS.
Os métodos são:

configGprs();
openBearer();
HttpInit();
HttpTerminate();
setUrl();
setContent();
boolean HttpPost();
String HttpGet();
String getLocation();
boolean executeCommand(String comm);
	
- TinyGps;
Classe responsável por retornar coordenadas de latitude e longitude do módulo GPS.



 