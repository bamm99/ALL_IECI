#!/bin/bash

##########################################################
# Script para configurar un servidor Linux              #
# Pasos para ejecutar el script:                        #
# 1. Abre la terminal.                                  #
# 2. Ve al directorio donde se encuentra este script.  #
# 3. Ejecuta el siguiente comando:                     #
#       sudo chmod +x configurar_servidor.sh           #
# 4. Ejecuta el script con:                            #
#       sudo ./configurar_servidor.sh                  #
##########################################################

# Actualizar la lista de paquetes disponibles y actualizar el sistema
apt-get update -y
apt-get upgrade -y

# Instalar git, proftpd y openssh-server sin interacción del usuario
apt-get install -y git proftpd openssh-server

# Limpiar la caché de paquetes descargados
apt-get clean

# Eliminar el archivo de configuración antiguo de proftpd si existe
rm -f /etc/proftpd/proftpd.conf

# Cambiar al directorio /home
cd /home

# Clonar el repositorio de GitHub si no existe
if [ ! -d "ALL_IECI" ]; then
  git clone https://github.com/bamm99/ALL_IECI.git
fi

# Cambiar al directorio ALL_IECI
cd ALL_IECI

# Copiar el archivo de configuración de proftpd al lugar correcto
cp proftpd.conf /etc/proftpd/proftpd.conf

# Cambiar los permisos del archivo de configuración de proftpd
chmod 644 /etc/proftpd/proftpd.conf
