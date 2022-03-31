

#include <SPI.h>
#include <SD.h>


//variables
File imagenes;
int seleccion;


void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.

  //Chip Select como salida
  pinMode(PA_3, OUTPUT);

   //Inicialización
  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //Se abre dentro de la ubicación principal
  imagenes = SD.open("/");

  //se abre el directorio (el de el File imagenes)
  printDirectory(imagenes, 0);

  Serial.println("done!");
  Serial.println("");
  Serial.println("Bienvenidos!");
  Serial.println("Selecciona la imagen que quieres observar");
  Serial.println("1 para avo.txt (aguacate)");
  Serial.println("2 para avengers.txt (escudo de Avengers)");
  Serial.println("3 para slytherin.txt (escudo de Slytherin)");
}


void loop() {
  // put your main code here, to run repeatedly: 
  // envia datos sólo cuando se reciben datos
  if (Serial.available() > 0) {
    // lee el byte de entrada (se guarda en una variable para poder hacer el case)
    seleccion = Serial.read();
  }
    
  leer_imagen();
  
}

//Función que nos muestra el contenido de la tarjeta SD 
void printDirectory(File dir, int numTabs) {
   while(true) {
     //Se abre archivo por archivo
     File entry =  dir.openNextFile();  //se crea otro objeto de la clase File y se abre el siguiente archivo (entra a la ubicación principal del directorio)
     if (! entry) {
       // no more files
       break;
     }
     //imprime tabulaciones
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     //imprime el nombre del archivo
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);  //ir imprimiendo los archivos
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC); //imprime tamaño del archivo
     }
     entry.close();
   }
}

//Función para leer las imagenes dependiendo del valor ingresado por el usuario
void leer_imagen(){
  // re-open the file for reading:
  switch(seleccion){
    case 49:
      imagenes = SD.open("avo.txt"); //si se ingresa 1, se abre al archivo avo.txt
      if (imagenes) {
        Serial.println("Aguacate:");
    
        // read from the file until there's nothing else in it:
        while (imagenes.available()) {
          Serial.write(imagenes.read());     //se lee el contenido del archivo 
        }
        // close the file:
        imagenes.close();
      } 
      else {
        // if the file didn't open, print an error:
        Serial.println("error opening avo.txt");
        Serial.println("Selecciona la imagen que quieres observar");
        Serial.println("1 para avo.txt (aguacate)");
        Serial.println("2 para avengers.txt (escudo de Avengers)");
        Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      }
      //Se vuelve a colocar el menú para tenerlo en loop
      Serial.println("Selecciona la imagen que quieres observar");
      Serial.println("1 para avo.txt (aguacate)");
      Serial.println("2 para avengers.txt (escudo de Avengers)");
      Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      break;

    case 50:
      imagenes = SD.open("avengers.txt");
      if (imagenes) {
        Serial.println("Escudo de Avengers:");
    
        // read from the file until there's nothing else in it:
        while (imagenes.available()) {
          Serial.write(imagenes.read());
        }
        // close the file:
        imagenes.close();
      } 
      else {
        // if the file didn't open, print an error:
        Serial.println("error opening avengers.txt");
        Serial.println("Selecciona la imagen que quieres observar");
        Serial.println("1 para avo.txt (aguacate)");
        Serial.println("2 para avengers.txt (escudo de Avengers)");
        Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      }
      Serial.println("Selecciona la imagen que quieres observar");
      Serial.println("1 para avo.txt (aguacate)");
      Serial.println("2 para avengers.txt (escudo de Avengers)");
      Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      break;

    case 51:
      imagenes = SD.open("SLYTHE~1.txt");
      if (imagenes) {
        Serial.println("Escudo de Slytherin:");
    
        // read from the file until there's nothing else in it:
        while (imagenes.available()) {
          Serial.write(imagenes.read());
        }
        // close the file:
        imagenes.close();
      } else {
        // if the file didn't open, print an error:
        Serial.println("error opening slytherin.txt");
        Serial.println("Selecciona la imagen que quieres observar");
        Serial.println("1 para avo.txt (aguacate)");
        Serial.println("2 para avengers.txt (escudo de Avengers)");
        Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      }
      Serial.println("Selecciona la imagen que quieres observar");
      Serial.println("1 para avo.txt (aguacate)");
      Serial.println("2 para avengers.txt (escudo de Avengers)");
      Serial.println("3 para slytherin.txt (escudo de Slytherin)");
      break;
    
  }
 
}
