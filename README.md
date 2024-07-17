# Analisis-de-eslabones-de-rigidez-variable-usando-Jamming
Estre repositorio forma parte de un trabajo de fin de estudios. Trata sobre el uso de jamming para variar la rigidez de eslabones y analizar las fuerzas que son capaces de soportar. 
En este proyecto se tocan varios palos. Primero el diseño 3D, donde he generado el molde para los eslabones de silicona y los acoples para unir los eslabones a un motor dynamixel. El control de los motores dynamixel se ha hecho usando la libreria del siguiente repositorio: https://github.com/TaISLab/dynamixel_ros_library.git 
Para hacer jamming uso una campana de vacio y una bomba de vacio, por tanto para conectar el eslabon a la campana de vacío he montado un circuito neumatico que entre otros componentes posee un sensor devacío y varias electrovalvulas.

Por tanto, este repositorio se podria dividir en dos partes:

Primero: La generación del eslabón y los acoples para los motores dynamixel. 

Segundo: El codigo de la ESP32. Con la ESP32 se realizan dos funciones:

        1. Lectura del sensor de vacío. 
        
        2. Control de electrovalvulas. 
