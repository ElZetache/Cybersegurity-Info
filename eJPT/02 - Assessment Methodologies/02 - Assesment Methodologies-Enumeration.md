# Assessment Methodologies: Enumeration
# Indice


---

# Introduccion

En este temario hablaremos de servidores y servicios.

Cubriremos algunos como:
- SMB
- FTP
- SSH
- HTTP
- SQL

Objetivos del curso:
- Aprenderemos el objetivo de hacer la enumeracion de los servicios.
- Aprenderemos a identificar los servicios mas comunes y los protocolos.
- Entenderemos el proceso para enumerar protocolos y servicios desconocidos.

---
---

# Servidores y servicios

Un servidor es una maquina encargada de ofrecer uno o mas servicios.
- Servidor Mail
- AD
- ...

Puedo correr cualquier sistema operativo que se haya configurado para ofrecer un servicio.

Los servidores por su naturaleza deben de ser accesibles publicamente para poder ofrecer sus servicios.
Y estos requieren tener ciertos puertos abiertos para que se pueda acceder a lo que ofrecen.

Si lo anterior no esta configurado un atacante podría usar diversas tecnicar para acceder al servidor y tomar el control.

---

# SMB
## SMB: Windows Discover And Mount

SMB es un servicio de Windows que implementa la comparticion de archivos, un termino generico para referirse a este tipos de servicios es CIFS (Common Internet File System).

**Estos servicios suelen funcionar en el puerto 445/TCP.**

Podemos ejecutar un Nmap para descubrir estos servicios y probar de conectarnos.

Comando windows para conectar:

`net use Z: \\"IP"\"RUTA" smbserver /USER:administrator`

## SMB: Nmap Scripts

Nmap viene con muchos scripts que nos pueden ser utiles a la hora de obtener informacion, por ejemplo `script=discovery`, por lo que vamos a tratar algunos de ellos.


- **smb-protocols**: Es un script que nos ayuda a obtener informacion extra cuando estamos apuntando nuestro Nmap a un puerto con un servicio SMB.
`nmap -p445 --script smb-protocols 10.4.31.90`
---
- **smb-security-mode**: Para obtener informacion del metodo de seguridad que esta usando un servidor samba que hemos detectado en un puerto. 
---
- **smb-enum-sessions**: Para enumerar las sesiones o conexiones al servidor SMB.
`nmap -p445 --script smb-enum-sessions 10.4.31.90`

    - Con algunos Scrips podemos añadir argumentos: 

    `nmap -p445 --script smb-enum-sessions --script-args smbusername=administrator,smbpassword=smbserver_771 10.4.31.90`
---
- **smb-enum-shares**: Script util para obtener una lista de los recursos compartidos por el servidor.
    - Si le añadimos argumentos nos devolverá a que recursos tenemos acceso con la cuenta logueada: 
    
    `nmap -p445 --script smb-enum-shares --script-args smbusername=administrator,smbpassword=smbserver_771 10.4.31.90`

    - si corremos este script junto a **smb-ls** nos listara los ficheros de las rutas compartidas:
    ```nmap -p445 --script smb-enum-shares,smb-ls --script-args smbusername=administrator,smbpassword=smbserver_771 10.4.31.90```
---
- **smb-enum-users**: Nos dará una lista de los usuarios, es probable tener que poner argumentos de user para que nos devuelva toda la informacion.
---
- **smb-server-stats**: Devuelve algo de informacion del servidor.
---
- **smb-enum-domains**: Nos devuelve un poco de informacion general de los dominios del servidor.
---
- **smb-enum-groups**: Podemos ver los grupos de usuarios del dominio del servidor SMB.
---
- **smb-enum-services**: Podemos ver los servicios que estan corriendo en el servidor.
---

## SMB: SMBMap

Es un programa hecho en Python que devuelve un poco de informacion del servicion SMB.

Ejemplo de uso:

`smbmap -u "usuario" -p "password" -d . -H "IP"`

`smbmap -u guest -p "" -d . -H 10.4.26.58`

![smbmap](img/smbmap-1.png)

Con esta herramienta en caso de haber optenido un usuario con permisos podemos llegar a ejecutar comandos en remoto:


`smbmap -H 10.4.26.58 -u administrator -p smbserver_771 -x 'ipconfig'`

Esto nos devolvería el resultado de ejecutar un 'ipconfig' en el windows que estamos auditando:

![smbmap](img/smbmap-2.png)

Esta herramienta tambien nos permite ver el contenido de un recurso compartido con el atributo "-r"

`smbmap -H 10.4.26.58 -u Administrator -p 'smbserver_771' -r 'C$'`

![smbmap](img/smbmap-3.png)

Incluso podemos utilizar el smbmap para subir ficheros que tenemos en local al servidor de destino con el siguiente comando:

`smbmap -H 10.4.26.58 -u Administrator -p 'smbserber_771' --upload '/root/backdoor' 'C$/backdoor`

![smbmap](img/smbmap-4.png)

Tambien podemos descargar ficheros con los siguientes atributos:

`smbmap -H 10.4.26.58 -u Administrator -p 'smbserber_771' --download 'C$/flag.txt`

## SMB: Algunas herramientas extra

- Otras herramientas que podemos usar:
    - msfconsole: Metasploit framework
        - para acceder a las herramientas para obtener informacion de SMB podemos ejecutar los siguientes comandos:
            - `use auxiliary/scanner/smb/` Si damos tabular veremos las herramientas disponibles.
            - Para saber que informacion requiere usaremos el comando `show options`
            ![metasploit](img/metasploit-1.png)
            - para asignar uno de los valores requiridos usaremos `set`
            ![metasploit](img/metasploit-2.png)
            - para lanzar usaremos `run`
            ![metasploit](img/metasploit-3.png)

    - smbclient
    - rpcclient
        - Si tenemos acceso con una sesion null podemos obtener algo de informacion extra con `rpcclient`:
            - `rpcclient -U "" -N 192.76.242.3`
            - `srvinfo`
            ![srvinfo](img/rpcclient-1.png)
    - enum4linux
        - `enum4linux -o "ip"` --> devuelve bastante informacion util del SMB.



