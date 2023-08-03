# ALL_IECI

este proyecto es la base de mi proyecto de titulo, este busca brindar una herramienta
que de acceso a la informacion de cada asignatura de la malla de Ingenieria de Ejecucion
en Computacion e Informatica de la Universidad del Bío Bío

## Comenzando 🚀

_Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu
máquina local para propósitos de desarrollo y pruebas._

## Pre-requisitos 📋

### Puntos clave

dentro del codigo de este proyecto se encuentran 2 puntos clave, el primero es que en el archivo "ver_asignatura.cpp"
en la linea de codigo 38, se encuentra la direccion ip del servidor, por lo que si se desea utilizar este proyecto debe colocar la 
ip de su servidor con el respectivo puerto,

```
        std::string ftpurl = "ftp://[ip del servidor]:[puerto ftp default 21 ]/" +semftp + "/" +asigftp +"/";
```
#### ejemplo
```
        std::string ftpurl = "ftp://192.168.1.117:21/" +semftp + "/" +asigftp +"/";
```

el segundo punto clave es que en el archivo "connect_server.cpp" en las lineas de codigo 88-89, 
se encuentran las credenciales del servidor, por lo que si se desea utilizar este proyecto debe colocar 
las credenciales de su respectivo servidor

```
        curl_easy_setopt(curl, CURLOPT_USERNAME, "[usuario]");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "[contraseña]");
```
#### ejemplo
```
        curl_easy_setopt(curl, CURLOPT_USERNAME, "benjamin");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "1234");
```


### Que cosas necesitas para instalar el software y como instalarlas

primero que nada, este proyecto esta desarrollado en c++, por lo que se 
recomienda tener un IDE que soporte este lenguaje, en mi caso yo utilizo CLion, 
pero puedes utilizar el que mas te acomode.

Este proyecto consta de dos partes, la primera es el servidor, que se encarga de la gestion de los archivos mediante un servidor ftp (ProFTPD) y el cliente que es la cara visible al usuario

### Instalación 🔧
primero que nada en el servidor debes instalar el servidor ftp, en este caso se uso ProFTPD,
para instalarlo en ubuntu server, el proyecto consta con un script que hara toda la instalacion y configuracion por ti, para ello debes ejecutar el siguiente comando
```
sudo apt-get install git
```
luego
```
git clone htpps://github.com/bamm99/ALL_IECI.git
```
una vez clonado el repositorio, debes ingresar a la carpeta del proyecto
```
cd /ALL_IECI
```
una vez dentro debe dar los permisos al script para que este pueda hacer la instalacion
```
chmod +x configurar_servidor.sh
```
y ahora ya puede ejecutar el script
``` 
sudo ./configurar_servidor.sh
```
este script se encargara de instalar y configurar el servidor ftp, ademas de instalar el 
cliente ssh, que es el que se encargara de la conexion entre el servidor y el cliente

Para compilar el proyecto en tu maquina local, debes instalar G++, para ello debes
ejecutar el siguiente comando
``` 
sudo apt-get install g++
```
una vez instalado, debes ingresar a la carpeta del proyecto
```
cd /ALL_IECI
```
una vez dentro debes ejecutar el siguiente comando
```
g++ -o ALL_IECI main.cpp ver_asignaturas.cpp connect_server.cpp ver_todas_asignaturas.cpp verCursoLinux.cpp -lcurl -std=c++11
```
y para iniciar la app debes ejecutar el siguiente comando
```
./ALL_IECI
```

una vez dentro de la app, te aparecera un menu con las opciones disponibles, como el que aparece a continuacion
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
para ejecutar pruebas en el servidor si todo esta funcionando bien, puedes usar el siguiente comando
```
service proftpd status
```
si el servidor esta funcionando bien, deberia aparecer algo como esto
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
tambien estan disponilbes los siguientes comandos para trabajar en el servidor, 
El primero es para inciar el servidor en caso de que este no este corriendo, 
el segundo es para detener el servidor y el tercero es para reiniciar el servidor
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

