#include <DHT.h>
#include <SPI.h>
#include <Ethernet.h>


//===============para Ethernet===============
byte mac[] = {  0x90, 0xA2, 0xDA, 0x0D, 0x4E, 0xD7 }; // MAC de la tarjeta ethernet shield
byte ip[] = { 192, 168, 0, 150 }; // Direccion ip local(puede variar dependiendo de tu router .0 o .1 )
byte server[] = { 192, 168, 0, 103 }; // Direccion ip del servidor (tenes que ver que ip tiene tu pc y colocar aqui)
EthernetClient client;
//=====================================================
void setup() {

  Serial.begin(9600); // Initialize serial communications with the PC

  //=====================ETHERNET======================
  Ethernet.begin(mac, ip); // inicializa ethernet shield
  delay(1000); // espera 1 segundo despues de inicializar



}

void loop() {
enviaAlServidor("Angel");//va enviar la palabra Angel Eso te tiene que guardar en tu php
}




void enviaAlServidor(String datos) {
  datos.replace(" ", "_");

  if (client.connect(server, 80)) {  // Se conecta al servidor
    client.print("GET /php/nuevousuario.php?nombre="); //en la pc tenes que instalar un servidor apache xampp. y colocar una carpeta en www/html 
    client.print(datos);
    client.println("&apellido=mori");
    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    Serial.println("enviando...");
  }
  else
  {
    // Serial.println("Falla en la conexion");
  }
  if (client.connected()) {}
  else {
    // Serial.println("Desconectado");
  }
  client.stop();
  client.flush();

}

