#include <Arduino.h>
#include <IRremote.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "teste";
const char* password = "12345678";

IRrecv recv(16); //D2
IRsend irSender;

IPAddress local_IP(192,168,18,150);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

// botão de ligar
//FC03EF00
//Protocol=NEC Address=0xEF00 Command=0x3 Raw-Data=0xFC03EF00 32 bits LSB first

// botão de desligar
//FD02EF00
//Protocol=NEC Address=0xEF00 Command=0x2 Raw-Data=0xFD02EF00 32 bits LSB first

// led vermelho
//FB04EF00
//Protocol=NEC Address=0xEF00 Command=0x4 Raw-Data=0xFB04EF00 32 bits LSB first

// led verde
//FA05EF00
//Protocol=NEC Address=0xEF00 Command=0x5 Raw-Data=0xFA05EF00 32 bits LSB first

// led azul
//F906EF00
//Protocol=NEC Address=0xEF00 Command=0x6 Raw-Data=0xF906EF00 32 bits LSB first

// led branco
//F807EF00
//Protocol=NEC Address=0xEF00 Command=0x7 Raw-Data=0xF807EF00 32 bits LSB first

// aumenta brilho
//FF00EF00
//Protocol=NEC Address=0xEF00 Command=0x0 Raw-Data=0xFF00EF00 32 bits LSB first

// diminui brilho
//FE01EF00
//Protocol=NEC Address=0xEF00 Command=0x1 Raw-Data=0xFE01EF00 32 bits LSB first

// liga flash
//F40BEF00
//Protocol=NEC Address=0xEF00 Command=0xB Raw-Data=0xF40BEF00 32 bits LSB first

// liga fade
//EC13EF00
//Protocol=NEC Address=0xEF00 Command=0x13 Raw-Data=0xEC13EF00 32 bits LSB first

void ligaLamp() {
  irSender.sendNEC(0xEF00, 0x3, 2);
  Serial.println("ligou");
  delay(1000);
}

void desligaLamp() {
  irSender.sendNEC(0xEF00, 0x2, 2);
  Serial.println("desligou");
  delay(1000);
}

void ligaLedVerde() {
  irSender.sendNEC(0xEF00, 0x5, 2);
  Serial.println("led verde");
  delay(1000);
}

void ligaLedVermelho() {
  irSender.sendNEC(0xEF00, 0x4, 2);
  Serial.println("led vermelho");
  delay(1000);
}

void ligaLedAzul() {
  irSender.sendNEC(0xEF00, 0x6, 2);
  Serial.println("led azul");
  delay(1000);
}

void ligaLedBranco() {
  irSender.sendNEC(0xEF00, 0x7, 2);
  Serial.println("led branco");
  delay(1000);
}

void ligaBrilho() {
  irSender.sendNEC(0xEF00, 0x0, 2);
  Serial.println("aumentou brilho");
  delay(1000);
}

void desligaBrilho() {
  irSender.sendNEC(0xEF00, 0x1, 2);
  Serial.println("diminuiu brilho");
  delay(1000);
}

void ligaFlash() {
  irSender.sendNEC(0xEF00, 0xB, 2);
  Serial.println("ligou flash");
  delay(1000);
}

void ligaFade() {
  irSender.sendNEC(0xEF00, 0x13, 2);
  Serial.println("ligou fade");
  delay(1000);
}

void handleRoot() {
  server.send(200, "text/html", "Hello from ESP8266!");
}

void handleLigaLamp() {
  ligaLamp();
  server.send(200, "text/plain", "Lâmpada ligada");
}

void handleDesligaLamp() {
  desligaLamp();
  server.send(200, "text/plain", "Lâmpada desligada");
}

void handleLigaVermelho() {
  ligaLedVermelho();
  server.send(200, "text/plain", "Lâmpada vermelha ligada");
}

void handleLigaAzul() {
  ligaLedAzul();
  server.send(200, "text/plain", "Lâmpada azul ligada");
}

void handleLigaBranco() {
  ligaLedBranco();
  server.send(200, "text/plain", "Lâmpada branca ligada");
}

void handleLigaVerde() {
  ligaLedVerde();
  server.send(200, "text/plain", "Lâmpada verde ligada");
}

void handleLigaBrilho() {
  ligaBrilho();
  server.send(200, "text/plain", "Brilho aumentado");
}

void handleDesligaBrilho() {
  desligaBrilho();
  server.send(200, "text/plain", "Brilho diminuido");
}

void handleLigaFlash() {
  ligaFlash();
  server.send(200, "text/plain", "Flash ligado");
}

void handleLigaFade() {
  ligaFade();
  server.send(200, "text/plain", "Fade ligado");
}

void setup() {
  recv.enableIRIn();
  Serial.begin(9600);
  irSender.begin(5); //D1
  irSender.enableIROut(38);

  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 


  server.on("/", HTTP_GET, handleRoot);
  server.on("/liga-lamp", HTTP_POST, handleLigaLamp);
  server.on("/desliga-lamp", HTTP_POST, handleDesligaLamp);
  server.on("/liga-azul", HTTP_POST, handleLigaAzul);
  server.on("/liga-vermelho", HTTP_POST, handleLigaVermelho);
  server.on("/liga-branco", HTTP_POST, handleLigaBranco);
  server.on("/liga-verde", HTTP_POST, handleLigaVerde);
  server.on("/liga-brilho", HTTP_POST, handleLigaBrilho);
  server.on("/desliga-brilho", HTTP_POST, handleDesligaBrilho);
  server.on("/liga-flash", HTTP_POST, handleLigaFlash);
  server.on("/liga-fade", HTTP_POST, handleLigaFade);

  server.begin(); 
}

void loop() {
  if (recv.decode()) {
    Serial.println(recv.decodedIRData.decodedRawData, HEX);
    recv.printIRResultShort(&Serial);
    delay(1000);
    recv.resume();
  }

  server.handleClient();

}
