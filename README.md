# ALL_IECI

Este proyecto es la base de mi proyecto de título, este busca brindar una herramienta
que de acceso a la información de cada asignatura de la malla de Ingeniería de Ejecución
en Computacion e Informatica de la Universidad del Bío-Bío.

## Comenzando 🚀

_Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu
máquina local para propósitos de desarrollo y pruebas._

## Entorno de desarrollo y pruebas📋

Este proyecto fue diseñado en un entorno de desarrollo específico, por lo que se recomienda
utilizar el mismo entorno para evitar problemas de compatibilidad.

entorno utilizado:
* virtualbox 7.0.10
  * ubuntu server 20.04
  * ubuntu desktop 22.04.2 LTS
* CLion 2023.2
* G++ 11.4.0
* Curl 7.68.0
* OpenSSH 8.2p1
* ProFTPD 1.3.6c

Para montar un entorno de desarrollo como el que se utilizó en este proyecto, se deben hacer 
reglas de redireccionamiento de puertos en virtualbox, para ello debes seguir los siguientes pasos:

1.- Primero debes crear las maquinas virtuales en virtualbox, en este caso se utilizo ubuntu server 20.04 
y ubuntu desktop 22.04.2 LTS.

2.- Una vez creadas las máquinas virtuales, debes ir a la configuracion de cada una de ellas y en la seccion de red, 
debe estar seleccionada la opcion de red NAT para ambas máquinas.

3.- En opciones avanzadas de la seccion de red, en la opccion "reenvío de puertos" debes agregar una regla de redireccionamiento
de puertos, en este caso se crearon reglas para los puertos: 

* 21 (puerto ftp)
* 22 (puerto ssh)
* 50000-50009 (rango de puertos pasivos para ftp)

La regla debería quedar más o menos asi:

```
Nombre: ftp
Protocolo: TCP
IP anfitrion: [la ip de tu computadora]
Puerto anfitrion: 21
IP invitado: [la ip de tu maquina virtual]
Puerto invitado: 21
```

## Puntos claves para la conexion cliente-servidor 🔧

Para poder conectar el servidor con el cliente, se utilizó el protocolo SSH, por lo que
se recomienda tener conocimientos basicos de este protocolo, además de tener conocimientos
basicos de FTP, ya que el servidor ftp se encarga de la gestion de los archivos.

En este caso la conexion requiere 4 cosas importantes para poder compilar el cliente:

* IP del servidor
* Puerto del servidor
* Usuario del servidor
* Contraseña del servidor

Estos datos se deben ingresar en el archivo config.cpp, en las siguientes líneas de codigo:
```
#include "string"

namespace config {
    
    std::string ftp_IP = "[AQUI VA LA IP DEL SERVIDOR]";
    
    std::string ftp_port = "[AQUI VA EL PUERTO]";
    
    std::string ftp_user = "[AQUI VA EL USUARIO]";
    
    std::string ftp_pass = "[AQUI VA LA CONTRASEÑA]";
}
```


## Instalación 🔧
### Servidor

Primero que nada en el servidor debes instalar el servidor ftp, en este caso se uso ProFTPD,
para instalarlo en ubuntu server, el proyecto consta con un script que hara toda la instalacion
y configuracion por ti, para ello debes ejecutar el siguiente comando:
```
sudo apt-get install git
```

Con esto nos aseguramos que tu servidor tenga git para trabajar, luego clonamos este repositorio con el comando:

```
git clone htpps://github.com/bamm99/ALL_IECI.git
```

Una vez clonado el repositorio, debes entrar al directorio del proyecto.

```
cd /ALL_IECI
```

Una vez dentro, debes dar los permisos al script para que este pueda hacer la instalacion y configuracion.

```
chmod +x configurar_servidor.sh
```

Y ahora ya puede ejecutar el script.

``` 
sudo ./configurar_servidor.sh
```

Este script se encargará de instalar y configurar el servidor ftp, además de instalar el 
cliente ssh, que es el que se encargara de la conexion entre el servidor y el cliente, también
se encarga de copiar los archivos de configuracion a su respectivo directorio, y por último ejecuta otro script
el cual hace un pequeño poblado de archivos para poder hacer pruebas con el cliente.

Una vez terminada la ejecución de los scripts, debes reiniciar el servidor para que los 
cambios surtan efecto, para ello debes ejecutar el siguiente comando:

```
service proftpd restart
```

### Cliente
Para compilar el proyecto en tu maquina (en el entorno de desarrollo corresponde a 
la maquina de ubuntu desktop 22.04.2 lts), debes instalar G++, para ello debes
ejecutar el siguiente comando:

``` 
sudo apt-get install g++
```

Una vez instalado, debes ingresar a la carpeta del proyecto.

```
cd /ALL_IECI
```
Una vez dentro debes ejecutar el siguiente comando.
```
g++ -o ALL_IECI main.cpp config.cpp ver_asignaturas.cpp connect_server.cpp verCursoLinux.cpp ver_todas_asignaturas.cpp -lcurl -std=c++17
```
Y para iniciar la app debes ejecutar el siguiente comando.
```
./ALL_IECI
```

Una vez dentro de la app, te aparecera un menu con las opciones disponibles, como el que aparece a continuacion:
```
----------------------------------------
Bienvenido a ALL_IECI
Software creado por Benjamin Mosso
Estudiante de Ingenieria de Ejecucion en computacion e informatica
Universidad Del Bio-Bio
----------------------------------------
               Menu
1. Ver asignatura de un semestre
2. Ver todas las asignaturas
3. Ver curso de autoaprendizaje Linux
0. Salir
----------------------------------------
Ingrese una opcion: 
```

## Ejecutando las pruebas ⚙️
Para ejecutar pruebas en el servidor si todo está funcionando bien, puedes usar el siguiente comando:
```
service proftpd status
```
Si el servidor está funcionando bien, debería aparecer algo como esto:
```
● proftpd.service - LSB: Starts ProFTPD daemon
     Loaded: loaded (/etc/init.d/proftpd; generated)
     Active: active (running) since Thu 2023-08-03 13:27:28 UTC; 52min ago
       Docs: man:systemd-sysv-generator(8)
    Process: 684 ExecStart=/etc/init.d/proftpd start (code=exited, status=0/SUC>
      Tasks: 1 (limit: 2257)
     Memory: 10.0M
     CGroup: /system.slice/proftpd.service
             └─777 proftpd: (accepting connections)

Aug 03 13:27:27 proftpd systemd[1]: Starting LSB: Starts ProFTPD daemon...
Aug 03 13:27:27 proftpd proftpd[684]:  * Starting ftp server proftpd
Aug 03 13:27:28 proftpd proftpd[753]: 2023-08-03 13:27:28,077 proftpd proftpd[7>
Aug 03 13:27:28 proftpd proftpd[684]:    ...done.
Aug 03 13:27:28 proftpd systemd[1]: Started LSB: Starts ProFTPD daemon.
```
También están disponibles los siguientes comandos para trabajar en el servidor, 
El primero es para inciar el servidor en caso de que este no este corriendo, 
el segundo es para detener el servidor y el tercero es para reiniciar el servidor.
```
service proftpd start
service proftpd stop
service proftpd restart
```

## Construido con 🛠️

* [CLion](https://www.jetbrains.com/es-es/clion/) - El IDE usado
  * [C++](https://www.cplusplus.com/) - Lenguaje de programacion
  * [Curl](https://curl.se/) - Libreria Curl
* [Ubuntu Server](https://ubuntu.com/download/server) - Sistema operativo
  * [SSH](https://www.ssh.com/ssh/) - Cliente SSH
  * [ProFTPD](http://www.proftpd.org/) - Servidor FTP
* [Git](https://git-scm.com/) - Control de versiones
* [GitHub](github.com/bamm99/ALL_IECI) - Repositorio

