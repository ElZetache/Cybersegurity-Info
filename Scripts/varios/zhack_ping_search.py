import os

def ping_subnet(subnet):
# obtener la subred y el tamaño de la máscara
    subnet_parts = subnet.split('/')
    subnet_addr = subnet_parts[0]
    subnet_size = int(subnet_parts[1])

    # generar la máscara en binario
    mask = '1' * subnet_size + '0' * (32 - subnet_size)
    mask_parts = [mask[0:8], mask[8:16], mask[16:24], mask[24:32]]
    mask_parts = [str(int(x, 2)) for x in mask_parts]

    # aplicar la máscara a la dirección de la subred
    subnet_parts = subnet_addr.split('.')
    network_parts = []
    for i in range(4):
        network_parts.append(str(int(subnet_parts[i]) & int(mask_parts[i])))
    network_addr = '.'.join(network_parts)

    # generar la dirección de broadcast
    broadcast_parts = []
    for i in range(4):
        broadcast_parts.append(str(int(network_parts[i]) | (int(mask_parts[i]) ^ 255)))
    broadcast_addr = '.'.join(broadcast_parts)

    # iterar sobre cada dirección IP en la subred y enviar un ping
    for i in range(1, 255):
        ip = network_addr[:network_addr.rindex('.') + 1] + str(i)
        response = os.system("ping -c 1 " + ip)
        if response == 0:
            print(ip + " is active")
        else:
            print(ip + " is inactive")

ping_subnet("192.168.0.0/24")