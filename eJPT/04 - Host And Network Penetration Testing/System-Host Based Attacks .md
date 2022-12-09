# Host & Network Penetration Testing: System/Host Based Attacks
# Indice




# Introduction To System/Host Based Attacks

Los ataques basados en Sytem/Host son ataques que tienen como objetivo un sistema o host que esta corriendo un sistema operativo especifico, como por ejemplo Windows o Linux.

Muchas veces podremos proceder a realizar estos ataques al ganar acceso a un servicio publico de una red.

Vamos a mirar algunas de las vulnerabilidades de los SO mas conocidos y a ver como explotarlas.

# Windows Vulnerabilities
## Overview of Windows Vulnerabilities

- Windows es el sistema operativo dominante a nivel mundial, esto hace que sea el objetivo principal para ataques.

- Windows en los ultimos 15 años a tenido vulnerabilidades severas como el MS08-067(Conflicker) to MS17-010(EternalBlue).

- Debido a la popularidad de Windows estas vulnerabilidades tienen codigos de exploit publicos que hace mas facil explotarlo.

---

### Versiones

Windows tiene muchas versiones, esto crea una fragmentacion en las vulnerabilidades, esto significa que vulnerabilidades que estan en Windows 7 podrían no estar en Windows 10 por ejemplo.

Independientemente de la version de Windows hay algunas cosas de la filosofia en si del SO que comparten todas las versiones:

- La base de Windows es el lenguaje de programacion C, esto lo hace vulnerable a buffer overflows, execucion de codigo arbitraría, etc. Digamos que son vulnerabilidades del propio lenguaje de programacion.

- Por defecto Windows no esta configurado para ejecutarse de forma segura, por ello requiere que se haga activamente esta configuracion al instalar de 0 el SO. 
    - Si no se configura activamente Windows tendrá vulnerabilidades.
    - Esta falta de configuracion pasiva es debido a que Windows esta pensado para que se pueda usar en el maximo de sectores posibles (hogar, empresas, arquitectos, artistas...).

- Debido a la naturaleza fragmentada de Windows muchas vulnerabilidades tardan un tiempo en ser parcheadas, por lo que hay muchos sistemas con vulnerabilidades conocidas sin parchear.
    - Esto se refiere a que por ejemplo una empresa que usa Windows 7 puede tardar en obtener un parche de seguridad para nuevas vulnerabilidades, porque es ese momento la prioridad de Windows es su version mas reciente.

- Windows de por si es vulnerable a cross-platform vulnerabilities, por ejemplo a SQL injection.

- Windows es vulnerable a ataques fisicos (robos, USB con malware...).

---

### Tipos de Vulnerabilidades de Windows

- Information disclosure: Permite a un atacante acceder a informacion confidencial.
- Buffer Overflow: Debido a un error de programacion un atacante podría escribir informacion en un buffer y sobrescribir el local, de esta manera puede escribir en memoria del sistema.
- Remote code execution.
- Privilege escalation: Permite a un atacante elevar sus privilegios despues de una primera vulneracion de un sistema.
- DDos attacks: Permite que un atacante consumir los recursos de un sistema haciendo que no funcione con normalidad.

---

## Frequently Exploited Windows Services 

El objetivo de este curso es aprender sobre los servicios que pueden ser vulnerables y que son propios de Windows sin necesidad de instalar, y que algunos de ellos pueden estar activados por defecto.

Conocer estos servicios y sus vulnerabilidades principales es algo imprescindible para un pentester.

![WindowsVulnerabilities](img/windows-vulnerabilities-1.png)

---

# Exploiting Windows Vulnerabilities
## Exploiting Microsoft IIS WebDAV 
### Microsoft IIS

Microsoft IIS es un servicio web desarrollado por Microsoft para **Windows**.

Puede alojar paginas web estaticas y dinamicas desarrolladas en **ASP.NET** y **PHP**.

Este servicio normalmente esta configurado para correr en el puerto 80 o 443 TCP.

Los archivos executables que acepta son:
- .asp
- .aspx
- .config
- .php

### WebDAV

Es un servicio web que que da una serie de extensiones **HTTP** que habilita a los usuarios para editar colaborativamente y trabajar con ficheros en servidores remotos.

Este servicio se configura encima de un servidos IIS.
















