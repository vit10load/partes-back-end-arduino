# back-end prot�tipo do arduino:

Classes Implementadas:

- SIM800http;
A SIM800http � uma das classes chaves do projeto, pois ela tem m�todos respons�veis por configurar o GPS e o GPRS.
Os m�todos s�o:

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
Classe respons�vel por retornar coordenadas de latitude e longitude do m�dulo GPS.



 