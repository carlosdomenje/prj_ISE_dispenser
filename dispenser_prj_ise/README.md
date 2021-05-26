Autor: Domenje Carlos R. - 2021

# Sistema inteligente de ingreso de personas con medición de temperatura y expendio de alcohol en gel.

Proyecto Final Introducción a Sistemas Embebidos


## Introducción 🚀

Este proyecto tiene como finalidad la evaluación de lo aprendido en la cátedra Introducción a los Sistemas Embebidos correspondiente a la especialización en internet de las cosas de la FIUBA. 



Mira **Implementación** para conocer como implementar el proyecto.


### Requisitos 📋

El proyecto final de aprobación de la materia consiste en una presentación de un proyecto de desarrollo propio basado en una aplicación real que respete los siguientes lineamientos:

* Debe emplearse la placa NUCLEO

* Puede ser una aplicación diferente (no necesariamente domótica)

* Puede utilizar los sensores vistos o agregar los nuevos

* Debe usar al menos una entrada analógica

* Debe usar comunicación serie 

* Realizar la temporización del sistema basada en interrupciones y uso de timers

Para ver una explicación detallada de cada uno de los puntos propuestos, abra el informe adjunto. 

* [Informe del TP](./informe.pdf)


### Entregables del proyecto: 🛠️

* Diagrama en bloques -> (ver: [Diagrama en bloques](./bloques.png))
* Conexionado hardware -> (ver: [Conexionado](./tp-diagrama.png))
* Modelado del software (o de alguna parte del mismo) (Diagrama de flujo o máquinas de estado u otro).
    -> (ver: [Diagrama](./diagramaFlujo.pdf))
* Repositorio con el código (😎)
* Video del funcionamiento -> (https://youtu.be/xVcdWI9hyU0)


## Implementación 📦

Para realizar la Implementación deberá tener los siguientes elementos:

* 1 - Placa NUCLEO H743ZI2
* 1 - display OLED 128x64
* 1 - sensor de temperatura MLX90614
* 1 - ESP32
* 1 - Potenciometro de 10 KOhm
* 2 - Sensores de ultrasonido HC-SR04
* 2 - Relays
* 1 - Fuente de alimentación de 3.3V y 5V

Mbed Studio para poder realizar el debug de la aplicación
[Mbed Studio](https://os.mbed.com/studio/) 

Opcional: 
[Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) es necesario si quiere realizar por linea de comandos el clone del repositorio.

Descargar o clonar el repositorio del proyecto.
```
git clone https://github.com/carlosdomenje/prj_ISE_dispenser.git

```

## Captura de la Implementación 📳️

![implementacion](./implementacion.png)


## Contribuir 🖇️

Puede contribuir realizando un pull request con las sugerencias al proyecto.

## Wiki 📖

Puedes encontrar mas informacion en el campus de la cátedra
[Campus](https://campus.fi.uba.ar/course/view.php?id=3312)

## Versionado 📌

Se utiliza [Git](https://git-scm.com/) para el versionado. Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/carlosdomenje/prj_ISE_dispenser.git).


## Licencia 📄

Este proyecto está bajo la Licencia GPL.

## Gratitud 🎁

* Con este proyecto pude interactuar entre varios sensores y realizar una implementación aplicable al desarrollo de un producto comercial.📢
* Agradezco a todos los profesores de la catedra Introduccion a los Sistemas Embebidos de FIUBA🤓.


---
