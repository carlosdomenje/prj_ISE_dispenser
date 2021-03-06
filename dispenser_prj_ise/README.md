Autor: Domenje Carlos R. - 2021

# Sistema inteligente de ingreso de personas con medici贸n de temperatura y expendio de alcohol en gel.

Proyecto Final Introducci贸n a Sistemas Embebidos


## Introducci贸n 馃殌

Este proyecto tiene como finalidad la evaluaci贸n de lo aprendido en la c谩tedra Introducci贸n a los Sistemas Embebidos correspondiente a la especializaci贸n en internet de las cosas de la FIUBA. 



Mira **Implementaci贸n** para conocer como implementar el proyecto.


### Requisitos 馃搵

El proyecto final de aprobaci贸n de la materia consiste en una presentaci贸n de un proyecto de desarrollo propio basado en una aplicaci贸n real que respete los siguientes lineamientos:

* Debe emplearse la placa NUCLEO

* Puede ser una aplicaci贸n diferente (no necesariamente dom贸tica)

* Puede utilizar los sensores vistos o agregar los nuevos

* Debe usar al menos una entrada anal贸gica

* Debe usar comunicaci贸n serie 

* Realizar la temporizaci贸n del sistema basada en interrupciones y uso de timers

Para ver una explicaci贸n detallada de cada uno de los puntos propuestos, abra el informe adjunto. 

* [Informe del TP](./informe.pdf)


### Entregables del proyecto: 馃洜锔?

* Diagrama en bloques -> (ver: [Diagrama en bloques](./bloques.png))
* Conexionado hardware -> (ver: [Conexionado](./tp-diagrama.png))
* Modelado del software (o de alguna parte del mismo) (Diagrama de flujo o m谩quinas de estado u otro).
    -> (ver: [Diagrama](./diagramaFlujo.pdf))
* Repositorio con el c贸digo (馃槑)
* Video del funcionamiento -> (https://youtu.be/xVcdWI9hyU0)


## Implementaci贸n 馃摝

Para realizar la Implementaci贸n deber谩 tener los siguientes elementos:

* 1 - Placa NUCLEO H743ZI2
* 1 - display OLED 128x64
* 1 - sensor de temperatura MLX90614
* 1 - ESP32
* 1 - Potenciometro de 10 KOhm
* 2 - Sensores de ultrasonido HC-SR04
* 2 - Relays
* 1 - Fuente de alimentaci贸n de 3.3V y 5V

Mbed Studio para poder realizar el debug de la aplicaci贸n
[Mbed Studio](https://os.mbed.com/studio/) 

Opcional: 
[Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) es necesario si quiere realizar por linea de comandos el clone del repositorio.

Descargar o clonar el repositorio del proyecto.
```
git clone https://github.com/carlosdomenje/prj_ISE_dispenser.git

```

## Captura de la Implementaci贸n 馃摮锔?

![implementacion](./implementacion.png)


## Contribuir 馃枃锔?

Puede contribuir realizando un pull request con las sugerencias al proyecto.

## Wiki 馃摉

Puedes encontrar mas informacion en el campus de la c谩tedra
[Campus](https://campus.fi.uba.ar/course/view.php?id=3312)

## Versionado 馃搶

Se utiliza [Git](https://git-scm.com/) para el versionado. Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/carlosdomenje/prj_ISE_dispenser.git).


## Licencia 馃搫

Este proyecto est谩 bajo la Licencia GPL.

## Gratitud 馃巵

* Con este proyecto pude interactuar entre varios sensores y realizar una implementaci贸n aplicable al desarrollo de un producto comercial.馃摙
* Agradezco a todos los profesores de la catedra Introduccion a los Sistemas Embebidos de FIUBA馃.


---
