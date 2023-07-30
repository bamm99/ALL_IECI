#include <iostream>
#include <libssh/libssh.h>

int main() {
    // Conexión al servidor SFTP
    ssh_session sshSession = ssh_new();
    if (sshSession == nullptr) {
        std::cerr << "Error al crear la sesión SSH." << std::endl;
        return 1;
    }

    std::string serverIpAddress = "172.20.0.2";
    std::string username = "benja";
    int port = 2222; // Puerto SFTP predeterminado es 22

    ssh_options_set(sshSession, SSH_OPTIONS_HOST, serverIpAddress.c_str());
    ssh_options_set(sshSession, SSH_OPTIONS_USER, username.c_str());
    ssh_options_set(sshSession, SSH_OPTIONS_PORT, &port);

    int rc = ssh_connect(sshSession);
    if (rc != SSH_OK) {
        std::cerr << "Error al conectar al servidor: " << ssh_get_error(sshSession) << std::endl;
        ssh_free(sshSession);
        return 1;
    }

    // Autenticación con contraseña (opcional)
    std::string password = "5426";
    rc = ssh_userauth_password(sshSession, nullptr, password.c_str());
    if (rc != SSH_AUTH_SUCCESS) {
        std::cerr << "Error de autenticación: " << ssh_get_error(sshSession) << std::endl;
        ssh_disconnect(sshSession);
        ssh_free(sshSession);
        return 1;
    }

    // Abrir una sesión SFTP
    sftp_session sftpSession = sftp_new(sshSession);
    if (sftpSession == nullptr) {
        std::cerr << "Error al crear la sesión SFTP: " << ssh_get_error(sshSession) << std::endl;
        ssh_disconnect(sshSession);
        ssh_free(sshSession);
        return 1;
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK) {
        std::cerr << "Error al inicializar la sesión SFTP: " << ssh_get_error(sshSession) << std::endl;
        sftp_free(sftpSession);
        ssh_disconnect(sshSession);
        ssh_free(sshSession);
        return 1;
    }

    // Ruta de la carpeta a listar
    std::string remoteFolderPath = "/ftp";

    // Obtener la lista de archivos de la carpeta remota
    sftp_dir dir = sftp_opendir(sftpSession, remoteFolderPath.c_str());
    if (dir == nullptr) {
        std::cerr << "Error al abrir la carpeta remota: " << ssh_get_error(sshSession) << std::endl;
        sftp_free(sftpSession);
        ssh_disconnect(sshSession);
        ssh_free(sshSession);
        return 1;
    }

    // Recorrer y mostrar los nombres de los archivos en la carpeta remota
    struct sftp_attributes attributes;
    while ((attributes = sftp_readdir(sftpSession, dir)) != nullptr) {
        std::cout << attributes->name << std::endl;
        sftp_attributes_free(attributes);
    }

    // Cerrar la carpeta y liberar recursos
    sftp_closedir(dir);
    sftp_free(sftpSession);
    ssh_disconnect(sshSession);
    ssh_free(sshSession);

    return 0;
}
