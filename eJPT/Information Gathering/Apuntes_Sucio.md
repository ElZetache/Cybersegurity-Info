# Indice

- [Information Gathering](#Information-Gathering)
    * [Website Recon & Footprinting](#Website-Recon-And-Footprinting)
    * [Whois Enumeration](#Whois-Enumeration)
    * [Netcraft](#Netcraft)
    * [DNS Recon](#DNS-Recon)
    * [WAF (web aplication firewall) Detection With wafw00f](#WAF-Detection-With-wafw00f)


# Information Gathering
- Alexis ahmed -- aahmed@ine.com twitter --> HackerSploit
----------------------------------------------------------

- Passive information gathering - Obtencion de la informacion publica accesible desde la red (google, redes...)
- Active information gathering - Informacion que obtenemos accediendo a los sistemas del objetivo

## Prerequisites

- Basic linux --> usaremos Kali Linux para este curso
- Basci web technologies

## Introduction

Information Gathering es la primera fase de un test de penetracion, aqui recopilamos informacion de los sitemas a los cuales vamos a hacer el pentesting.
Este conocimiento nos ayudará en las siguientes fases y cuanto mas sepamos de nuestro objetivo mas facil nos será acceder.

Esta fase se divide en dos:
- Passive information gathering --> En esta fase usamos la informacion accesible de forma "publica" para obtener informacion de nuestro objetivo.
- Active information gathering --> En esta fase es cuando utilizaremos tecnicas activas para obtener informacion de nuestro objetivo, por ejemplo si obtubimos la IP en la fase pasiva aqui podriamos usar un nmap para ver los puertos abiertos en esta IP. Para realizar esta fase necessitamos permisos de la compañia objetivo.

### Ejemplos de informacion que podemos obtener de una web en cada una de las fases:
- Passive:
    - ip adress & informacion DNS
    - nombre de dominio y propietario
    - cuentas de correo y perfiles de redes sociales
    - technologias usadas
    - informacion de subdominios
- Activa:
    - Puertos abiertos en los sistemas
    - Informacion de la estructura interna 
    - Enumerar informacion de los sistemas objetivos
--------------

## Website Recon And Footprinting

En esta seccion revisaremos el proceso de obtener informacion pasiva de un sitio web.

- Que buscaremos?
    - Ip
    - Directorios ocultos de los buscadores
    - Nombres
    - Cuentas de mail
    - Numeros de telefono
    - Direcciones fisicas
    - Technologias web usadas
    - ...

---------

### Obtener la ip:

- Comando linux: 
    - ```whatis host```
    - ```host 'url'```

-----

### Directorios ocultos:

Una manera de ver los dirrectorios ocultos de los buscadores podría ser intentando ver el fichero "robots.txt" que tienen algunas web.

Por ejemplo en https://hackersploit.org/robots.txt .

Otro fichero que podemos mirar es el "sitemap_index.xml" --> https://hackersploit.org/sitemap_index.xml .

----

### Tecnologias web usadas:

Hay diversas app que nos ayudarán en esta tares, por ejemplo hay un addon para firefox llamado BuildWith que nos puede decir que se esta usando en cualquier web.

Tambien podemos usar "whatweb" que es una aplicacion incluida en la consola de Kali:

```whatweb hackersploit.org```

Con la app HTTrack podemos descargar una copia del codigo de la web para poderlo analizar.

--------

### Whois Enumeration

whois es un protocolo de internet que usaremos para obtener informacion de los servidores de un sitio web.

Comando Kali:
```whois hackersploit.org```

Tambien existe la web https://who.is que hace la misma funcion que el whois.

-------

### Netcraft

Netcraft es una utilidad que nos ayuda a complementar la informacion que conseguimos con el whois.


Con esta utilidad tambien podemos obtener informacion de los certificados SSL y TLS.

Basicamente te hace un resumen de toda la informacion que puede obtener de una URL muy bien organizada.

-----

### DNS Recon

Es un script de Python que chekea todos los registros NS, dandonos los datos registrados en un DNS de un dominion especifico, algunos de estos registros son:

- Registros de DNS:
    - MX --> mail adress
    - SOA
    - NS
    - A --> registro ipv4
    - AAAA --> registro ipv6
    - SPF
    - TXT

Este script nos viene incluido en Kali, por lo que con este SO no necessitamos instalarlo.

Ejemplo:

```dnsrecon -d hackersploit.org```
```dnsrecon -d zonetransfer.me```

Otra buena opcion para obtener informacion DNS de un dominio es la web https://dnsdumpster.com

----

### WAF-Detection-With-wafw00f
WAF(web aplication firewall)











