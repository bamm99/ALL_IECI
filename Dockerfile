

# Imagen base
FROM ubuntu:20.04
LABEL authors="benja"
# Actualizar el sistema e instalar paquetes necesarios
#(servidor ftp, git, servidor ssh, compilador de c++ para pruebas, tzdata para configurar la zona horaria
RUN ln -fs /usr/share/zoneinfo/America/Santiago /etc/localtime
RUN apt-get update && apt-get install -y \
    proftpd \
    git \
    openssh-server \
    tzdata \
    build-essential \
    apt-utils && \
    apt-get clean

# Configuración no interactiva para tzdata
ENV DEBCONF_NONINTERACTIVE_SEEN=true \
    DEBIAN_FRONTEND=noninteractive


# Copiar la configuración de ProFTPD
RUN cd /home && \
    git clone https://github.com/bamm99/ALL_IECI.git

RUN cd /home/ALL_IECI &&\
    cp proftpd.conf /etc/proftpd/proftpd.conf


# Configuración de SSH
RUN mkdir /var/run/sshd
RUN echo 'root:5426' | chpasswd
RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config

# Puerto SSH
ENV SSH_USERNAME=benja
ENV SSH_PASSWORD=5426
EXPOSE 2121
EXPOSE 2222
EXPOSE 50000-50009

# Comando para iniciar ProFTPD y SSH
CMD service proftpd start && /usr/sbin/sshd -D