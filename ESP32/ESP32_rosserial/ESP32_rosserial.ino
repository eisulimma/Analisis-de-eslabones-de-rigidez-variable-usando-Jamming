//Codigo para el control de las electro valculas y lectura del sensor de vacio 
//Los datos se publican usando Ros 
//De la misma forma se crea un subscriptor para que envie los datos de control de la electrovalcula
//Los codigos de control son:
//Publisher Sensor_vacio: rostopic echo sensor_vacio
//Subscriber Relé: rostopic pub /Rele std_msgs/UInt8 "data: 0" 
// Para abrir el Relé (Cerrar Valvula): Data = 0
// Para cerrar el Relé (Abrir Valvula): Data= 1

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Empty.h>

//Defino los pines de uso
const int sensor = 15;
const int rele = 4;

//Defino las variables
int volt = 0;

ros::NodeHandle  nh;

std_msgs::Float32 analog_msg;
ros::Publisher analog_pub("sensor_vacio", &analog_msg);

void messageCb (const std_msgs::UInt8& msg){
  uint8_t received_value = msg.data;
  if(received_value==0){
    digitalWrite(rele, LOW);
  }
  if(received_value==1){
    digitalWrite(rele, HIGH);
  }
    
}

ros::Subscriber<std_msgs::UInt8> sub("Rele", &messageCb);

void setup() {
  //Para asegurar que la velocidad en baudios en el código de Arduino y rosserial coinciden
  nh.getHardware()->setBaud(57600);
  pinMode(rele, OUTPUT);

  //Inicializacion del nodo y del publisher
  nh.initNode();
  nh.advertise(analog_pub);
  nh.subscribe(sub);
}

void loop() {
  // lectura del sensor
  volt = analogRead(sensor);

  //Paso de los datos a la variable del publicador
  analog_msg.data = volt;
  //publicacion de los datos
  analog_pub.publish(&analog_msg);

  //Para mantener la conexion
  nh.spinOnce();
  delay(500);
}

